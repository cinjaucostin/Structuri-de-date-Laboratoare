/*
*	Created by Nan Mihai on 20.04.2021
*	Copyright (c) 2021 Nan Mihai. All rights reserved.
*	Laborator 7 - Structuri de date
*	Grupa 313CD
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2020-2021, Seria CD
*/
#include "avl.h"

Tree createTree(T value)
{
	Tree root = malloc(sizeof(struct node));
	root->value = value;
	root->left = NULL;
	root->right = NULL;
	root->height = 1;
	return root;
}

int maximum(int a, int b)
{
	return (a > b) ? a : b;
}

int height(Tree root)
{
	if (root == NULL)
		return 0;
	return root->height;
}

int balancedFactor(Tree root)
{
	if (root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

void updateHeight(Tree root)
{
	root->height = maximum(height(root->left), height(root->right)) + 1;
}

Tree leftRotation(Tree x)
{
	// TODO 1
	Tree y = x->right;
	x->right = y->left;
	y->left = x;
	updateHeight(x);
	updateHeight(y);
	x = y;
	return x;
}

Tree rightRotation(Tree x)
{
	// TODO 2
	Tree y = x->left;
	x->left = y->right;
	y->right = x;
	updateHeight(x);
	updateHeight(y);
	x = y;
	return x;
}

Tree insert(Tree root, T value)
{
	// TODO 3
	if (root == NULL)
	{
		root = createTree(value);
		return root;
	}
	else if (root->value == value)
		return root;
	else if (value < root->value)
		root->left = insert(root->left, value);
	else if (value > root->value)
		root->right = insert(root->right, value);
	else
		return root;
	updateHeight(root);
	if (balancedFactor(root) > 1 && root->left->value > value)
	{
		root = rightRotation(root);
		return root;
	}
	else if (balancedFactor(root) < -1 && root->right->value < value)
	{
		root = leftRotation(root);
		return root;
	}
	else if (balancedFactor(root) > 1 && root->left->value < value)
	{
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	else if (balancedFactor(root) < -1 && root->right->value > value)
	{
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}

Tree freeTree(Tree root)
{
	if (root == NULL)
		return NULL;
	root->left = freeTree(root->left);
	root->right = freeTree(root->right);
	free(root);
	return NULL;
}
