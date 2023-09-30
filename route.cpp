#include "route.h"

void Route::RouteGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(860, 20, 400, 220, window_flags, main_viewport, "Route");

    //Creates The Route Plot
    if (ImPlot::BeginPlot(Core::fileData.fileName.c_str(), ImVec2(380, 180), ImPlotFlags_NoFrame | ImPlotFlags_Crosshairs)) {
        //Set/Hides The Axis
        ImPlot::SetupAxes("##Longitude", "##Latitude", axisFlags, axisFlags);
        ImPlot::SetupAxesLimits(Core::fileData.minPosLong, Core::fileData.maxPosLong, Core::fileData.minPosLat, Core::fileData.maxPosLat, ImPlotCond_Once);
        
        //Plots The Data
        ImPlot::PlotLine(Core::fileData.fileName.c_str(), Core::fileData.posLong.data(), Core::fileData.posLat.data(), Core::fileData.posLat.size());

        ImPlot::EndPlot();
    }
    ImGui::End();
}