# Weather Report: Top-k Weather Anomaly Query Engine

A C++ command-line application that ingests, filters, and extracts top-k extreme weather anomalies from datasets with over 100,000 records. Built to compare the execution speed of custom sorting algorithms.

---

## Team Members

* **An Tran** — Heap Sort, Benchmarking, Testing
* **Azan Zaman** — CLI Front-End, Testing
* **Shuncheng Liang** — Quick Sort, Testing

---

## Problem & Motivation

### Problem Statement
Analyzing localized extreme weather events across large historical datasets requires quick, ranked retrieval of weather observations based on severity under custom filters.

### Motivation
Extreme weather events affect agriculture, flight logistics, emergency dispatch services, and public safety. Because historical weather datasets contain millions of observations, linear scans or full array sorts are computationally expensive. By building and benchmarking custom **Heap Sort** and **Quick Sort** algorithms from scratch, this engine evaluates selection mechanisms to power real-time analytical dashboards.

---

## Key Features

* **Data Ingestion**: Parses and loads over 100,000 records into memory.
* **Filtering**: Filter records by state, metric type (rain, snow, fog), severity level, and region.
* **Algorithm Comparison**: Select between custom Heap Sort and Quick Sort implementations.
* **Latency Benchmarking**: Measures execution time using `std::chrono::steady_clock`.
* **Tabular Results**: Displays ranked top-k outputs alongside precise benchmark metrics.

---

## Dataset & Schema

* **Dataset**: [US Weather Events (2016–2022)](https://www.kaggle.com/datasets/sobhanmoosavi/us-weather-events) by Sobhan Moosavi.
* **Data Structure**: `std::vector<WeatherRecord>` storing normalized weather attributes.

### Schema Attributes

| Field Name | Data Type | Description |
| :--- | :--- | :--- |
| `EventID` | `std::string` | Unique event identifier |
| `Type` | `std::string` | Event category (*Rain, Fog, Snow, Cold, etc.*) |
| `Severity` | `std::string` | Severity rating (*Light, Moderate, Severe*) |
| `StartTime` / `EndTime` | `std::string` | Timestamps of event duration |
| `Location` | `std::string` | City name |
| `State` | `std::string` | Two-letter US state code |
| `Precipitation` | `double` | Measured precipitation in inches |

---

## Tech Stack & Tools

* **Language**: C++17
* **Build System**: CMake & Ninja
* **Unit Testing**: Catch2 (v3)
* **Interface**: Interactive Command Line Interface (CLI)

---

## Technical Strategy

1. **In-Place Heap Sort**: Builds a Max-Heap over the vector using bottom-up `heapifyDown` in $O(N)$ time, followed by $O(N \log N)$ extraction to compute top-k orderings.
2. **In-Place Quick Sort**: Partitioning-based sorting algorithm operating in $O(N \log N)$ average-case time.
3. **Benchmarking**: Measures execution time with `std::chrono::steady_clock` to record query latency.

---

## Visuals & Usage Example

### CLI Execution Workflow

```text
=======================================
           WEATHER REPORT CLI          
=======================================
1. Filter by State (e.g., FL): FL
2. Filter by Severity/Type: Rain
3. Enter Top-K Quantity: 5
4. Select Algorithm:
   [1] Quick Sort
   [2] Heap Sort

Choice: 2

–- Results -–
Rank   EventID     Type   Severity   State   Precipitation
----------------------------------------------------------
1      W-10492     Rain   Severe     FL      4.85 in
2      W-84920     Rain   Severe     FL      4.12 in
3      W-30291     Rain   Moderate   FL      3.90 in
4      W-19284     Rain   Moderate   FL      3.45 in
5      W-48201     Rain   Light      FL      3.10 in

[Benchmark Output]
- Dataset Size: 100,000 records
- Heap Sort Latency: 7.6 ms
```

---

## Building & Running

### Build Project with CMake
```bash
# Create build directory
mkdir build && cd build

# Configure and compile using CMake
cmake ..
cmake --build .
```

### Run Application
```bash
# Executable run
./Weather_Report
```

### Run Unit Tests
```bash
# Run test suite using CTest
ctest --output-on-failure
```

---

## References

* Moosavi, Sobhan, et al. *"US Weather Events (2016–2022)."* Kaggle Datasets, 2022.
