#include "route.h"

Route::Route(FitFileData& _fileData) : fileData(_fileData)
{
    axisFlags = 
          ImPlotAxisFlags_NoDecorations
        | ImPlotAxisFlags_AutoFit;
}

void Route::RouteGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(860, 20, 400, 220, window_flags, main_viewport, "Route");

    //Creates The Route Plot
    if (ImPlot::BeginPlot("##", ImVec2(380, 180), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText)) {
        //Set/Hides The Axis
        ImPlot::SetupAxes("##Longitude", "##Latitude", axisFlags, axisFlags);
        //Plots The Data
        ImPlot::PlotLine("", fileData.posLong.data(), fileData.posLat.data(), fileData.posLat.size());

        ImPlot::EndPlot();
    }
    ImGui::End();
}