#ifndef WEATHER_PARSER_H
#define WEATHER_PARSER_H

#include "WeatherRecord.h"
#include <vector>
#include <string>

class WeatherParser {
public:
    // Reads CSV file and returns a dynamic vector of parsed weather records
    static std::vector<WeatherRecord> parseCSV(const std::string& filePath, size_t maxRecords = 100000);
};

#endif // WEATHER_PARSER_H