#pragma once

#include "imgui.h"
#include "implot.h"

#include "core.h"
#include "fit-file-data.h"

class Analysis
{
	public:
		Analysis(FitFileData& _fileData);
		void AnalysisGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport);

	private:
		FitFileData& fileData;

		ImPlotAxisFlags plotFlags;

		float rowRatios[5] = { 3, 2, 1.5, 1, 1 };
		float colRatios[1] = { 1 };
};