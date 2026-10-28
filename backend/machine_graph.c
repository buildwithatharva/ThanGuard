#include "machine_graph.h"
void build_machine_graph(Graph *g) {
 int i;
 /* Five component chains with four links each: total 20 edges. */
 for(i=0;i<4;i++) graph_add_edge(g,i,i+1);
 for(i=5;i<9;i++) graph_add_edge(g,i,i+1);
 for(i=10;i<14;i++) graph_add_edge(g,i,i+1);
 for(i=15;i<19;i++) graph_add_edge(g,i,i+1);
 for(i=20;i<24;i++) graph_add_edge(g,i,i+1);
}
