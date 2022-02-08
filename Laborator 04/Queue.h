#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
	Item elem;
	struct QueueNode *next;
} QueueNode;

typedef QueueNode TcelQ;
typedef QueueNode *ACelQ;

typedef struct Queue
{
	QueueNode *front;
	QueueNode *rear;
	long size;
} Queue;

typedef Queue TCoada;
typedef Queue *AQ;

Queue *createQueue(void)
{
	// TODO: Cerinta 2
	AQ coada;
	coada = malloc(sizeof(Queue));
	coada->front = NULL;
	coada->rear = NULL;
	coada->size = 0;
	return coada;
}

int isQueueEmpty(Queue *q)
{
	// TODO: Cerinta 2
	if (q == NULL)
		return 1;
	else if (q->front == NULL && q->rear == NULL && q->size == 0)
		return 1;
	return 0;
}

void enqueue(Queue *q, Item elem)
{
	// TODO: Cerinta 2
	ACelQ new_node;
	new_node = malloc(sizeof(QueueNode));
	if (isQueueEmpty(q) == 1) //inseamna ca stiva era goala si adaugam un element in ea(caz in care si rear si front la nodul nou creat)
	{
		new_node->elem = elem;
		new_node->next = NULL;
		q->front = new_node;
		q->rear = new_node;
		q->size++;
	}
	else
	{
		new_node->elem = elem;
		new_node->next = NULL;
		q->rear->next = new_node;
		q->rear = new_node;
		q->size++;
	}
}

Item front(Queue *q)
{
	// TODO: Cerinta 2
	return q->front->elem;
}

void dequeue(Queue *q)
{
	// TODO: Cerinta 2
	if (isQueueEmpty(q) == 1)
		return;
	else
	{
		if (q->rear == q->front)
		{
			ACelQ temp=q->front;
			q->rear=q->front=NULL;
			q->size--;
			free(temp);
		}
		else
		{
			ACelQ temp;
			temp=q->front;
			q->front=q->front->next;
			free(temp);
			q->size--;	
		}
		
	}
}

void destroyQueue(Queue *q)
{
	// TODO: Cerinta 2
	ACelQ coada=q->front,temp;
	while(coada)
	{
		temp=coada;
		coada=coada->next;
		free(temp);
	}
	free(q);
}

#endif
