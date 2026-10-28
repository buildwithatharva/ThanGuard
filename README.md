# ThanGuard — C Mini Project

ThanGuard is a student mini-project that demonstrates rule-based component risk assessment and machine-component dependency analysis.

## Features
- 25 sample machine components
- Directed dependency graph using an adjacency matrix
- Risk scoring from example temperature and vibration values
- BFS failure-propagation simulation
- Input validation and quick self-test

## Requirements
A C compiler such as GCC. No external libraries are required.

## Compile (run from the `backend` folder)
```bash
gcc main.c machine_data.c graph.c machine_graph.c -o thanguard
```

Run on Windows:
```bash
thanguard.exe
```
Run on Linux/macOS:
```bash
./thanguard
```

## Important limitation
This is an educational simulation using sample values and illustrative thresholds. It does not connect to real sensors and does not provide validated industrial failure predictions.
