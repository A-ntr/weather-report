#ifndef WEATHER_COMPARATORS_H
#define WEATHER_COMPARATORS_H

#include "WeatherRecord.h"

// Functor for Precipitation (Ascending)
struct ComparePrecipitationAsc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.precipitation < b.precipitation;
  }
};
// Functor for Precipitation (Descending)
struct ComparePrecipitationDesc {
  bool operator()(const WeatherRecord& a, const WeatherRecord& b) const {
    return a.precipitation > b.precipitation;
  }
};
// Functor for Latitude Sorting

#endif // WEATHER_COMPARATORS_H