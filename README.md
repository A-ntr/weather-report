# Weather Report: Top-$k$ Weather Anomaly Query Engine

A high-performance C++ command-line application built to ingest, filter, and extract top-k extreme weather event anomalies from large-scale meteorological datasets (>100,000 records). Designed to compare the execution speed of custom algorithm implementations.

---

## Team Members

* **An Tran** — Heap Sort, Benchmarking, Testing
* **Azan Zaman** — User Interface (CLI Front-End), Testing
* **Shuncheng Liang** — Quick Sort, Testing

---

## Problem & Motivation

### Problem Statement
Analyzing localized extreme weather events across massive historical datasets requires fast, ranked retrieval of weather observations based on severity metrics under customizable filtering conditions.

### Motivation
Extreme weather events significantly affect agriculture, flight logistics, emergency dispatch services, and public safety. Because historical weather datasets comprise millions of observations, naive linear scans or full array sorting are computationally expensive. By implementing and benchmarking custom **Heap Sort** and **Quick Sort** algorithms from scratch, this engine demonstrates optimal selection mechanisms to power real-time analytical dashboards.

---

## Key Features

* **High-Volume Data Ingestion**: Parses and loads over 100,000 records smoothly into memory.
* **Customizable Filtering**: Filter records dynamically by state, metric type (rain, snow, fog), severity level, and geographical region.
* **Algorithm Comparison**: Select between custom **Heap Sort** and custom **Quick Sort** implementations.
* **Latency Benchmarking**: Measures exact execution time using high-precision CPU timers (`std::chrono::steady_clock`).
* **Tabular Results**: Displays ranked top-$k$ outputs alongside precise benchmark metrics.

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

1. **In-Place Heap Sort**: Formulates a Max-Heap structure over the array using bottom-up `heapifyDown` in O(N) time, followed by O(N log N) extraction to compute top-k orderings.
2. **In-Place Quick Sort**: Partitioning-based algorithm designed for fast average-case sorting performance O(N log N).
3. **High-Resolution Benchmarking**: Wraps algorithm execution inside `std::chrono::steady_clock` invocations to measure sub-millisecond query latency.

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
