#include <stdio.h>


// function for Bellman Ford Algorithm
int Bellman_Ford(int G[20][20] , int V, int E, int edge[20][2])
{
    int u, v;
    int S; // S = Source Vertex

    int distance[20], parent[20], flag=1;

    for(int i=0; i<V; i++) {
        distance[i] = 1000, parent[i] = -1;
    }
    printf("\n Enter source Vertex : ");
    scanf("%d",&S);
    printf("\n");

    distance[S-1] = 0;
    for(int i=0; i<V-1; i++) {
        for(int k=0; k<E; k++) {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v] , parent[v]=u ;
        }
    }
    for(int k=0; k<E; k++) {
        u = edge[k][0] , v = edge[k][1] ;
        if(distance[u]+G[u][v] < distance[v])
            flag = 0 ;
    }
    if(flag) {
        printf("\n Distance of each Vertex from the source Vertex is given as :-\n");
        for (int i = 0; i < V; i++) {
            printf(" Vertex %d -->  cost = %d   \tparent = %d\n", i + 1, distance[i], parent[i] + 1);
        }
    }
    return flag;
}


// main function
int main()
{
    int V; // V = No. of Vertices in Graph
    int edge[20][2], G[20][20], k=0;

    printf("\n BELLMAN FORD\n");

    printf("\n Enter total number of vertices : ");
    scanf("%d",&V);

    printf("\n Enter the graph in Adjacency Matrix form :\n");
    for(int i=0;i<V;i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
            if (G[i][j] != 0)
                edge[k][0] = i, edge[k++][1] = j;
        }
    }

    if(Bellman_Ford(G, V, k, edge))
        printf("\n -- No negative weight cycle is present in Graph ! --\n");
    else
        printf("\n -- Negative weight cycle exists in Graph ! --\n");
    return 0;
}
