# ThanGuard Project Scope

## Problem
Machine components are connected by dependencies. A fault in one component may affect downstream components. Operators need a simple way to inspect component condition and understand these dependency paths.

## Proposed solution
ThanGuard uses a directed graph to model component dependencies, simple threshold rules to assign a risk score, and Breadth-First Search (BFS) to show downstream components that may be affected by a simulated failure.

## Data Structures and Algorithms
- Arrays and structures: store component data
- Directed adjacency matrix: represent dependencies
- BFS with a queue: trace reachable downstream components
- Rule-based scoring: illustrative risk categorization

## Limitation
Sample data and thresholds are for demonstration only. Real-world deployment requires validated machine-specific limits and real sensor measurements.
