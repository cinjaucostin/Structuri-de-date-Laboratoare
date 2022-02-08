#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
	Item elem;
	struct StackNode *next;
} StackNode;

typedef StackNode TCelSt;  // Redenumirea unui nod la notatiile din curs
typedef StackNode *ACelSt; // Redenumirea unui pointer la nod la notatiile din curs

typedef struct Stack
{
	StackNode *head; // Varful stivei
	long size;		 // Numarul de elemente din stiva
} Stack;

typedef Stack TStiva; // Redenumirea stivei la notatiile din curs
typedef Stack *ASt;	  //  // Redenumirea unui pointer la stiva la notatiile din curs

Stack *createStack(void)
{
	// TODO: Cerinta 1
	ASt stiva;
	stiva = malloc(sizeof(Stack));
	stiva->head = NULL;
	stiva->size = 0;
	return stiva;
}

int isStackEmpty(Stack *stack)
{
	// TODO: Cerinta 1
	if (stack == NULL)
		return 1;
	else if (stack->head == NULL && stack->size == 0)
		return 1;
	return 0;
}

void push(Stack *stack, Item elem)
{
	// TODO: Cerinta 1
	ACelSt new_node;
	new_node = malloc(sizeof(StackNode));
	new_node->next = stack->head;
	new_node->elem = elem;
	stack->head = new_node;
	stack->size = stack->size + 1;
}

Item top(Stack *stack)
{
	// TODO: Cerinta 1
	Item varf;
	varf = stack->head->elem;
	return varf;
}

void pop(Stack *stack)
{
	// TODO: Cerinta 1
	if (isStackEmpty(stack))
		return;
	else
	{
		ACelSt temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
		stack->size--;
	}
}

void destroyStack(Stack *stack)
{
	// TODO: Cerinta 1
	ACelSt stiva = stack->head, temp;
	while (stiva != NULL)
	{
		temp = stiva;
		stiva = stiva->next;
		free(temp);
	}
	free(stack);
}

#endif
