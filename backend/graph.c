#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
Graph *graph_create(int n) {
 int i; Graph *g=(Graph*)malloc(sizeof(Graph)); if(!g)return NULL;
 g->numNodes=n;g->numEdges=0;g->adj=(int**)malloc(n*sizeof(int*));
 if(!g->adj){free(g);return NULL;}
 for(i=0;i<n;i++){g->adj[i]=(int*)calloc(n,sizeof(int));if(!g->adj[i]){
  while(i>0) { free(g->adj[--i]); }
  free(g->adj); free(g); return NULL;
 }}
 return g;
}
void graph_free(Graph *g){int i;if(!g)return;for(i=0;i<g->numNodes;i++)free(g->adj[i]);free(g->adj);free(g);}
int graph_add_edge(Graph *g,int a,int b){
 if(!g||a<0||b<0||a>=g->numNodes||b>=g->numNodes||a==b||g->adj[a][b])return 0;
 g->adj[a][b]=1;g->numEdges++;return 1;
}
int graph_has_edge(const Graph *g,int a,int b){return g&&a>=0&&b>=0&&a<g->numNodes&&b<g->numNodes?g->adj[a][b]:0;}
int graph_out_degree(const Graph *g,int n){int j,d=0;if(!g||n<0||n>=g->numNodes)return -1;for(j=0;j<g->numNodes;j++)d+=g->adj[n][j];return d;}
void graph_print(const Graph *g,const Component c[]){
 int i,j;printf("\nDependency graph (%d nodes, %d directed links):\n",g->numNodes,g->numEdges);
 for(i=0;i<g->numNodes;i++)for(j=0;j<g->numNodes;j++)if(g->adj[i][j])printf("  %s -> %s\n",c[i].name,c[j].name);
}
void graph_bfs_failure(const Graph *g,int start,const Component c[]){
 int *seen,*q,head=0,tail=0,i,v,found=0;
 if(!g||start<0||start>=g->numNodes)return;
 seen=(int*)calloc(g->numNodes,sizeof(int));q=(int*)malloc(g->numNodes*sizeof(int));
 if(!seen||!q){free(seen);free(q);puts("Memory allocation failed.");return;}
 seen[start]=1;q[tail++]=start;
 printf("\nFailure propagation starting at %s:\n",c[start].name);
 while(head<tail){v=q[head++];for(i=0;i<g->numNodes;i++)if(g->adj[v][i]&&!seen[i]){
  seen[i]=1;q[tail++]=i;printf("  Potentially affected: %s\n",c[i].name);found=1;}}
 if(!found)printf("  No downstream components are connected.\n");
 puts("Note: this is a dependency simulation, not a confirmed real-world failure.");
 free(seen);free(q);
}
