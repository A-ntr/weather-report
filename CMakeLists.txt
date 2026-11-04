cmake_minimum_required(VERSION 3.14)
project(WeatherReport VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Catch2 via FetchContent (declared before the test target that links it)
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Core library: non-main sources compiled once, shared by app and tests.
# Sources are listed explicitly (not GLOB) to reliably keep src/main.cpp out.
add_library(weather_core OBJECT
  src/WeatherParser.cpp
)
target_include_directories(weather_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Application executable: core objects + main entry point.
add_executable(Weather_Report
  src/main.cpp
)
target_link_libraries(Weather_Report PRIVATE weather_core)

# Test executable: core objects + tests, Catch2 provides main.
add_executable(tests
  test/test.cpp
)
target_link_libraries(tests PRIVATE weather_core Catch2::Catch2WithMain)
