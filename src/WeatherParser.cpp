#include "WeatherParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<WeatherRecord> WeatherParser::parseCSV(const string& filePath) {
  vector<WeatherRecord> records;
  ifstream file(filePath);

  if (!file.is_open()) {
    cerr << "Error: Unable to open file at " << filePath << endl;
    return records;
  }

  // Reserve space to minimize memory re-allocations for large datasets (>100,000 rows)
  records.reserve(150000);

  string line;

  // Skip first line (header)
  if (!getline(file, line)) {
    cerr << "Error: Empty CSV file." << endl;
    return records;
  }

  while (getline(file, line)) {
    if(line.empty()) continue;
    stringstream ss(line);
    WeatherRecord record;
    string token; // string value placeholder for numerical data type (i.e. double precipitation)

    // Parsing
      // Categorization
    getline(ss, record.eventId, ',');
    getline(ss, record.type, ',');
    getline(ss, record.severity, ',');
      // Timestamps
    getline(ss, record.startTime, ',');
    getline(ss, record.endTime, ',');
      // Precipitation (double)
    getline(ss, token, ',');
    record.precipitation = token.empty() ? 0.0 : stod(token);
      // Time Zone
    getline(ss, record.timeZone, ',');
      // Airport Code
    getline(ss, record.airportCode, ',');
      // Latitude (double)
    getline(ss, token, ',');
    record.locLat = token.empty() ? 0.0 : stod(token);
      // Longitude (double)
    getline(ss, token, ',');
    record.locLng = token.empty() ? 0.0 : stod(token);
      // Location info
    std::getline(ss, record.city, ',');
    std::getline(ss, record.county, ',');
    std::getline(ss, record.state, ',');
    std::getline(ss, record.zipCode, ',');

    records.push_back(record);
  }
  file.close();
  std::cout << "Successfully parsed " << records.size() << " records." << std::endl;
  return records;
}
