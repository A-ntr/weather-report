#include <catch2/catch_test_macros.hpp>
#include "Heap.h"
#include "Quick.h"
#include "WeatherRecord.h"
#include "WeatherComparators.h"
#include "WeatherParser.h"
#include <iostream>
#include <sstream>
/*
Heap testing
*/
// Test Case 1
TEST_CASE("ascending (max) heapifyDown on vector of integers", "[heapifyDown][int]") {
  vector<int> arr = {1, 3, 2, 4, 0};
  vector<int> expected = {1, 0, 2, 4, 3};
  heapifyDown(arr, arr.size(), 1, greater<int>());

  REQUIRE(arr == expected);
}

// Test Case 2
TEST_CASE("descending (min) heapifyDown on vector of integers", "[heapifyDown][int]") {
  vector<int> arr = {1, 3, 2, 4, 0};
  vector<int> expected = {1, 4, 2, 3, 0};
  heapifyDown(arr, arr.size(), 1);

  REQUIRE(arr == expected);
}

// Test Case 3
TEST_CASE("ascending (max) heapSort on vector of integers", "[heapSort][int]") {
  vector<int> arr = {1, 3, 2, 4, 0};
  vector<int> expected = {0, 1, 2, 3, 4};
  heapSort(arr);

  REQUIRE(arr == expected);
}

// Test Case 4
TEST_CASE("descending (min) heapSort on vector of integers", "[heapSort][int]") {
  vector<int> arr = {1, 3, 2, 4, 0};
  vector<int> expected = {4, 3, 2, 1, 0};
  heapSort(arr, std::greater<int>());

  REQUIRE(arr == expected);
}

/*
Quick testing
*/
// Test Case 5
TEST_CASE("ascending (max) partition on vector of integers", "[partition][int]") {
  vector<int> arr = {1, 3, 2, 4, 0};
  vector<int> expected = {0, 1, 2, 4, 3};
  partition(arr, 0, arr.size() - 1);

  REQUIRE(arr == expected);
}

// Test Case 6
TEST_CASE("descending (min) partition on vector of integers", "[partition][int]") {
  vector<int> arr = {1, 3, 2, 4, 0};
  vector<int> expected = {4, 3, 2, 1, 0};
  partition(arr, 0, arr.size() - 1, std::greater<int>());

  REQUIRE(arr == expected);
}

// Test Case 7
TEST_CASE("ascending (max) quickSort on vector of integers", "[quickSort][int]") {
  vector<int> arr = {1, 3, 2, 4, 0};
  vector<int> expected = {0, 1, 2, 3, 4};
  quickSort(arr);

  REQUIRE(arr == expected);
}

// Test Case 8
TEST_CASE("descending (min) quickSort on vector of integers", "[quickSort][int]") {
  vector<int> arr = {1, 3, 2, 4, 0};
  vector<int> expected = {4, 3, 2, 1, 0};
  quickSort(arr, std::greater<int>());

  REQUIRE(arr == expected);
}

/*
WeatherParser testing
*/
// Test Case 9: parseCSV correct path
TEST_CASE("WeatherParser::parseCSV on dataset in data correct path", "[parseCSV][WeatherParser]") {
  stringstream buffer;
  streambuf* prev = cout.rdbuf(buffer.rdbuf());
  std::string datasetPath = "./data/WeatherEvents_Jan2016-Dec2022.csv";
  
  std::vector<WeatherRecord> dataset = WeatherParser::parseCSV(datasetPath);
  cout.rdbuf(prev);

  REQUIRE(buffer.str() == "Successfully parsed 100000 records.\n");
}

// Test Case 10: parseCSV wrong path
TEST_CASE("WeatherParser::parseCSV on dataset in data wrong path", "[parseCSV][WeatherParser]") {
  stringstream buffer;
  streambuf* prev = cerr.rdbuf(buffer.rdbuf());
  std::string datasetPath = "./dats/WeatherEvents_Jan2016-Dec2022.csv";
  
  std::vector<WeatherRecord> dataset = WeatherParser::parseCSV(datasetPath);
  cerr.rdbuf(prev);
  std::string expected = "Error: Unable to open file at " + datasetPath + "\n";
  REQUIRE(buffer.str() == expected);
}

/*
heapSort testing
*/
// Test Case 11
TEST_CASE("ascending (max) heapSort on vector of WeatherRecord precipitation", "[heapSort][WeatherRecord]") {
  std::string datasetPath = "./data/WeatherEvents_Jan2016-Dec2022.csv";
  
  std::vector<WeatherRecord> dataset = WeatherParser::parseCSV(datasetPath);

  // Testing on first 1000 reports
  vector<WeatherRecord> records(dataset.begin(), dataset.begin()+1000);

  heapSort(records, ComparePrecipitationAsc());

  for (size_t i = 0; i < records.size()-1; i++) {
    REQUIRE(records[i].precipitation <= records[i+1].precipitation);
  }
  
}

/*
quickSort testing
*/
// Test Case 12
TEST_CASE("ascending (max) quickSort on vector of WeatherRecord precipitation", "[quickSort][WeatherRecord]") {
  std::string datasetPath = "./data/WeatherEvents_Jan2016-Dec2022.csv";
  
  std::vector<WeatherRecord> dataset = WeatherParser::parseCSV(datasetPath);

  // Testing on first 1000 reports
  vector<WeatherRecord> records(dataset.begin(), dataset.begin()+1000);

  quickSort(records, ComparePrecipitationAsc());

  for (size_t i = 0; i < records.size()-1; i++) {
    REQUIRE(records[i].precipitation <= records[i+1].precipitation);
  }
  
}