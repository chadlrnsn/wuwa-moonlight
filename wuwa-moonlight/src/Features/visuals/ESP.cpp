#include "ESP.hpp"
#include <TsEffectActor_classes.hpp>
#include <TsEffectActor_parameters.hpp>

void ESP::Draw()
{
	ImGui::Checkbox("ESP", &bEnable);
	ImGui::SameLine();
	ImGui::Tooltip("Extra Sensory Perception");

	ImGui::BeginDisabled(!bEnable);
	{
		ImGui::Checkbox("Show occluded", &bOccluded);
		
		ImGui::SliderFloat("Distance", &espDistance.Current, espDistance.Min, espDistance.Max, "%.2f");
		ImGui::ColorEdit4("Occluded color", fOccludedColor);
		
		ImGui::SameLine();
		ImGui::Tooltip("Color of invisible object");

		ImGui::ColorEdit4("Color", fColor);
		ImGui::SameLine();
		ImGui::Tooltip("Color of visible object");
		
		ImGui::Checkbox("Tracers", &bTracers);
		ImGui::Checkbox("Show occluded tracers", &bOccludedTracers);
		ImGui::SliderFloat("Thickness", &TracerThickness.Current, TracerThickness.Min, TracerThickness.Max);
		ImGui::ColorEdit4("Tracer color", fTracerColor);
		ImGui::ColorEdit4("Tracer color occluded", fTracerColorOccluded);

		ImGui::NewLine();

		ImGui::Text("Search Actor Class");
		char buffer[256] = { 0 };
		std::strncpy(buffer, searchClassName.c_str(), sizeof(buffer) - 1);
		if (ImGui::InputText("##ClassSearch", buffer, sizeof(buffer)))
		{
			searchClassName = buffer;
		}
		ImGui::SameLine();
		ImGui::Tooltip("Enter actor class name (e.g., StaticMeshActor, SceneComponent)");

		ImGui::NewLine();
		ImGui::Checkbox("Debug window", &m_bDebugWindow);
	}
	ImGui::EndDisabled();
	
}

void ESP::Render()
{
	if (!bEnable) return;

	ImDrawList* drawBackList = ImGui::GetBackgroundDrawList();
	ImVec4 color = ImVec4(fOccludedColor[0], fOccludedColor[1], fOccludedColor[2], fOccludedColor[3]);

	for (const auto& Data : renderData)
	{
		if (!Data.Actor) continue;

		ImVec4 Color = Data.bIsVisible ? ImVec4(fColor[0], fColor[1], fColor[2], fColor[3]) :
			ImVec4(fOccludedColor[0], fOccludedColor[1], fOccludedColor[2], fOccludedColor[3]);

		drawBackList->AddText(ImVec2(Data.ScreenLocation.X, Data.ScreenLocation.Y), ImColor(Color), Data.DisplayText.c_str());
		drawBackList->AddText(ImVec2(Data.ScreenLocation.X, Data.ScreenLocation.Y - 10), ImColor(Color), Data.DisplayClassName.c_str());

		if (bTracers) {
			ImVec4 TracerColor = Data.bIsVisible ? ImVec4(fTracerColor[0], fTracerColor[1], fTracerColor[2], fTracerColor[3]) :
				ImVec4(fTracerColorOccluded[0], fTracerColorOccluded[1], fTracerColorOccluded[2], fTracerColorOccluded[3]);

			drawBackList->AddLine(ImGui::GetIO().DisplaySize / 2, ImVec2(Data.ScreenLocation.X, Data.ScreenLocation.Y), ImColor(TracerColor), TracerThickness.Current);
		}
	}
}

void ESP::Run() // routine
{
	if (!bEnable) {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));

		std::lock_guard<std::mutex> lock(renderMutex);
		tempRenderData.clear();
		renderData.clear();
		return;
	}

	tempRenderData.clear();
	tempRenderData.reserve(100);
	
	if (!globals::world || !globals::player_controller) return;

	auto Persisten_Level = globals::world->PersistentLevel;
	if (Persisten_Level == nullptr) return;

	auto pcharacter = globals::player_controller->Character;
	if (pcharacter == nullptr) 
	{
		if (renderData.size() > 0) {
			std::lock_guard<std::mutex> lock(renderMutex);
			renderData.clear();
		}
		return;
	};

	SDK::FVector pCharacterLocation = pcharacter->K2_GetActorLocation();
	cameraLocation = pCharacterLocation;

	for (auto actor : Persisten_Level->Actors) {
		if (!actor) continue;

		// Skip default UI components
		// if (actor->IsA(hkEngine)) continue;
		if (actor->IsChildActor() ||
			actor->IsA(SDK::UNiagaraComponent::StaticClass()) || // valid ( btw this is component of some library )
			actor->IsA(SDK::ATsEffectActor_C::StaticClass()) || // valid
			actor->IsA(SDK::AUIBaseActor::StaticClass()) || // valid
			actor->IsA(SDK::ASpotLight::StaticClass()) || // valid
			actor->IsA(SDK::AUIContainerActor::StaticClass()) || // valid MAIN UI COMPONENT!!!!
			actor->IsA(SDK::AInfo::StaticClass()) || 		// some info like world, settings etc.
			actor->IsA(SDK::AHUD::StaticClass()) || // inherits AActor component
			actor->IsA(SDK::APlayerStart::StaticClass()) ||
			actor->IsA(SDK::ALGUIManagerActor::StaticClass()) || // UI Shit
			actor->IsA(SDK::ALevelSequenceActor::StaticClass()) || // lib for animation idk
			actor->IsA(SDK::ACameraActor::StaticClass()) || // removes some camera useless classes in rendering
			actor->IsA(SDK::AParticleEventManager::StaticClass()) || // no clue wat is that :/
			actor->IsA(SDK::AAkiWorld_WP_C::StaticClass()) || // wtf is this?
			actor->IsA(SDK::AAIController::StaticClass()) || // to exclude any visible controllers
			actor->IsA(SDK::AEffectSystemActor::StaticClass())
			
		) continue;

		std::string ActorClassName = actor->Class->GetName();
		std::string DisplayName = ActorClassName.c_str();

		// Visible check
		bool bIsVisible = globals::player_controller->LineOfSightTo(actor, pCharacterLocation, false);
		if (!bIsVisible && !bOccluded) continue;

		SDK::FVector ActorLocation = actor->K2_GetActorLocation();

		float Distance = pCharacterLocation.GetDistanceTo(ActorLocation) / 100.0f;
		if (Distance > espDistance.Current) continue;

		// auto owner = actor->GetOwner();
		// if (searchClassName.npos) continue;

		// auto compToS = globals::UGAkStatics->FindClassFast(searchClassName);
		// auto meshComp = actor->Attached(compToS);

		// if (!meshComp) continue;

		// LOG_INFO(meshComp->GetFullName().c_str());
		// auto ownerName = owner->GetFullName();
		// LOG_INFO(meshComp->GetFullName().c_str());

		// if (!meshComp->GetFullName().find("Flower")) continue;


		SDK::FVector2D ScreenLocation;
		if (!globals::player_controller->ProjectWorldLocationToScreen(ActorLocation, &ScreenLocation, false)) continue;

		RenderData Data;
		Data.Actor = actor;
		Data.DisplayText = DisplayName + "[" + std::to_string(static_cast<int>(Distance)) + "m]";
		Data.DisplayClassName = actor->Class->GetFullName().c_str();
		Data.ScreenLocation = ScreenLocation;
		Data.bIsVisible = bIsVisible;
		// Data.Tags = actor->;
		tempRenderData.push_back(std::move(Data));
	}

	std::lock_guard<std::mutex> lock(renderMutex);
	renderData.swap(tempRenderData);
}

void ESP::RenderDebug()
{
	if (!m_bDebugWindow || renderData.empty()) return;

	ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Once);
	if (ImGui::Begin("ESP Debug stuff"))
	{
		ImGui::Text("Actors found: %d", (int)renderData.size());
		
		for (const auto& Data : renderData)
		{
			if (!Data.Actor) continue;
			if (renderData.size() > 100) continue;
			ImGui::Text(Data.DisplayText.c_str());
			// ImGui::SameLine();
			// if (Data.Tags.Num() > 0) {
			// 	for (const auto& tag : Data.Tags) {
			// 		SDK::FString strdata = UKismetStringLibrary::Conv_NameToString(tag);
			// 		ImGui::Text(strdata.ToString().c_str());
			// 	}
			// }
		}

		ImGui::End();
	}
}