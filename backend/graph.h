#ifndef GRAPH_H
#define GRAPH_H
#include "machine_data.h"
typedef struct { int numNodes; int numEdges; int **adj; } Graph;
Graph *graph_create(int nodes);
void graph_free(Graph *g);
int graph_add_edge(Graph *g, int from, int to);
int graph_has_edge(const Graph *g, int from, int to);
int graph_out_degree(const Graph *g, int node);
void graph_print(const Graph *g, const Component c[]);
void graph_bfs_failure(const Graph *g, int start, const Component c[]);
#endif
