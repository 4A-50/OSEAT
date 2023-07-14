#pragma once

#include <vector>
#include <iostream>
#include "lap-data.h"

class FitFileData
{
	public:
		FitFileData() {}

		std::string fileName = "##";

		//----Live Data
		/// <summary>
		/// Timestamps In Seconds Since FIT Epoch (31 Dec 1989 UTC)
		/// </summary>
		std::vector<float> timestamp;

		/// <summary>
		/// Latitude
		/// </summary>
		std::vector<float> posLat;
		float minPosLat;
		float maxPosLat;
		/// <summary>
		/// Longitude
		/// </summary>
		std::vector<float> posLong;
		float minPosLong;
		float maxPosLong;

		/// <summary>
		/// GPS Accuracy In Meters
		/// </summary>
		std::vector<float> gpsAccuracy;

		/// <summary>
		/// Altitude In Meters
		/// </summary>
		std::vector<float> altitude;

		/// <summary>
		/// Grade As A Percentage
		/// </summary>
		std::vector<float> grade;

		/// <summary>
		/// Distance In Meters
		/// </summary>
		std::vector<float> distance;
		float minDistance;
		float maxDistance;

		/// <summary>
		/// Heart Rate In BPM
		/// </summary>
		std::vector<float> heartRate;

		/// <summary>
		/// Calories In Kcal
		/// </summary>
		std::vector<float> calories;

		/// <summary>
		/// Cadence In RPM
		/// </summary>
		std::vector<float> cadence;
		/// <summary>
		/// Speed In KPH
		/// </summary>
		std::vector<float> speed;

		/// <summary>
		/// Temperature In 'C
		/// </summary>
		std::vector<float> temp;

		/// <summary>
		/// Ascent In Meters
		/// </summary>
		std::vector<float> ascent;
		/// <summary>
		/// Descent In Meters
		/// </summary>
		std::vector<float> descent;
		//----

		//----Overall Data
		/// <summary>
		/// Start Time In Seconds Since FIT Epoch (31 Dec 1989 UTC)
		/// </summary>
		float startTime;
		/// <summary>
		/// Total Activity Time In Seconds
		/// </summary>
		float elapsedTime;
		/// <summary>
		/// Total Moving Time In Seconds
		/// </summary>
		float movingTime;
		/// <summary>
		/// Average Speed In KPH
		/// </summary>
		float averageSpeed;
		/// <summary>
		/// Max Speed In KPH
		/// </summary>
		float maxSpeed;
		/// <summary>
		/// Total Distance In Meters
		/// </summary>
		float totalDistance;
		/// <summary>
		/// Average Cadence In RPM
		/// </summary>
		float averageCadence;
		/// <summary>
		/// Max Cadence In RPM
		/// </summary>
		float maxCadence;
		/// <summary>
		/// Min Heart Rate In BPM
		/// </summary>
		float minHeartRate;
		/// <summary>
		/// Average Heart Rate In BPM
		/// </summary>
		float averageHeartRate;
		/// <summary>
		/// Max Heart Rate In BPM
		/// </summary>
		float maxHeartRate;
		/// <summary>
		/// Min Altitude In Meters
		/// </summary>
		float minAltitude;
		/// <summary>
		/// Average Altitude In Meters
		/// </summary>
		float averageAltitude;
		/// <summary>
		/// Max Altitude In Meters
		/// </summary>
		float maxAltitude;
		/// <summary>
		/// Max Negative Gradient In %
		/// </summary>
		float maxNegativeGradient;
		/// <summary>
		/// Average Gradient In %
		/// </summary>
		float averageGradient;
		/// <summary>
		/// Max Positive Gradient In %
		/// </summary>
		float maxPositiveGradient;
		/// <summary>
		/// Total Calories In Kcal
		/// </summary>
		float totalCalories;
		/// <summary>
		/// Average Temperature In 'C
		/// </summary>
		float averageTemperature;
		/// <summary>
		/// Max Temperature In 'C
		/// </summary>
		float maxTemperature;
		/// <summary>
		/// Total Ascent In Meters
		/// </summary>
		float totalAscent;
		/// <summary>
		/// Total Descent In Meters
		/// </summary>
		float totalDescent;
		//----

		//----Laps
		std::vector<LapData> laps;
		//----

		/// <summary>
		/// Clears All The Data
		/// </summary>
		void ClearFileData();
};

/// <summary>
/// Clears All The Data
/// Not How I Wanted To Do It
/// </summary>
inline void FitFileData::ClearFileData()
{
	fileName = "##";

	posLat.clear();
	minPosLat = 0;
	maxPosLat = 0;

	posLong.clear();
	minPosLong = 0;
	maxPosLong = 0;

	gpsAccuracy.clear();
	altitude.clear();
	grade.clear();

	distance.clear();
	minDistance = 0;
	maxDistance = 0;

	heartRate.clear();
	calories.clear();
	cadence.clear();
	speed.clear();
	temp.clear();
	ascent.clear();
	descent.clear();

	startTime = 0;
	elapsedTime = 0;
	movingTime = 0;
	averageSpeed = 0;
	maxSpeed = 0;
	totalDistance = 0;
	averageCadence = 0;
	maxCadence = 0;
	minHeartRate = 0;
	averageHeartRate = 0;
	maxHeartRate = 0;
	minAltitude = 0;
	averageAltitude = 0;
	maxAltitude = 0;
	maxNegativeGradient = 0;
	averageGradient = 0;
	maxPositiveGradient = 0;
	totalCalories = 0;
	averageTemperature = 0;
	maxTemperature = 0;
	totalAscent = 0;
	totalDescent = 0;

	laps.clear();
}