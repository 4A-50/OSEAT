#include "route.h"

Route::Route(FitFileData& _fileData) : fileData(_fileData) {}

void Route::RouteGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(860, 20, 400, 220, window_flags, main_viewport, "Route");

    //Creates The Temp/Demo Sin Wave
    static float xs1[1001], ys1[1001];
    for (int i = 0; i < 1001; ++i) {
        xs1[i] = i * 0.001f;
        ys1[i] = 0.5f + 0.5f * sinf(50 * (xs1[i] + (float)ImGui::GetTime() / 10));
    }

    //Creates The Route Plot
    if (ImPlot::BeginPlot("##", ImVec2(380, 180), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText)) {
        //Set/Hides The Axis
        ImPlot::SetupAxes("", "", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_NoDecorations);
        //Plots The Data
        ImPlot::PlotLine("", xs1, ys1, 1001);

        ImPlot::EndPlot();
    }
    ImGui::End();
}