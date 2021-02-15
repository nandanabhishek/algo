#include<stdio.h>

#define INFINITY 9999
#define MAX 15

void dijkstra(int G[MAX][MAX], int n, int startnode);

int main()
{
    int n; // n = number of vertices in Graph
	int G[MAX][MAX];
	int u; // u = starting node

	printf("\n Enter total number of vertices in Graph : ");
	scanf("%d",&n);

	printf("\n Enter the adjacency matrix for the graph :\n");
	for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

	printf("\n Enter the starting node : ");
	scanf("%d",&u);

	dijkstra(G, n, u); // calling the function dijkstra

	return 0;
}



// function for executing Dijkstra Algorithm using Greedy Technique
void dijkstra(int G[MAX][MAX], int n, int start_node)
{

	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, min_distance, next_node;

	//pred[] stores the predecessor of each node
	//count gives the number of nodes visited so far

	//creating the cost matrix
	for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }

	//initialize pred[],distance[] and visited[]
	for(int i=0;i<n;i++) {
		distance[i] = cost[start_node][i];
		pred[i] = start_node;
		visited[i] = 0;
	}

	distance[start_node] = 0;
	visited[start_node] = 1;
	count = 1;

	while(count < n-1)
	{
		min_distance = INFINITY;

		// next_node gives the node at minimum distance
		for(int i=0; i<n; i++)
			if( distance[i] < min_distance && !visited[i] ) {
				min_distance = distance[i];
				next_node = i;
			}

			// check if a shorter path exists through next_node
			visited[next_node] = 1;
			for(int i=0; i<n; i++)
				if( !visited[i] ) {
                    if (min_distance + cost[next_node][i] < distance[i]) {
                        distance[i] = min_distance + cost[next_node][i];
                        pred[i] = next_node;
                    }
                }
		count++;
	}

	//printing the path and distance of each node from the starting node(or Source node)
	for(int i=0; i<n; i++) {
        if (i != start_node) {
            // all distances are from the Source Node
            printf("\n Distance of Node-%d = %d", i, distance[i]);
            printf("\n Path = %d", i);

            int j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != start_node);

            printf("\n");
        }
    }
}
