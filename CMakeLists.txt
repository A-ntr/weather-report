cmake_minimum_required(VERSION 3.14)
project(WeatherReport VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# Core Executable
add_executable(Weather_Report ${SOURCES} src/main.cpp)

# Include Catch2 via FetchContent for testing
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # Or target version
)
FetchContent_MakeAvailable(Catch2)

# Enable testing target
enable_testing()
add_executable(tests test/test.cpp ${SOURCES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)