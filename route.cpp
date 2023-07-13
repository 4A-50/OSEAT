#include "route.h"

Route::Route(FitFileData& _fileData) : fileData(_fileData)
{
    axisFlags = ImPlotAxisFlags_NoDecorations;
}

void Route::RouteGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(860, 20, 400, 220, window_flags, main_viewport, "Route");

    //Creates The Route Plot
    if (ImPlot::BeginPlot(fileData.fileName.c_str(), ImVec2(380, 180), ImPlotFlags_NoFrame | ImPlotFlags_Crosshairs)) {
        //Set/Hides The Axis
        ImPlot::SetupAxes("##Longitude", "##Latitude", axisFlags, axisFlags);
        ImPlot::SetupAxesLimits(fileData.minPosLong, fileData.maxPosLong, fileData.minPosLat, fileData.maxPosLat, ImPlotCond_Once);
        
        //Plots The Data
        ImPlot::PlotLine(fileData.fileName.c_str(), fileData.posLong.data(), fileData.posLat.data(), fileData.posLat.size());

        ImPlot::EndPlot();
    }
    ImGui::End();
}