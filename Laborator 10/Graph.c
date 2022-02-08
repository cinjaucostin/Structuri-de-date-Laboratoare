#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
#include "Graph.h"

TGraphL *createGraphAdjList(int numberOfNodes)
{
	//TODO: 1
	TGraphL *graf;
	graf = malloc(sizeof(TGraphL));
	graf->adl = malloc(numberOfNodes * sizeof(ATNode));
	graf->nn = numberOfNodes;
	for (int i = 0; i < numberOfNodes; i++)
	{
		graf->adl[i] = malloc(sizeof(TNode));
		graf->adl[i] = NULL;
	}
	return graf;
}

void addEdgeList(TGraphL *graph, int v1, int v2)
{
	ATNode temp1, temp2;
	temp1 = malloc(sizeof(TNode));
	temp2 = malloc(sizeof(TNode));

	temp1->v = v2;
	temp1->c = 1;
	temp1->next = graph->adl[v1];

	temp2->v = v1;
	temp2->c = 1;
	temp2->next = graph->adl[v2];

	graph->adl[v1] = temp1;
	graph->adl[v2] = temp2;
	//TODO: 1
}

List *dfsIterative(TGraphL *graph, int s)
{
	//TODO: 2
	int u, *viz = calloc(graph->nn, sizeof(int));
	Stack *stiva = createStack();
	List *parcurgere;
	ATNode t;
	push(stiva, s);
	parcurgere = createList();
	while (!isStackEmpty(stiva))
	{
		u = top(stiva);
		pop(stiva);
		enqueue(parcurgere, u);
		if (viz[u] == 0)
		{
			viz[u] = 1;
			for (t = graph->adl[u]; t != NULL; t = t->next)
			{
				if (viz[t->v] == 0)
				{
					push(stiva, t->v);
				}
			}
		}
	}
	free(viz);
	return parcurgere;
}

void dfsRecHelper(TGraphL *graph, int *visited, List *path, int s)
{
	//TODO: 3
	ATNode t;
	visited[s] = 1;
	enqueue(path, s);
	for (t = graph->adl[s]; t != NULL; t = t->next)
	{
		if (visited[t->v] == 0)
			dfsRecHelper(graph, visited, path, t->v);
	}
}

List *dfsRecursive(TGraphL *graph, int s)
{
	List *path;
	int *visited = calloc(graph->nn, sizeof(int));
	path = createList();
	dfsRecHelper(graph, visited, path, s);
	return path;
	// TODO 3
}

void partial_tree(Graph g, int start)
{
	int u;
	List t;
	coada = createQueue();
	enqueue(coada,start);
	g->visited[start] = 1;
	while (!coada_goala(coada))
	{
		u = front(coada);
		dequeue(coada);
		for (t = g->adjLists[u]; t != NULL; t = t->next)
		{
			if (g->visited[t->v] == 0)
			{
				g->visited[t->v] = 1;
				g->parents[t->v]=u;
				add_edge(t->v,u);
				printf("Avem muchie de la %d la %d",u,t->v);
				enqueue(coada, t->v);
			}
		}
	}
}

void destroyGraphAdjList(TGraphL *graph)
{
	// TODO: 5
	for (int i = 0; i < graph->nn; i++)
	{
		removeNodeList(graph, graph->adl[i]->v);
		free(graph->adl[i]);
	}
	free(graph->adl);
	free(graph);
}

void removeEdgeList(TGraphL *graph, int v1, int v2)
{
	TNode *it = graph->adl[v1];
	TNode *prev = NULL;
	while (it != NULL && it->v != v2)
	{
		prev = it;
		it = it->next;
	}

	if (it == NULL)
		return;

	if (prev != NULL)
		prev->next = it->next;
	else
		graph->adl[v1] = it->next;
	free(it);

	it = graph->adl[v2];
	prev = NULL;
	while (it != NULL && it->v != v1)
	{
		prev = it;
		it = it->next;
	}
	if (it == NULL)
		return;
	if (prev != NULL)
		prev->next = it->next;
	else
		graph->adl[v2] = it->next;

	free(it);
}

void removeNodeList(TGraphL *graph, int v)
{
	for (int i = 0; i < graph->nn; i++)
	{
		removeEdgeList(graph, v, i);
	}
}
