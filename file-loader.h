#pragma once

#include "imgui.h"
#include "imfilebrowser.h"

#include "fit_decode.hpp"
#include "fit_mesg_broadcaster.hpp"
#include "fit_developer_field_description.hpp"
#include "Listener.h"

#include "core.h"

#include <vector>
#include <fstream>
#include <iostream>

class FileLoader
{
	public:
		FileLoader();
		void FileLoaderGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport);

	private:

		fit::Decode decode;
		fit::MesgBroadcaster mesgBroadcaster;
		Listener listener;
		std::fstream file;

		ImGui::FileBrowser fileDialog;
		std::string path = "/";
		std::string ext = ".fit";

		std::vector<std::string> files;

		void SearchDirectory();
		void LoadFile(int fileIndex);
};