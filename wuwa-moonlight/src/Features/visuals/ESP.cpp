#include "ESP.hpp"

void ESP::Draw()
{
	ImGui::Checkbox("ESP", &bEnable);
	ImGui::SameLine();
	ImGui::Tooltip("Extra Sensory Perception");

	if (bEnable)
	{
		ImGui::SliderFloat("Distance", &espDistance.Current, espDistance.Min, espDistance.Max, "%.2f");
		ImGui::ColorEdit4("Occluded color", fOccludedColor);
		
		ImGui::SameLine();
		ImGui::Tooltip("Color of invisible object");

		ImGui::ColorEdit4("Color", fColor);
		ImGui::SameLine();
		ImGui::Tooltip("Color of visible object");

		ImGui::NewLine();

		ImGui::Text("Search Actor Class");
		char buffer[256] = { 0 };
		std::strncpy(buffer, searchClassName.c_str(), sizeof(buffer) - 1);
		if (ImGui::InputText("##ClassSearch", buffer, sizeof(buffer)))
		{
			searchClassName = buffer;
		}
		ImGui::SameLine();
		ImGui::Tooltip("Enter actor class name (e.g., Collect003, Monster012)");

		ImGui::NewLine();
	}

	ImGui::Checkbox("Debug window", &m_bDebugWindow);
}

void ESP::Render()
{
	if (!bEnable) return;

	ImDrawList* drawBackList = ImGui::GetBackgroundDrawList();

	ImVec4 color = ImVec4(fOccludedColor[0], fOccludedColor[1], fOccludedColor[2], fOccludedColor[3]);

	//drawList->AddRectFilled(ImVec2(200, 200), ImVec2(400, 400), ImColor(color));

	for (const auto& Data : renderActors)
	{
		ImVec4 Color = Data.bIsVisible ? ImVec4(fColor[0], fColor[1], fColor[2], fColor[3]) :
			ImVec4(fOccludedColor[0], fOccludedColor[1], fOccludedColor[2], fOccludedColor[3]);

		drawBackList->AddText(ImVec2(Data.ScreenLocation.X, Data.ScreenLocation.Y), ImColor(Color), Data.DisplayText.c_str());

		drawBackList->AddLine(ImGui::GetIO().DisplaySize / 2, ImVec2(Data.ScreenLocation.X, Data.ScreenLocation.Y), ImColor(200, 0, 0, 255));
	}

}

void ESP::Run() // routine
{
	if (!bEnable) return;
	
	std::vector<RenderData> tempActors;

	if (globals::world == nullptr) return;
	//LOG_INFO("ESP: World issue");

	if (globals::player_controller == nullptr) return;
	//LOG_INFO("ESP: PC issue");

	auto Game_State = globals::world->GameState;
	if (Game_State == nullptr) return;
	//LOG_INFO("ESP: GameState issue");

	auto Persisten_Level = globals::world->PersistentLevel;
	if (Persisten_Level == nullptr) return;
	//LOG_INFO("ESP: Persistent level issue");

	if (globals::pawn == nullptr) return;


	// Получаем позицию камеры
	auto camera_manager = globals::player_controller->PlayerCameraManager;
	if (camera_manager == nullptr) return;

	renderActors.clear();
	tempActors.clear();

	SDK::FVector CameraLocation = camera_manager->GetCameraLocation();
	cameraLocation = CameraLocation;

	for (auto actor : Persisten_Level->Actors) {
		if (!actor || actor == globals::pawn) continue;

		std::string ActorClassName = actor->Class->GetName();
		std::string DisplayName = ActorClassName.c_str();

		bool bIsVisible = globals::player_controller->LineOfSightTo(actor, CameraLocation, false);

		SDK::FVector ActorLocation = actor->K2_GetActorLocation();

		float Distance = globals::player_controller->GetDistanceTo(actor) / 100.0f;
		if (Distance > espDistance.Current) continue;

		SDK::FVector2D ScreenLocation;
		if (!globals::player_controller->ProjectWorldLocationToScreen(ActorLocation, &ScreenLocation, false)) continue;


		RenderData Data;
		Data.Actor = actor;
		Data.DisplayText = DisplayName + "[" + std::to_string(static_cast<int>(Distance)) + "m]";
		Data.ScreenLocation = ScreenLocation;
		Data.bIsVisible = bIsVisible;
		tempActors.push_back(Data);
	}

	renderActors.swap(tempActors);
}

void ESP::RenderDebug()
{
	if (!m_bDebugWindow) return;

	ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Once);
	if (ImGui::Begin("ESP Debug stuff"))
	{
		for (const auto& Data : renderActors)
		{
			if (!Data.Actor) continue;
			if (renderActors.size() > 100) continue;
			ImGui::Text(Data.DisplayText.c_str());
		}

		ImGui::End();
	}
}