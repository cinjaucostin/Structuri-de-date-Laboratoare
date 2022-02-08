/*
*	Created by Nan Mihai on 04.04.2020
*	Copyright (c) 2020 Nan Mihai. All rights reserved.
*	Laborator - Proiectarea algoritmilor (Grafuri)
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2019-2020, Seria CD
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"

void dijkstra(Graph graf, int sursa)
{
	int *d = calloc(graf->V + 1, sizeof(int));
	int *p = calloc(graf->V + 1, sizeof(int));
	MinHeap coada_min;
	graf->visited[sursa] = 1;
	for (int i = 0; i != sursa && i < graf->V; i++)
	{
		if (isArc(graf, sursa, i))
		{
		}
	}
}

int main()
{
	freopen("test1.in", "r", stdin);
	int V, type, i, x, y, M;
	scanf("%d %d", &V, &type);
	Graph graph = initGraph(V, type);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		graph = insertEdge(graph, x, y, 0);
	}
	printGraph(graph);
	drawGraph(graph, "graph1.dot");
	graph = freeGraph(graph);
	return 0;
}