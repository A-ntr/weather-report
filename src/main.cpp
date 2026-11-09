#include <iostream>
#include <string>
#include <unordered_set>
#include "WeatherParser.h"
#include "WeatherRecord.h"
#include "WeatherComparators.h"
#include "Heap.h"

int safeStoi(const string& s) {
    try { return s.empty() ? 0 : stoi(s);} catch (...) {return 0;}
}

bool verifyState(const string& str) {
    if (str == "_") return true;
    if (str.size() != 2) return false;

    unordered_set<std::string> stateSet{"AL", "AK", "AZ", "AR",
        "CA", "CO", "CT", "DE", "FL", "GA", "HI", "ID",
        "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD",
        "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV",
        "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK",
        "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT",
        "VT", "VA", "WA", "WV", "WI", "WY"};

    return stateSet.find(str) != stateSet.end();
}

bool verifyCondition(const string& str) {
    unordered_set<std::string> conditionSet{"Cold", "Fog",
        "Hail", "Rain", "Snow", "Storm", "Precipitation"};

    return conditionSet.find(str) != conditionSet.end() || str == "_";
}

bool verifySeverity(const string& str) {
    unordered_set<std::string> conditionSet{
        "Light", "Moderate", "Heavy", "Severe", "UNK"};

    return conditionSet.find(str) != conditionSet.end() || str == "_";
}


int main() {

    std::string header = "======================================="
                         "\n           WEATHER REPORT CLI"
                         "\n=======================================";
    std::cout << header << std::endl;

    //user input prompts
    std::cout << "If you don't want a filter, enter just an underscore (_)" << std::endl;

    std::string state;
    std::cout << "1. Filter by State (e.g., FL):";
    std::cin >> state;
    if (!verifyState(state)) {
        std::cout << "Invalid state, please try again" << std::endl;
        return 1;
    }

    std::cout << "2. Filter by Severity: ";
    std::string severity;
    std::cin >> severity;
    if (!verifyCondition(severity)) {
        std::cout << "Invalid severity, please try again" << std::endl;
        return 1;
    }

    std::cout << "3. Filter by Type: ";
    std::string type;
    std::cin >> type;
    if (!verifyCondition(type)) {
        std::cout << "Invalid type, please try again" << std::endl;
        return 1;
    }

    std::cout << "4. Enter Top-K Quantity (greater than 0): ";
    string topKStr;
    std::cin >> topKStr;
    int topK = safeStoi(topKStr);
    if (topK == 0) {
        std::cout << "Invalid Top-K Quantity, please try again" << std::endl;
        return 1;
    }

    std::cout << "5. Select Algorithm:\n\t[1] Quick Sort"
                 "\n\t[2] Heap Sort\n\nChoice: ";
    std::string choice;
    std::cin >> choice;

    std::cout << state << std::endl;
    std::cout << severity << std::endl;
    std::cout << type << std::endl;
    std::cout << topKStr << std::endl;
    std::cout << choice << std::endl;

    std::string datasetPath = "../data/WeatherEvents_Jan2016-Dec2022.csv";

    // to be used for filtering later
    std::vector<std::string> filterVec{state, type, severity};

    std::cout << "Loading dataset..." << std::endl;
    std::vector<WeatherRecord> dataset = WeatherParser::parseCSV(datasetPath, 100000);

    std::cout << "-- Results --\n"
            "Rank\tEventID\tType\tSeverity State\tPrecipitation\n"
            "----------------------------------------------------------" << std::endl;

    if (choice == "1") {
        // import Shuncheng's quicksort
    }
    else if (choice == "2") {
        heapSort(dataset, ComparePrecipitationDesc());
    }

    if (topK > dataset.size()) {
        topK = dataset.size();
    }
    for (int i = 0; i < topK; i++) {
        WeatherRecord& data = dataset[i];
        std::cout << i+1 << "\t" << data.toString() << std::endl;
    }

    return 0;
}
