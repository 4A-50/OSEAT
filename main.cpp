#include "imgui.h"
#include "imgui-SFML.h"
#include "imfilebrowser.h"
#include "SFML/Graphics.hpp"

#include <iostream>

void BuildIMGUIWindow(int xPos, int yPos, int width, int height, ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport, const char title[]);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "OSEAT");
    ImGui::SFML::Init(window);

    //File Dialog Setup
    ImGui::FileBrowser fileDialog;
    fileDialog.SetTitle("Exercise Files");
    fileDialog.SetTypeFilters({ ".fit" });

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

        ImGuiWindowFlags window_flags = 
              ImGuiWindowFlags_NoResize 
            | ImGuiWindowFlags_NoMove 
            | ImGuiWindowFlags_NoSavedSettings
            | ImGuiWindowFlags_NoCollapse;
        
        //----File Loader
        BuildIMGUIWindow(20, 20, 400, 220, window_flags, main_viewport, "Exercise Files");

        ImGui::Text("Load A New Exercise File (.fit)");
        if (ImGui::Button("Select File"))
            fileDialog.Open();

        ImGui::Text("Load A Previous Exercise File:");
        ImGui::BeginChild("Scrolling", {0, 100});
        for (int n = 0; n < 50; n++)
            ImGui::Text("%04d: Some text", n);
        ImGui::EndChild();
        ImGui::Button("Change Directory");

        ImGui::End();
        //----

        fileDialog.Display();

        if (fileDialog.HasSelected())
        {
            std::cout << "Selected Filename " << fileDialog.GetSelected().string() << std::endl;
            fileDialog.ClearSelected();
        }

        BuildIMGUIWindow(440, 20, 400, 220, window_flags, main_viewport, "Splits");
        ImGui::End();

        BuildIMGUIWindow(860, 20, 400, 220, window_flags, main_viewport, "Route");
        ImGui::End();

        BuildIMGUIWindow(20, 260, 400, 440, window_flags, main_viewport, "Test 4");
        ImGui::End();

        BuildIMGUIWindow(440, 260, 820, 440, window_flags, main_viewport, "Test 5");
        ImGui::End();

        window.clear(sf::Color(17, 17, 17));
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}

void BuildIMGUIWindow(int xPos, int yPos, int width, int height, ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport, const char title[])
{
    ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + xPos, main_viewport->WorkPos.y + yPos), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Always);

    if (!ImGui::Begin(title, NULL, window_flags))
    {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return;
    }
}