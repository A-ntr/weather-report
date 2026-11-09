#ifndef WEATHER_RECORD_H
#define WEATHER_RECORD_H
#pragma once

#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
// EventId,Type,Severity,StartTime(UTC),EndTime(UTC),Precipitation(in),TimeZone,AirportCode,LocationLat,LocationLng,City,County,State,ZipCode
struct WeatherRecord {
  // Categorization
  string eventId; // W-123456...
  string type; // Rain, Snow, Fog
  string severity; // Light, Severe
  // Timestamps
  string startTime;
  string endTime;
  // Precipitation
  double precipitation;
  // Geographical & Location Info
  std::string timeZone;
  std::string airportCode;
  double locLat; // Location Latitude coordinates
  double locLng; // Location Longitude coordinates
  std::string city;
  std::string county;
  std::string state;
  std::string zipCode;
  static int getSeverityRank(const std::string& sev) {
    if (sev == "Light") return 1;
    if (sev == "Moderate") return 2;
    if (sev == "Severe") return 3;
    return 0; // unknown default 0
  }

  std::string toString() const {
    std::ostringstream precipStr;
    precipStr << std::fixed << std::setprecision(2) << precipitation;

    return eventId + "\t" + (type == "Precipitation" ? "Precip" : type)
      + "\t" + severity + (severity == "Moderate" ? "" : "\t") + " " + state
      + "\t" + precipStr.str();
  }
};

#endif // WEATHER_RECORD_H