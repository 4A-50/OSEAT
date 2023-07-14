#include "splits.h"

Splits::Splits(FitFileData& _fileData) : fileData(_fileData) {}

void Splits::SplitsGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(440, 20, 400, 220, window_flags, main_viewport, "Splits");

    //Gets The Lap Data
    splits.clear();
    
    for (int i = 0; i < fileData.laps.size(); i++)
    {
        splits.push_back(ConvertToMinPerKM(fileData.laps[i].totalTime, fileData.laps[i].totalDistance));
    }

    //Creates The Split Plot
    if (ImPlot::BeginPlot("##", ImVec2(380, 180), ImPlotFlags_NoFrame | ImPlotFlags_NoInputs)) {
        //Sets Up The Y Axis
        ImPlot::SetupAxes(nullptr, "Time", ImPlotAxisFlags_NoDecorations | ImPlotAxisFlags_AutoFit, ImPlotAxisFlags_AutoFit);
        //Plots The Data
        ImPlot::PlotBars("", splits.data(), splits.size(), 0.9, 1);
        ImPlot::EndPlot();
    }

    ImGui::End();
}

float Splits::ConvertToMinPerKM(float movingTime, float distance)
{
    float pace = (movingTime / distance) / 60 * 1000;
    float leftover = fmod(pace,1);
    float minutes = pace - leftover;
    float seconds = roundf(leftover * 60);

    return minutes + (seconds / 100);
}