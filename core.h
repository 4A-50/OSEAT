#pragma once

#include "imgui.h"

class Core
{
	public:
		static void BuildIMGUIWindow(int xPos, int yPos, int width, int height, ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport, const char title[]);
};

inline void Core::BuildIMGUIWindow(int xPos, int yPos, int width, int height, ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport, const char title[])
{
    //Set Windows Pos & Size
    ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + xPos, main_viewport->WorkPos.y + yPos), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Always);

    if (!ImGui::Begin(title, NULL, window_flags))
    {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return;
    }
}