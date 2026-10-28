#include <stdio.h>
#include "machine_data.h"
#include "graph.h"
#include "machine_graph.h"

static void clear_input(void){int ch;while((ch=getchar())!='\n'&&ch!=EOF){}}
int main(void){
 Component c[MAX_COMPONENTS];int count,choice,id,index;Graph *g;
 count=load_sample_components(c,MAX_COMPONENTS);g=graph_create(count);
 if(!g){puts("Could not create graph.");return 1;}build_machine_graph(g);
 for(;;){
  printf("\n========== THANGUARD ==========\n");
  printf("1. View machine components\n2. Analyze component risk\n3. View dependency graph\n4. Simulate component failure (BFS)\n5. Run quick self-test\n0. Exit\nChoose: ");
  if(scanf("%d",&choice)!=1){clear_input();puts("Enter a number.");continue;}
  if(choice==0)break;
  switch(choice){
   case 1: print_component_table(c,count);break;
   case 2:
    assess_risk(c,count);print_component_table(c,count);
    puts("\nRisk rule: temperature >=75C adds 25; >=90C adds 50. Vibration >=5 adds 25; >=7 adds 50.");
    break;
   case 3: graph_print(g,c);break;
   case 4:
    printf("Enter component ID (1-25): ");
    if(scanf("%d",&id)!=1){clear_input();puts("Invalid input.");break;}
    index=find_component_index_by_id(c,count,id);
    if(index<0)puts("Unknown component ID.");else graph_bfs_failure(g,index,c);
    break;
   case 5:
    printf("Components: %s; Graph nodes: %d; Graph edges: %d\n",
      count==25?"PASS":"FAIL",g->numNodes,g->numEdges);
    printf("Duplicate-edge rejection: %s\n",graph_add_edge(g,0,1)==0?"PASS":"FAIL");
    printf("Unknown ID rejection: %s\n",find_component_index_by_id(c,count,99)==-1?"PASS":"FAIL");
    break;
   default: puts("Choose an option from the menu.");
  }
 }
 graph_free(g);puts("ThanGuard closed.");return 0;
}
