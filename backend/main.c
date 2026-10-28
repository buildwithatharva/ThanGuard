#include <stdio.h>
#include "machine_data.h"
#include "graph.h"
#include "machine_graph.h"

static void clear_input(void){int ch;while((ch=getchar())!='\n'&&ch!=EOF){}}

static int bfs_is_reachable(const Graph *g, int src, int dest) {
 int visited[MAX_COMPONENTS] = {0};
 int queue[MAX_COMPONENTS];
 int head = 0, tail = 0;
 if (!g || src < 0 || dest < 0 || src >= g->numNodes || dest >= g->numNodes) return 0;
 if (src == dest) return 1;
 visited[src] = 1;
 queue[tail++] = src;
 while (head < tail) {
  int u = queue[head++];
  if (u == dest) return 1;
  for (int v = 0; v < g->numNodes; v++) {
   if (g->adj[u][v] && !visited[v]) {
    visited[v] = 1;
    queue[tail++] = v;
   }
  }
 }
 return 0;
}

int main(void){
 Component c[MAX_COMPONENTS];int count,choice,id,index;Graph *g;
 count=load_sample_components(c,MAX_COMPONENTS);g=graph_create(count);
 if(!g){puts("Could not create graph.");return 1;}build_machine_graph(g);
 for(;;){
  printf("\n========== THANGUARD ==========\n");
  printf("1. View machine components\n2. Analyze component risk\n3. View dependency graph\n4. What-If failure simulation (BFS)\n5. Run quick self-test\n0. Exit\nChoose: ");
  if(scanf("%d",&choice)!=1){clear_input();puts("Enter a number.");continue;}
  clear_input();
  if(choice==0)break;
  switch(choice){
   case 1: print_component_table(c,count);break;
   case 2:
    assess_risk(c,count);print_component_table(c,count);
    puts("\nRisk rule: temperature >=75C adds 25; >=90C adds 50. Vibration >=5 adds 25; >=7 adds 50.");
    break;
   case 3: graph_print(g,c);break;
   case 4:
    printf("\n[What-If Mode] Enter component ID to simulate failure (1-%d): ", count);
    if(scanf("%d",&id)!=1){clear_input();puts("Invalid input. Please enter a valid number.");break;}
    clear_input();
    index=find_component_index_by_id(c,count,id);
    if(index<0)printf("Unknown component ID %d. Valid range is 1 to %d.\n", id, count);
    else graph_bfs_failure(g,index,c);
    break;
   case 5:
    printf("\n========== ThanGuard Self-Test ==========\n");
    printf("Components count (25): %s (%d)\n", count==25?"PASS":"FAIL", count);
    printf("Graph nodes (25):      %s (%d)\n", g->numNodes==25?"PASS":"FAIL", g->numNodes);
    printf("Graph edges (20):      %s (%d)\n", g->numEdges==20?"PASS":"FAIL", g->numEdges);
    printf("Duplicate-edge reject: %s\n", graph_add_edge(g,0,1)==0?"PASS":"FAIL");
    printf("Unknown ID rejection:  %s\n", find_component_index_by_id(c,count,99)==-1?"PASS":"FAIL");
    printf("BFS Motor 1 -> Bearing 1: %s\n",
      bfs_is_reachable(g, IDX_MOTOR_1, IDX_BEARING_1) ? "PASS" : "FAIL");
    printf("BFS Gear 5  -> Bearing 5: %s\n",
      bfs_is_reachable(g, IDX_GEAR_5, IDX_BEARING_5) ? "PASS" : "FAIL");
    break;
   default: puts("Choose an option from the menu.");
  }
 }
 graph_free(g);puts("ThanGuard closed.");return 0;
}
