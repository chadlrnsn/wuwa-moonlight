#include "ESP.hpp"

void ESP::Draw()
{
	if ( ImGui::Checkbox("ESP", &bEnable ))
	{
		ImGui::SliderFloat("Distance", &espDistance.Current, espDistance.Min, espDistance.Max, "%.2f");
		ImGui::ColorEdit4("Occluded color", fColor);
		
		ImGui::SameLine();
		ImGui::Tooltip("Color of invisible object");

		ImGui::ColorEdit4("Color", fColor);
		ImGui::SameLine();
		ImGui::Tooltip("Color of visible object");
	}
}

void ESP::Render()
{
	ImDrawList* drawBackList = ImGui::GetBackgroundDrawList();


	//ImDrawList* dl = ImGuiIO::
}

void ESP::Run() // routine
{

}