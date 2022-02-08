#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>
#include <math.h>

/* We assume there is a defined primitive type Item. */
typedef struct
{
	int prior; // Item priority
	Item data; // Item d
} ItemType;

typedef struct heap
{
	long maxHeapSize; // capacity
	long size;		  // number of elements
	ItemType *elem;	  // array of elements
} PriQueue, *APriQueue;

PriQueue *makeQueue(int maxHeapSize)
{
	//TODO:
	APriQueue hp;
	hp = malloc(sizeof(PriQueue));
	hp->maxHeapSize = maxHeapSize;
	hp->size = 0;
	hp->elem = malloc(hp->maxHeapSize * sizeof(ItemType));
	return hp;
}

int getLeftChild(int i)
{
	//TODO:
	return 2 * i + 1;
}

int getRightChild(int i)
{
	//TODO:
	return 2 * i + 2;
}

int getParent(int i)
{
	//TODO:
	return (i - 1) / 2;
}

ItemType getMax(APriQueue h)
{
	//TODO:
	return h->elem[0];
}

void siftUp(APriQueue h, int idx)
{
	//TODO:
	while (idx > 0 && h->elem[idx].prior > h->elem[getParent(idx)].prior)
	{
		int aux = h->elem[getParent(idx)].prior;
		h->elem[getParent(idx)].prior = h->elem[idx].prior;
		h->elem[idx].prior = aux;
		idx = getParent(idx);
	}
}

void insert(PriQueue *h, ItemType x)
{
	//TODO:
	if (h->size == h->maxHeapSize)
	{
		h->maxHeapSize *= 2;
		h->elem = realloc(h->elem, h->maxHeapSize * sizeof(ItemType));
	}
	h->elem[h->size] = x;
	siftUp(h, h->size);
	h->size++;
}

void siftDown(APriQueue h, int idx)
{
	int j;
	while (2 * idx + 1 < h->size)
	{
		j = getLeftChild(idx);
		if (j + 1 < h->size && h->elem[j].prior < h->elem[j + 1].prior)
			j++;
		if (h->elem[idx].prior > h->elem[j].prior)
			break;
		int aux = h->elem[idx].prior;
		h->elem[idx].prior = h->elem[j].prior;
		h->elem[j].prior = aux;
		idx = j;
	}
	//TODO:
}

void removeMax(APriQueue h)
{
	//TODO:
	h->elem[0] = h->elem[h->size - 1];
	h->size--;
	siftDown(h, 0);
}

void freeQueue(APriQueue h)
{
	free(h->elem);
	free(h);
	// TODO:
}

#endif
