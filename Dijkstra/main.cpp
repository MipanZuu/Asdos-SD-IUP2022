/*
    adj matrix / Dijkstra
    input 
9 0
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/

#include <bits/stdc++.h>
using namespace std;

#define vert 10000
int dist[vert];
int prevs[vert];
int graph[vert][vert];
int vertices;
int source, destination;

int min_distance(int dist[], bool Q[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < vertices; v++)
		if (Q[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

void printPath(int previous[], int j)
{
	if (previous[j] == -1)
		return;
	printPath(previous, previous[j]);
	printf("%d ", j);
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int n, int previous[])
{
	printf("Vertex\t Distance\tPath");
	for (int i = 1; i < vertices; i++) {
		printf("\n%d -> %d \t\t %d\t\t%d ", source, i, dist[i], source);
		printPath(previous, i);
	}
}

void dijkstra(int graph[vert][vert], int src)
{
	int dist[vertices];
	bool Q[vertices] = { false };
	int parent[vertices] = { -1 };

	for (int i = 0; i < vertices; i++) {
		dist[i] = INT_MAX;
	}
	dist[src] = 0;

	for (int count = 0; count < vertices - 1; count++) {
		int u = min_distance(dist, Q);
		Q[u] = true;
		for (int v = 0; v < vertices; v++)
			if (!Q[v] && graph[u][v]
				&& dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	printSolution(dist, vertices, parent);
}

int main()
{
	cin >> vertices >> source;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        } 
    }

	dijkstra(graph, source);
	return 0;
}