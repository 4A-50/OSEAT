#include "analysis.h"

void Analysis::AnalysisGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(440, 260, 820, 440, window_flags, main_viewport, ("Analysis" + Core::fileData.fileName).c_str());

    //Creates The Analysis Plots
    if (ImPlot::BeginPlot(("##Speed" + Core::fileData.fileName).c_str(), ImVec2(800, 115), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "Speed (KPH)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, Core::fileData.minDistance, Core::fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(0, ImPlotColormap_Jet));
        ImPlot::PlotLine(("Speed" + Core::fileData.fileName).c_str(), Core::fileData.distance.data(), Core::fileData.speed.data(), Core::fileData.speed.size());
        ImPlot::EndPlot();
    }

    if (ImPlot::BeginPlot(("##Altitude" + Core::fileData.fileName).c_str(), ImVec2(800, 80), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "Altitude (M)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, Core::fileData.minDistance, Core::fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(2, ImPlotColormap_Jet));
        ImPlot::PlotLine(("Altitude" + Core::fileData.fileName).c_str(), Core::fileData.distance.data(), Core::fileData.altitude.data(), Core::fileData.altitude.size());
        ImPlot::EndPlot();
    }

    if (ImPlot::BeginPlot(("##HR" + Core::fileData.fileName).c_str(), ImVec2(800, 70), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "HR (BPM)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, Core::fileData.minDistance, Core::fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(1, ImPlotColormap_Jet));
        ImPlot::PlotLine(("HR" + Core::fileData.fileName).c_str(), Core::fileData.distance.data(), Core::fileData.heartRate.data(), Core::fileData.heartRate.size());
        ImPlot::EndPlot();
    }

    if (ImPlot::BeginPlot(("##RPM" + Core::fileData.fileName).c_str(), ImVec2(800, 60), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "Cadence (RPM)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, Core::fileData.minDistance, Core::fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(5, ImPlotColormap_Jet));
        ImPlot::PlotLine(("Cadence" + Core::fileData.fileName).c_str(), Core::fileData.distance.data(), Core::fileData.cadence.data(), Core::fileData.cadence.size());
        ImPlot::EndPlot();
    }

    if (ImPlot::BeginPlot(("##Grade" + Core::fileData.fileName).c_str(), ImVec2(800, 60), plotFlags)) {
        ImPlot::SetupAxes("Distance (M)", "Grade (%)", ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxisLimits(ImAxis_X1, Core::fileData.minDistance, Core::fileData.maxDistance);
        ImPlot::SetNextLineStyle(ImPlot::SampleColormap(6, ImPlotColormap_Jet));
        ImPlot::PlotLine(("Grade" + Core::fileData.fileName).c_str(), Core::fileData.distance.data(), Core::fileData.grade.data(), Core::fileData.grade.size());
        ImPlot::EndPlot();
    }

    ImGui::End();
}