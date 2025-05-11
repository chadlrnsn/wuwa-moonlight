#include "ESP.hpp"
#include <TsEffectActor_classes.hpp>
#include <TsEffectActor_parameters.hpp>
#include <BP_BaseItem_classes.hpp>
// #include <BP_BaseNPC_classes.hpp>

void ESP::Draw()
{
	ImGui::Checkbox("ESP", &bEnable);
	ImGui::SameLine();
	ImGui::Tooltip("Extra Sensory Perception");

	ImGui::BeginDisabled(!bEnable);
	{
		ImGui::Checkbox("Name", &bShowName);
		ImGui::Checkbox("Class Name", &bShowFullClassName);
		ImGui::SameLine();
		ImGui::Tooltip("for devs");
		
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

	if (renderData.empty()) return;

	for (const auto& Data : renderData)
	{
		if (!Data.Actor) continue;

		ImVec4 Color = Data.bIsVisible ? ImVec4(fColor[0], fColor[1], fColor[2], fColor[3]) :
			ImVec4(fOccludedColor[0], fOccludedColor[1], fOccludedColor[2], fOccludedColor[3]);


		if (bShowName)
			drawBackList->AddText(ImVec2(Data.ScreenLocation.X, Data.ScreenLocation.Y), ImColor(Color), Data.DisplayText.c_str());
		
		if (bShowFullClassName)
			drawBackList->AddText(ImVec2(Data.ScreenLocation.X, Data.ScreenLocation.Y - 15), ImColor(Color), Data.DisplayClassName.c_str());

		if (bTracers) {
			ImVec4 TracerColor = Data.bIsVisible ? ImVec4(fTracerColor[0], fTracerColor[1], fTracerColor[2], fTracerColor[3]) :
				ImVec4(fTracerColorOccluded[0], fTracerColorOccluded[1], fTracerColorOccluded[2], fTracerColorOccluded[3]);

			drawBackList->AddLine(ImGui::GetIO().DisplaySize / 2, ImVec2(Data.ScreenLocation.X, Data.ScreenLocation.Y), ImColor(TracerColor), TracerThickness.Current);
		}
	}
}

bool ValidatePtr()
{
    return globals::world && globals::player_controller && 
           globals::player_controller->PlayerCameraManager &&
           globals::player_controller->Character;
}

void ESP::Run()
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

	if (!ValidatePtr()) return;
	
	auto cameraComp = globals::player_controller->PlayerCameraManager;
	auto pcharacter = globals::player_controller->Character;

	if (!pcharacter || !cameraComp) 
	{
		if (renderData.size() > 0) {
			std::lock_guard<std::mutex> lock(renderMutex);
			renderData.clear();
		}
		return;
	}; 

	SDK::FVector pCharacterLocation = pcharacter->K2_GetActorLocation();

	for (auto actor : globals::world->PersistentLevel->Actors) {
		if (!actor) continue;

		if (
			!actor->IsA(ABP_BaseItem_C::StaticClass()) &&
			// !actor->IsA(ABP_BaseNPC_C::StaticClass()) &&
			!actor->IsA(ABP_BaseAnimal_C::StaticClass()) &&
			!actor->IsA(ATsBaseCharacter_C::StaticClass())

			// actor->IsA(SDK::UNiagaraComponent::StaticClass()) || // valid ( btw this is component of some library )
			// actor->IsA(SDK::ATsEffectActor_C::StaticClass()) || // valid
			// actor->IsA(SDK::AUIBaseActor::StaticClass()) || // valid
			// actor->IsA(SDK::ASpotLight::StaticClass()) || // valid
			// actor->IsA(SDK::AUIContainerActor::StaticClass()) || // valid MAIN UI COMPONENT!!!!
			// actor->IsA(SDK::AInfo::StaticClass()) || 		// some info like world, settings etc.
			// actor->IsA(SDK::AHUD::StaticClass()) || // inherits AActor component
			// actor->IsA(SDK::APlayerStart::StaticClass()) ||
			// actor->IsA(SDK::ALGUIManagerActor::StaticClass()) || // UI Shit
			// actor->IsA(SDK::ALevelSequenceActor::StaticClass()) || // lib for animation idk
			// actor->IsA(SDK::ACameraActor::StaticClass()) || // removes some camera useless classes in rendering
			// actor->IsA(SDK::AParticleEventManager::StaticClass()) || // no clue wat is that :/
			// actor->IsA(SDK::AAkiWorld_WP_C::StaticClass()) || // wtf is this?
			// actor->IsA(SDK::AAIController::StaticClass()) || // to exclude any visible controllers
			// actor->IsA(SDK::AEffectSystemActor::StaticClass())
			
		) continue;


		auto DisplayName = actor->BlueprintTypeName.ToString();

		// Visible check
		bool bIsVisible = globals::player_controller->LineOfSightTo(actor, cameraComp->GetCameraLocation(), false);
		if (!bIsVisible && !bOccluded) continue;

		SDK::FVector ActorLocation = actor->K2_GetActorLocation();

		float Distance = pCharacterLocation.GetDistanceTo(ActorLocation) / 100.0f;
		if (Distance > espDistance.Current) continue;

		SDK::FVector2D ScreenLocation;
		if (!globals::player_controller->ProjectWorldLocationToScreen(ActorLocation, &ScreenLocation, false)) continue;

		RenderData Data;
		Data.Actor = actor;
		Data.DisplayText = DisplayName + " [" + std::to_string(static_cast<int>(Distance)) + "m]";
		Data.DisplayClassName = actor->Class->GetFullName();
		Data.ScreenLocation = ScreenLocation;
		Data.bIsVisible = bIsVisible;
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
			if (renderData.size() > 1000) continue;
			ImGui::Text(Data.DisplayText.c_str());
		}

		ImGui::End();
	}
}

nlohmann::json ESP::Serialize() const
{
	nlohmann::json j = FeatureFactory::Serialize();
	
	// Сохраняем базовые настройки ESP
	j["occluded"] = bOccluded;
	j["debug_window"] = m_bDebugWindow;
	j["tracers"] = bTracers;
	j["occluded_tracers"] = bOccludedTracers;
	j["search_class_name"] = searchClassName;
	j["default_filters"] = bDefaultFilters;
	
	// Сохраняем цвета и толщину линий
	j["color"] = {fColor[0], fColor[1], fColor[2], fColor[3]};
	j["occluded_color"] = {fOccludedColor[0], fOccludedColor[1], fOccludedColor[2], fOccludedColor[3]};
	j["thickness"] = fThickness;
	
	// Сохраняем настройки трейсеров
	j["tracer_color"] = {fTracerColor[0], fTracerColor[1], fTracerColor[2], fTracerColor[3]};
	j["tracer_color_occluded"] = {fTracerColorOccluded[0], fTracerColorOccluded[1], fTracerColorOccluded[2], fTracerColorOccluded[3]};
	j["tracer_thickness"] = {
		{"min", TracerThickness.Min},
		{"max", TracerThickness.Max},
		{"current", TracerThickness.Current}
	};
	
	// Сохраняем настройки дистанции
	j["esp_distance"] = {
		{"min", espDistance.Min},
		{"max", espDistance.Max},
		{"current", espDistance.Current}
	};
	
	return j;
}

void ESP::Deserialize(const nlohmann::json &json)
{
	// Загружаем базовые настройки из родительского класса
	FeatureFactory::Deserialize(json);
	
	// Загружаем базовые настройки ESP
	if (json.contains("occluded")) bOccluded = json["occluded"].get<bool>();
	if (json.contains("debug_window")) m_bDebugWindow = json["debug_window"].get<bool>();
	if (json.contains("tracers")) bTracers = json["tracers"].get<bool>();
	if (json.contains("occluded_tracers")) bOccludedTracers = json["occluded_tracers"].get<bool>();
	if (json.contains("search_class_name")) searchClassName = json["search_class_name"].get<std::string>();
	if (json.contains("default_filters")) bDefaultFilters = json["default_filters"].get<bool>();
	
	// Загружаем цвета и толщину линий
	if (json.contains("color") && json["color"].is_array() && json["color"].size() == 4) {
		for (int i = 0; i < 4; i++) {
			fColor[i] = json["color"][i].get<float>();
		}
	}
	
	if (json.contains("occluded_color") && json["occluded_color"].is_array() && json["occluded_color"].size() == 4) {
		for (int i = 0; i < 4; i++) {
			fOccludedColor[i] = json["occluded_color"][i].get<float>();
		}
	}
	
	if (json.contains("thickness")) fThickness = json["thickness"].get<float>();
	
	// Загружаем настройки трейсеров
	if (json.contains("tracer_color") && json["tracer_color"].is_array() && json["tracer_color"].size() == 4) {
		for (int i = 0; i < 4; i++) {
			fTracerColor[i] = json["tracer_color"][i].get<float>();
		}
	}
	
	if (json.contains("tracer_color_occluded") && json["tracer_color_occluded"].is_array() && json["tracer_color_occluded"].size() == 4) {
		for (int i = 0; i < 4; i++) {
			fTracerColorOccluded[i] = json["tracer_color_occluded"][i].get<float>();
		}
	}
	
	// Загружаем настройки толщины трейсеров
	if (json.contains("tracer_thickness")) {
		auto& thickness = json["tracer_thickness"];
		if (thickness.contains("min")) TracerThickness.Min = thickness["min"].get<float>();
		if (thickness.contains("max")) TracerThickness.Max = thickness["max"].get<float>();
		if (thickness.contains("current")) TracerThickness.Current = thickness["current"].get<float>();
	}
	
	// Загружаем настройки дистанции
	if (json.contains("esp_distance")) {
		auto& distance = json["esp_distance"];
		if (distance.contains("min")) espDistance.Min = distance["min"].get<float>();
		if (distance.contains("max")) espDistance.Max = distance["max"].get<float>();
		if (distance.contains("current")) espDistance.Current = distance["current"].get<float>();
	}
}