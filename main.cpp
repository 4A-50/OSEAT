#include "imgui.h"
#include "imgui-SFML.h"
#include "implot.h"
#include "SFML/Graphics.hpp"

#include "core.h"
#include "fit-file-data.h"
#include "file-loader.h"
#include "zones.h"
#include "splits.h"
#include "route.h"
#include "analysis.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "OSEAT", sf::Style::Titlebar | sf::Style::Close);
    ImGui::SFML::Init(window);

    //Initialises The FitFileData Class
    FitFileData fileData = FitFileData();

    //Initialises The Window Classes
    FileLoader fileLoader(fileData);
    Zones zones(fileData);
    Splits splits(fileData);
    Route route(fileData);
    Analysis analysis(fileData);

    //ImGUI Window Flags
    ImGuiWindowFlags window_flags =
          ImGuiWindowFlags_NoResize
        | ImGuiWindowFlags_NoMove
        | ImGuiWindowFlags_NoSavedSettings
        | ImGuiWindowFlags_NoCollapse
        | ImGuiWindowFlags_NoBringToFrontOnFocus;

    //ImGui & ImPlot Contexts
    ImGui::CreateContext();
    ImPlot::CreateContext();

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());
        
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        
        //----File Loader
        fileLoader.FileLoaderGUI(window_flags, main_viewport);
        //----

        //----Splits
        splits.SplitsGUI(window_flags, main_viewport);
        //----

        //----Route
        route.RouteGUI(window_flags, main_viewport);
        //----

        //----Zones
        zones.ZonesGUI(window_flags, main_viewport);
        //----

        //----Analysis
        analysis.AnalysisGUI(window_flags, main_viewport);
        //----

        window.clear(sf::Color(17, 17, 17));
        ImGui::SFML::Render(window);
        window.display();
    }

    std::cout << fileData.averageCadence << std::endl;

    ImGui::SFML::Shutdown();
    ImGui::DestroyContext();
    ImPlot::DestroyContext();
    return 0;
}

/* Modal Popups
if (ImGui::Button("Delete.."))
    ImGui::OpenPopup("Delete?");

// Always center this window when appearing
ImVec2 center = ImGui::GetMainViewport()->GetCenter();
ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

if (ImGui::BeginPopupModal("Delete?", NULL, ImGuiWindowFlags_AlwaysAutoResize))
{
    ImGui::Text("All those beautiful files will be deleted.\nThis operation cannot be undone!");
    ImGui::Separator();

    //static int unused_i = 0;
    //ImGui::Combo("Combo", &unused_i, "Delete\0Delete harder\0");

    static bool dont_ask_me_next_time = false;
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
    ImGui::Checkbox("Don't ask me next time", &dont_ask_me_next_time);
    ImGui::PopStyleVar();

    if (ImGui::Button("OK", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
    ImGui::SetItemDefaultFocus();
    ImGui::SameLine();
    if (ImGui::Button("Cancel", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
    ImGui::EndPopup();
}
*/