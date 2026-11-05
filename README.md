# WeatherReport - Extreme Weather Analytics Engine

## Prerequisites
* C++17 compatible compiler (`g++` or `clang++`)[cite: 1]
* CMake (v3.14+)

## Quickstart (Building & Running)
1. Clone the repository:
   ```bash
   git clone [https://github.com/YOUR-USERNAME/YOUR-REPO-NAME.git](https://github.com/YOUR-USERNAME/YOUR-REPO-NAME.git)
   cd YOUR-REPO-NAME
   
## Dataset Setup
1. Download the dataset from [Kaggle US Weather Events](https://www.kaggle.com/datasets/sobhanmoosavi/us-weather-events).
2. Unzip and place `US_WeatherEvents_2016-2022.csv` into the `data/` directory:
   `my-project/data/weather_data.csv`

   Project Title: Weather Report
Team Members: Azan Zaman, An Tran, Shuncheng Liang


Problem: 
Analyzing localized extreme weather events requires a list of weather observations ranked by severity across a very large dataset. We aim to design an efficient query engine capable of computing the top k extreme weather anomalies from a large-scale dataset under varying filtering conditions.
Motivation: 
Extreme weather occurrences are native to Florida, affecting agriculture, flight logistics, dispatch services, and our family and friends. With easier access to meaningful historical records, meteorologists can have a streamlined process of analysis, enabling regional planning and risk mitigation. Since historical weather data consists of millions of measurements and data points, naive linear searches or full array sorts require a significant amount of time. By evaluating the optimal algorithm for top-k selection, we directly impact the real-time analytical dashboards.
Features: 
Ingest and parse over 100,000 records into memory.
Working filter by state, metric (severity, type, region, etc.), and top k quantity.
Implement top k retrieval by using both algorithms then benchmark them.
Display query latency and the ranked tabular output.
Data: 
Dataset: US Weather Events (2016-2022)
Link: https://www.kaggle.com/datasets/sobhanmoosavi/us-weather-events 
Schema:
EventID (String): Unique identifier.
Type (String): Weather occurrence (Rain, fog, snow, cold…).
Severity (String): Light, Moderate, Severe.
StartTime / EndTime (String/Datetime): Event timestamps.
Location (String): City.
State (String): US State code.
Precipitation (Float): precipitation measurement in inches.
Tools: Programming languages or any tools/frameworks we will be using [0.25 point]
Language: C++
Testing: Catch2
Build System: CMake
Interface: CLI


Visuals: CLI
C:\Users\username\ProjectTwo> g++ sort.cpp -o run


=======================================
Program name
=======================================
Command 1: receives input. If valid then print follow up
Command 2:
…
Algorithm select: [1] quicksort [2] heapsort


After executing command will print
–Results–
Rank
1
2
3
4
5
…
Benchmark:
-quicksort: 6.7 ms
-heapsort: 7.6 ms 




Strategy: 
Data representation: a vector of WeatherRecord structs storing normalized data.
Algorithm 1: Custom In-Place Heap Sort.
Algorithm 2: Custom Quick Sort.
Benchmarking: std::chrono::steady_clock to measure CPU execution time.
Distribution of Responsibility and Roles: 
An Tran: heap sort, benchmarking, testing
Azan Zaman: front-end, testing
Shuncheng Liang: quick sort, testing
References:
Moosavi, S. US Weather Events (2016–2022), Kaggle Datasets.
