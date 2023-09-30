#pragma once

#include "imgui.h"
#include "implot.h"

#include "core.h"

class Analysis
{
	public:
		void AnalysisGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport);

	private:

		ImPlotAxisFlags plotFlags = ImPlotFlags_NoFrame | ImPlotFlags_Crosshairs;

		float rowRatios[5] = { 3, 2, 1.5, 1, 1 };
		float colRatios[1] = { 1 };
};