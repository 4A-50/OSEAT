#pragma once

#include <vector>

class FitFileData
{
	public:
		FitFileData() {}

		//----Live Data
		/// <summary>
		/// Timestamps In Seconds Since FIT Epoch (31 Dec 1989 UTC)
		/// </summary>
		std::vector<long> timestamp;

		/// <summary>
		/// Latitude
		/// </summary>
		std::vector<float> posLat;
		/// <summary>
		/// Longitude
		/// </summary>
		std::vector<float> posLong;

		/// <summary>
		/// GPS Accuracy In Meters
		/// </summary>
		std::vector<int> gpsAccuracy;

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

		/// <summary>
		/// Heart Rate In BPM
		/// </summary>
		std::vector<int> heartRate;

		/// <summary>
		/// Calories In Kcal
		/// </summary>
		std::vector<int> calories;

		/// <summary>
		/// Cadence In RPM
		/// </summary>
		std::vector<int> cadence;
		/// <summary>
		/// Speed In M/S
		/// </summary>
		std::vector<float> speed;

		/// <summary>
		/// Temperature In 'C
		/// </summary>
		std::vector<int> temp;

		/// <summary>
		/// Ascent In Meters
		/// </summary>
		std::vector<int> ascent;
		/// <summary>
		/// Descent In Meters
		/// </summary>
		std::vector<int> descent;
		//----

		//----Overall Data
		/// <summary>
		/// Start Time In Seconds Since FIT Epoch (31 Dec 1989 UTC)
		/// </summary>
		long startTime;
		/// <summary>
		/// Total Activity Time In Seconds
		/// </summary>
		int elapsedTime;
		/// <summary>
		/// Total Moving Time In Seconds
		/// </summary>
		int movingTime;
		/// <summary>
		/// Average Speed In M/S
		/// </summary>
		float averageSpeed;
		/// <summary>
		/// Max Speed In M/S
		/// </summary>
		float maxSpeed;
		/// <summary>
		/// Total Distance In Meters
		/// </summary>
		float totalDistance;
		/// <summary>
		/// Average Cadence In RPM
		/// </summary>
		int averageCadence;
		/// <summary>
		/// Max Cadence In RPM
		/// </summary>
		int maxCadence;
		/// <summary>
		/// Min Heart Rate In BPM
		/// </summary>
		int minHeartRate;
		/// <summary>
		/// Average Heart Rate In BPM
		/// </summary>
		int averageHeartRate;
		/// <summary>
		/// Max Heart Rate In BPM
		/// </summary>
		int maxHeartRate;
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
		int totalCalories;
		/// <summary>
		/// Average Temperature In 'C
		/// </summary>
		int averageTemperature;
		/// <summary>
		/// Max Temperature In 'C
		/// </summary>
		int maxTemperature;
		/// <summary>
		/// Total Ascent In Meters
		/// </summary>
		int totalAscent;
		/// <summary>
		/// Total Descent In Meters
		/// </summary>
		int totalDescent;
		//----

		/// <summary>
		/// Clears All The Data
		/// </summary>
		FitFileData ClearFileData();
};

inline FitFileData FitFileData::ClearFileData() 
{
	return FitFileData();
}