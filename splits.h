#pragma once

#include "imgui.h"
#include "implot.h"

#include "core.h"

#include <vector>

class Splits
{
	public:
		void SplitsGUI(ImGuiWindowFlags window_flags, const ImGuiViewport* main_viewport);

	private:
		float ConvertToMinPerKM(float movingTime, float distance);

		std::vector<float> splits;
};