#include "analysis.h"

Analysis::Analysis(FitFileData& _fileData) : fileData(_fileData) 
{
    plotFlags = ImPlotFlags_NoFrame | ImPlotFlags_Crosshairs;
}

void Analysis::AnalysisGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(440, 260, 820, 440, window_flags, main_viewport, ("Analysis" + fileData.fileName).c_str());

    //Creates The Analysis Plots
    if (ImPlot::BeginPlot(("##Speed" + fileData.fileName).c_str(), ImVec2(800, 115), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "Speed (KPH)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, fileData.minDistance, fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(0, ImPlotColormap_Jet));
        ImPlot::PlotLine(("Speed" + fileData.fileName).c_str(), fileData.distance.data(), fileData.speed.data(), fileData.speed.size());
        ImPlot::EndPlot();
    }

    if (ImPlot::BeginPlot(("##Altitude" + fileData.fileName).c_str(), ImVec2(800, 80), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "Altitude (M)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, fileData.minDistance, fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(2, ImPlotColormap_Jet));
        ImPlot::PlotLine(("Altitude" + fileData.fileName).c_str(), fileData.distance.data(), fileData.altitude.data(), fileData.altitude.size());
        ImPlot::EndPlot();
    }

    if (ImPlot::BeginPlot(("##HR" + fileData.fileName).c_str(), ImVec2(800, 70), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "HR (BPM)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, fileData.minDistance, fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(1, ImPlotColormap_Jet));
        ImPlot::PlotLine(("HR" + fileData.fileName).c_str(), fileData.distance.data(), fileData.heartRate.data(), fileData.heartRate.size());
        ImPlot::EndPlot();
    }

    if (ImPlot::BeginPlot(("##RPM" + fileData.fileName).c_str(), ImVec2(800, 60), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "Cadence (RPM)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, fileData.minDistance, fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(5, ImPlotColormap_Jet));
        ImPlot::PlotLine(("Cadence" + fileData.fileName).c_str(), fileData.distance.data(), fileData.cadence.data(), fileData.cadence.size());
        ImPlot::EndPlot();
    }

    if (ImPlot::BeginPlot(("##Grade" + fileData.fileName).c_str(), ImVec2(800, 60), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "Grade (%)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, fileData.minDistance, fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(6, ImPlotColormap_Jet));
        ImPlot::PlotLine(("Grade" + fileData.fileName).c_str(), fileData.distance.data(), fileData.grade.data(), fileData.grade.size());
        ImPlot::EndPlot();
    }

    ImGui::End();
}