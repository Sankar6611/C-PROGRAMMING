#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode {
    int v;
    struct AdjNode* next;
} AdjNode;

typedef struct {
    int V;
    AdjNode** head;
} Graph;

AdjNode* newAdj(int v){
    AdjNode* n=(AdjNode*)malloc(sizeof(AdjNode));
    n->v=v; n->next=NULL; return n;
}

Graph* createGraph(int V){
    Graph* g=(Graph*)malloc(sizeof(Graph));
    g->V=V; g->head=(AdjNode**)malloc(V*sizeof(AdjNode*));
    for(int i=0;i<V;i++) g->head[i]=NULL;
    return g;
}

void addEdge(Graph* g, int u, int v){
    AdjNode* a=newAdj(v); a->next=g->head[u]; g->head[u]=a;
    AdjNode* b=newAdj(u); b->next=g->head[v]; g->head[v]=b;
}

void BFS(Graph* g, int s){
    int *vis=(int*)calloc(g->V,sizeof(int));
    int *q=(int*)malloc(g->V*sizeof(int)); int f=0,r=0;
    vis[s]=1; q[r++]=s;
    printf("BFS: ");
    while(f<r){
        int u=q[f++]; printf("%d ", u);
        for(AdjNode* p=g->head[u]; p; p=p->next){
            if(!vis[p->v]){ vis[p->v]=1; q[r++]=p->v; }
        }
    }
    printf("\n"); free(vis); free(q);
}

void DFS_util(Graph* g, int u, int vis[]){
    vis[u]=1; printf("%d ", u);
    for(AdjNode* p=g->head[u]; p; p=p->next)
        if(!vis[p->v]) DFS_util(g,p->v,vis);
}

void DFS(Graph* g, int s){
    int *vis=(int*)calloc(g->V,sizeof(int));
    printf("DFS: ");
    DFS_util(g,s,vis);
    printf("\n"); free(vis);
}

int main(){
    Graph* g=createGraph(5);
    addEdge(g,0,1); addEdge(g,0,2); addEdge(g,1,3); addEdge(g,2,4);
    BFS(g,0);
    DFS(g,0);
    return 0;
}
