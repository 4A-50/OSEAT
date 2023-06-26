#pragma once

#include "imgui.h"
#include "implot.h"

#include "core.h"
#include "fit-file-data.h"

class Zones
{
	public:
		Zones(FitFileData& _fileData);
		void ZonesGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport);

	private:
		FitFileData& fileData;

		const char* heartRateLabels[5] = {"Z1", "Z2", "Z3", "Z4", "Z5"};
		const char* powerLabels[7] = {"Z1", "Z2", "Z3", "Z4", "Z5", "Z6", "Z7"};

		float heartRatePrecent[5] = {0.0, 13.8, 22.5, 40.0, 23.7};
		float powerPrecent[7] = {10, 23, 30, 25, 7, 4, 1};
};