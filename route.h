#pragma once

#include "imgui.h"
#include "implot.h"
#include "math.h"

#include "core.h"
#include "fit-file-data.h"

class Route
{
	public:
		Route(FitFileData& _fileData);

		void RouteGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport);

	private:
		FitFileData& fileData;

		ImPlotAxisFlags axisFlags;
};