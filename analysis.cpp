#include "analysis.h"

Analysis::Analysis(FitFileData& _fileData) : fileData(_fileData) {}

void Analysis::AnalysisGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(440, 260, 820, 440, window_flags, main_viewport, "Analysis");

    //Creates The Route Plot
    /*if (ImPlot::BeginPlot("##", ImVec2(800, 400), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText)) {
        //Set/Hides The Axis
        ImPlot::SetupAxes("Distance (M)", "Speed (KPH)", ImPlotAxisFlags_None, ImPlotAxisFlags_None);
        //Plots The Data
        ImPlot::PlotLine("", fileData.distance.data(), fileData.speed.data(), fileData.speed.size());

        ImPlot::EndPlot();
    }*/

    if (ImPlot::BeginSubplots("##", 5, 1, ImVec2(800, 400), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText, rowRatios, colRatios)) {
        if (ImPlot::BeginPlot("", ImVec2(), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText)) {
            ImPlot::SetupAxes(NULL, NULL, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
            ImPlot::SetNextLineStyle(ImPlot::SampleColormap(1, ImPlotColormap_Jet));
            ImPlot::PlotLine("", fileData.distance.data(), fileData.speed.data(), fileData.speed.size());
            ImPlot::EndPlot();
        }
        if (ImPlot::BeginPlot("", ImVec2(), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText)) {
            ImPlot::SetupAxes(NULL, NULL, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
            ImPlot::SetNextLineStyle(ImPlot::SampleColormap(2, ImPlotColormap_Jet));
            ImPlot::PlotLine("", fileData.distance.data(), fileData.altitude.data(), fileData.speed.size());
            ImPlot::EndPlot();
        }
        if (ImPlot::BeginPlot("", ImVec2(), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText)) {
            ImPlot::SetupAxes(NULL, NULL, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
            ImPlot::SetNextLineStyle(ImPlot::SampleColormap(3, ImPlotColormap_Jet));
            ImPlot::PlotLine("", fileData.distance.data(), fileData.heartRate.data(), fileData.speed.size());
            ImPlot::EndPlot();
        }
        if (ImPlot::BeginPlot("", ImVec2(), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText)) {
            ImPlot::SetupAxes(NULL, NULL, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
            ImPlot::SetNextLineStyle(ImPlot::SampleColormap(4, ImPlotColormap_Jet));
            ImPlot::PlotLine("", fileData.distance.data(), fileData.cadence.data(), fileData.speed.size());
            ImPlot::EndPlot();
        }
        if (ImPlot::BeginPlot("", ImVec2(), ImPlotFlags_NoFrame | ImPlotFlags_NoMouseText)) {
            ImPlot::SetupAxes(NULL, NULL, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoDecorations);
            ImPlot::SetNextLineStyle(ImPlot::SampleColormap(5, ImPlotColormap_Jet));
            ImPlot::PlotLine("", fileData.distance.data(), fileData.grade.data(), fileData.speed.size());
            ImPlot::EndPlot();
        }

        ImPlot::EndSubplots();
    }

    ImGui::End();
}