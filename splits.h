#pragma once

#include "imgui.h"
#include "implot.h"

#include "core.h"
#include "fit-file-data.h"

#include <vector>

class Splits
{
	public:
		Splits(FitFileData& _fileData);
		void SplitsGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport);

	private:
		float ConvertToMinPerKM(float movingTime, float distance);

		FitFileData& fileData;

		std::vector<float> splits;
};