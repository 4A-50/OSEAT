#include "zones.h"

Zones::Zones(FitFileData& _fileData) : fileData(_fileData) {}

void Zones::ZonesGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(20, 260, 400, 440, window_flags, main_viewport, "Zones");

    //Creates A Tab Bar
    if (ImGui::BeginTabBar("ZonesTabBar", ImGuiTabBarFlags_None))
    {
        //HR Section
        if (ImGui::BeginTabItem("Heart Rate"))
        {
            //Sets Up The HR Color Map
            ImPlot::PushColormap(ImPlotColormap_Hot);
            //Creates The HR Pie Chart
            if (ImPlot::BeginPlot("##", ImVec2(380, 380), ImPlotFlags_Equal | ImPlotFlags_NoMouseText | ImPlotFlags_NoFrame | ImPlotFlags_NoInputs)) {
                //Hides & Sets Up The Axis
                ImPlot::SetupAxes(nullptr, nullptr, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_NoDecorations);
                ImPlot::SetupAxesLimits(0, 1, 0, 1);
                //Plots The Data
                ImPlot::PlotPieChart(heartRateLabels, heartRatePrecent, 5, 0.5, 0.5, 0.4, "%.2f%%", 180, ImPlotPieChartFlags_Normalize);

                ImPlot::EndPlot();
            }
            //Clears The Color Map
            ImPlot::PopColormap();

            ImGui::EndTabItem();
        }
        //Power Section
        if (ImGui::BeginTabItem("Power"))
        {
            //Sets Up The HR Color Map
            ImPlot::PushColormap(ImPlotColormap_Plasma);
            //Creates The Power Pie Chart
            if (ImPlot::BeginPlot("##", ImVec2(380, 380), ImPlotFlags_Equal | ImPlotFlags_NoMouseText | ImPlotFlags_NoFrame | ImPlotFlags_NoInputs)) {
                //Hides & Sets Up The Axis
                ImPlot::SetupAxes(nullptr, nullptr, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_NoDecorations);
                ImPlot::SetupAxesLimits(0, 1, 0, 1);
                //Plots The Data
                ImPlot::PlotPieChart(powerLabels, powerPrecent, 7, 0.5, 0.5, 0.4, "%.2f%%", 180, ImPlotPieChartFlags_Normalize);

                ImPlot::EndPlot();
            }
            //Clears The Color Map
            ImPlot::PopColormap();

            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    ImGui::End();
}