#include <catch2/catch_test_macros.hpp>
#include "Heap.h"
#include "WeatherRecord.h"
#include "WeatherComparators.h"


TEST_CASE("min heapifyDown on vector of integers", "[heapifyDown][int]") {
  vector<int> arr = {1, 3, 2, 4, 0};
  vector<int> expected = {1, 0, 2, 4, 3};
  heapifyDown(arr, arr.size(), 1);

  REQUIRE(arr == expected);
  
}