# TSP Routing Algorithm

A high-performance C++ solution for the Traveling Salesman Problem, designed for ocean shipping and urban delivery route optimization.

## Overview

This project implements three distinct algorithms to solve TSP across different graph sizes, from small toy datasets to large-scale real-world networks with geographic coordinates.

## Key Features

- **Three Algorithm Implementations**
  - Backtracking with pruning (optimal for small graphs)
  - Triangular approximation heuristic (balanced approach)
  - Nearest neighbor with 2-opt optimization (fast for large graphs)

- **Multiple Graph Support**
  - Toy graphs (shipping, stadiums, tourism)
  - Real-world graphs with geographic coordinates
  - Fully connected graphs (25-900 nodes)

- **Advanced Optimization**
  - Haversine formula for accurate geographic distances
  - 2-opt local search optimization
  - Performance timing and metrics

## Quick Start

```bash
# Build
mkdir build && cd build
cmake ..
make

# Run
./DA_TSP
```

## Architecture

```
Core Components:
├── Graph.cpp/h              # Node and Edge data structures
├── GraphInterface.cpp/h     # Algorithm implementations
├── Parser.cpp/h             # CSV parsing for different formats
├── Menu.cpp/h               # Interactive CLI
└── MutablePriorityQueue.h   # Priority queue for algorithms
```

## Algorithm Comparison

| Algorithm | Complexity | Optimality | Best Use Case |
|-----------|-----------|-----------|---------------|
| Backtracking | O(n!) | Optimal | < 15 nodes |
| Triangular Approx | O(n²) | Approximate | 15-100 nodes |
| Nearest Neighbor + 2-opt | O(n²) | Approximate | 100+ nodes |

## Dataset Format

**Toy Graphs** - Simple edge list:
```csv
source,dest,distance
0,1,150.5
1,2,200.3
```

**Real-World Graphs** - Separate node and edge files:
```csv
# nodes.csv
id,longitude,latitude
0,-8.6291,41.1579

# edges.csv
source,dest,distance
0,1,15420.5
```

## Example Output

```
| The heuristic found a distance of 15420.5 meters
| Total time elapsed: 0.0234 seconds
| The path is:
0 -> 3 -> 7 -> 2 -> 5 -> 1 -> 4 -> 6 -> 0
```

## Implementation Highlights

- **Haversine Distance**: Calculates great-circle distances for geographic coordinates
- **2-opt Optimization**: Iteratively improves tours by testing edge swaps
- **Memory Efficient**: Adjacency list representation with proper cleanup
- **Interactive Menu**: User-friendly CLI with input validation

## Technical Stack

- C++17
- CMake 3.26+
- Standard Template Library (STL)

## Authors

Eduardo Cunha, Luna Cunha, Rodrigo Araújo  
Design of Algorithms Course - FEUP

---

*This project demonstrates advanced algorithm design, optimization techniques, and practical problem-solving for logistics and route planning.*
