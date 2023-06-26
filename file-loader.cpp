#include "file-loader.h"

#include <iostream>

FileLoader::FileLoader(FitFileData& _fileData) : fileData(_fileData)
{
    //Fit SDK Setup
    decode = fit::Decode();
    mesgBroadcaster = fit::MesgBroadcaster();
    listener = Listener(_fileData);
    file = std::fstream();

    //File Dialog Setup
    fileDialog = ImGui::FileBrowser(ImGuiFileBrowserFlags_SelectDirectory);
    fileDialog.SetTitle("Exercise Files");
    fileDialog.SetTypeFilters({ ".fit" });

    //Searched The Default Directory
    SearchDirectory();
}

void FileLoader::FileLoaderGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport)
{
    //Builds The Core Of The Section Window
    Core::BuildIMGUIWindow(20, 20, 400, 220, window_flags, main_viewport, "Exercise Files");

    //-- Section ImGui
    ImGui::Text("Load An Exercise File (.fit)");

    ImGui::BeginChild("Scrolling", { 0, 140 }, true);
        if (files.size() > 0)
        {
            for (int i = 0; i < files.size(); i++)
                if (ImGui::Button(files[i].c_str()))
                    LoadFile(i);
        }
        else
        {
            ImGui::Text("No .fit Files Found");
        }
    ImGui::EndChild();

    if (ImGui::Button("Change Directory"))
        fileDialog.Open();
    //Change Dir Button Tool Tip
    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
        ImGui::SetTooltip("Select A Directory, Containing .fit Files");

    ImGui::SameLine();
    if (ImGui::Button("Refresh"))
        SearchDirectory();
    //Refresh Button Tool Tip
    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
        ImGui::SetTooltip("Refresh Directory Search");

    ImGui::End();
    //--

    //---Displays The File Dialog
    fileDialog.Display();

    if (fileDialog.HasSelected())
    {
        path = fileDialog.GetSelected().string();
        SearchDirectory();

        fileDialog.ClearSelected();
    }
    //---
}

void FileLoader::SearchDirectory()
{
    //Clears Out The Vector For A New Search
    files.clear();

    //Encased In Try Catch To Stop Errors If No Files Are Found
    try 
    {
        for (auto& p : std::filesystem::recursive_directory_iterator(path))
        {
            if (p.path().extension() == ext)
                files.push_back(p.path().stem().string());
        }
    }
    catch (...)
    {
        return;
    }
}

void FileLoader::LoadFile(int fileIndex)
{
    //Resets The File Data Class To A Clean Slate
    fileData = fileData.ClearFileData();

    std::string filePath = path + "\\" + files[fileIndex] + ext;

    file.open(filePath, std::ios::in | std::ios::binary);

    if (!file.is_open())
    {
        printf("Error opening file\n");
        return;
    }

    if (!decode.CheckIntegrity(file))
    {
        printf("FIT file integrity failed.\nAttempting to decode...\n");
    }

    //mesgBroadcaster.AddListener((fit::FileIdMesgListener&)listener);
    //mesgBroadcaster.AddListener((fit::UserProfileMesgListener&)listener);
    //mesgBroadcaster.AddListener((fit::MonitoringMesgListener&)listener);
    //mesgBroadcaster.AddListener((fit::DeviceInfoMesgListener&)listener);
    //mesgBroadcaster.AddListener((fit::RecordMesgListener&)listener);
    mesgBroadcaster.AddListener((fit::MesgListener&)listener);

    try
    {
        decode.Read(&file, &mesgBroadcaster, &mesgBroadcaster, &listener);
    }
    catch (const fit::RuntimeException& e)
    {
        printf("Exception decoding file: %s\n", e.what());
        return;
    }

    printf("Decoded FIT file.\n");
    
    //A Bodge To Fix The Problems Making The Listener Version A Reference Makes
    fileData = listener.fileData;
}