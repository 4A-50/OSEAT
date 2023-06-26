#include "splits.h"

Splits::Splits(FitFileData& _fileData) : fileData(_fileData) {}

void Splits::SplitsGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(440, 20, 400, 220, window_flags, main_viewport, "Splits");

    //Creates The Split Plot
    if (ImPlot::BeginPlot("##", ImVec2(380, 180), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText | ImPlotFlags_NoInputs)) {
        //Sets Up The Y Axis
        ImPlot::SetupAxes(nullptr, "Time", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_None);
        //Plots The Data
        ImPlot::PlotBars("", splits.data(), splits.size(), 0.9, 1);
        ImPlot::EndPlot();
    }

    ImGui::End();
}