#include <iostream>
#include "WeatherParser.h"

int main() {
    std::string datasetPath = "../data/WeatherEvents_Jan2016-Dec2022.csv";
    
    std::cout << "Loading dataset..." << std::endl;
    std::vector<WeatherRecord> dataset = WeatherParser::parseCSV(datasetPath);

    if (!dataset.empty()) {
        std::cout << "\nSample Record [0]:" << std::endl;
        std::cout << "ID: " << dataset[0].eventId << std::endl;
        std::cout << "Type: " << dataset[0].type << std::endl;
        std::cout << "State: " << dataset[0].state << std::endl;
        std::cout << "Precipitation: " << dataset[0].precipitation << std::endl;
    }

    return 0;
}