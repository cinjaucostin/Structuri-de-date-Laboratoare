/*
*	Created by Nan Mihai on 20.04.2021
*	Copyright (c) 2021 Nan Mihai. All rights reserved.
*	Laborator 7 - Structuri de date
*	Grupa 313CD
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2020-2021, Seria CD
*/
#include <stdio.h>
#include <stdlib.h>

typedef int T;

typedef struct node {
	T value;
	int height;
	struct node *left, *right;
} *Tree;

Tree createTree(T);
int maximum(int, int);
int height(Tree);
int balancedFactor(Tree);
void updateHeight(Tree);
Tree leftRotation(Tree);
Tree rightRotation(Tree);
Tree insert(Tree, T);
Tree freeTree(Tree);
