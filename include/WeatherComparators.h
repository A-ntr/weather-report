#ifndef WEATHER_COMPARATORS_H
#define WEATHER_COMPARATORS_H

#include "WeatherRecord.h"

// Functor for Precipitation
struct ComparePrecipitationAsc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.precipitation < b.precipitation;
  }
};
struct ComparePrecipitationDesc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.precipitation > b.precipitation;
  }
};
// Functor for Latitude Sorting
struct CompareLatitudeAsc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.locLat < b.locLat;
  }
};
struct CompareLatitudeDesc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.locLat > b.locLat;
  }
};
// Functor for Longitude Sorting
struct CompareLongitudeAsc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.locLng < b.locLng;
  }
};
struct CompareLongitudeDesc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.locLng > b.locLng;
  }
};
// Functor for Coordinate Sorting
struct CompareCoordinateAsc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    if (a.locLng != b.locLng) return a.locLng < b.locLng; // Sort by X
    return a.locLat < b.locLat; // If X is equal, sort by Y
  }
};
struct CompareCoordinateDesc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    if (a.locLng != b.locLng) return a.locLng > b.locLng; // Sort by X
    return a.locLat > b.locLat; // If X is equal, sort by Y
  }
};
// Functor for Severity Sorting
struct CompareSeverityAsc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return WeatherRecord::getSeverityRank(a.severity) < WeatherRecord::getSeverityRank(b.severity);
  }
};
struct CompareSeverityDesc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return WeatherRecord::getSeverityRank(a.severity) > WeatherRecord::getSeverityRank(b.severity);
  }
};
// Functor for Type Sorting
struct CompareTypeAsc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.type < b.type;
  }
};
struct CompareTypeDesc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.type > b.type;
  }
};
// Functor for EventID Sorting

#endif // WEATHER_COMPARATORS_H