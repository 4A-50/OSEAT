#pragma once

#include "imgui.h"
#include "implot.h"
#include "math.h"
#include <algorithm>

#include "core.h"

class Route
{
	public:
		void RouteGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport);

	private:

		ImPlotAxisFlags axisFlags = ImPlotAxisFlags_NoDecorations;;
};