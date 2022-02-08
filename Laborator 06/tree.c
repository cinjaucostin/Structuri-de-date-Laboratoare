/*
*	Created by Nan Mihai on 05.05.2021
*	Copyright (c) 2020 Nan Mihai. All rights reserved.
*	Laborator 6 - Structuri de date
*	Grupa 314CD
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2020-2021, Seria CD
*/
#include "tree.h"

/*
*	Funcție care creează un arbore cu un singur nod
*/
Tree createTree(Tree parent, Item value)
{
	Tree root = malloc(sizeof(TreeNode));
	root->parent = parent;
	root->value = value;
	root->left = NULL;
	root->right = NULL;
	return root;
}

/*
*	Funcție care inițializează un nod de arbore
*		- îi alocă memorie
*		- îi setează câmpul valoare
*		- setează left și right să pointeze către NULL
*/

void init(Tree *root, Tree parent, Item value)
{
	// TODO 0
	*root = createTree(parent, value);
}

/*
*	Funcție care inserează o valoare într-un arbore binar, respectând
* proprietățile unui arbore binar de căutare
*/
Tree insert(Tree root, Item value)
{
	// TODO 1
	if (root == NULL)
		return createTree(NULL, value);
	if (root->value == value)
		return root;
	if (value < root->value)
	{
		root->left = insert(root->left, value);
		root->left->parent = root;
	}
	else
	{
		root->right = insert(root->right, value);
		root->right->parent = root;
	}
	return root;
}

/*
*	Funcție care verifică dacă un arbore este vid sau nu
*		- întoarce 1 dacă arborele este vid
*		- întoarce 0 dacă arborele nu este vid
*/
int isEmpty(Tree root)
{
	// TODO 2
	if (root == NULL)
		return 1;
	return 0;
}

/*
*	Funcție care verifică dacă o valoare există sau nu în arbore
*		- 1 dacă value există în arbore
*		- 0 dacă value nu există în arbore
*/
int contains(Tree tree, Item value)
{
	// TODO 3
	Tree root = tree;
	while (root != NULL)
	{
		if (value < root->value)
			root = root->left;
		else if (value > root->value)
			root = root->right;
		else if (value == root->value)
			return 1;
	}
	return 0;
}

/*
*	Funcție care determină elementul minim dintr-un arbore binar de căutare
*		- NULL pentru arbore vid
*/
Tree minimum(Tree tree)
{
	// TODO 4.1
	Tree root = tree;
	if (isEmpty(root))
		return NULL;
	while (!isEmpty(root))
	{
		if (root->left == NULL)
			return root;
		root = root->left;
	}
}

/*
*	Funcție care determină elementul maxim dintr-un arbore binar de căutare
*		- NULL pentru arbore vid
*/
Tree maximum(Tree tree)
{
	// TODO 4.2
	Tree root = tree;
	if (isEmpty(root))
		return NULL;
	while (!isEmpty(root))
	{
		if (root->right == NULL)
			return root;
		root = root->right;
	}
}

/*
*	Funcție care determină succesorul în inordine pentru nodul care conține
* valoarea value.
*/
Tree successor(Tree root, Item value)
{
	// TODO 5
	Tree tree = root, nod;
	//Am parcurs arborele pentru a ajunge la nodul caruia trebuie sa ii calculam succesorul
	while (tree != NULL)
	{
		if (value < tree->value)
			tree = tree->left;
		else if (value > tree->value)
			tree = tree->right;
		else if (tree->value == value)
		{
			nod = tree;
			break;
		}
	}
	if (nod->right != NULL)
		return minimum(nod->right);
	else
	{
		tree = nod;
		while (tree != NULL)
		{
			if (tree->value > nod->value)
			{
				return tree;
			}
			tree = tree->parent;
		}
	}
}

/*
*	Funcție care determină predecesorul în inordine pentru nodul care conține
* valoarea value.
*/
Tree predecessor(Tree root, Item value)
{
	// TODO 6
	Tree tree = root, nod;
	//Am parcurs arborele pentru a ajunge la nodul caruia trebuie sa ii calculam predecesorul
	while (tree != NULL)
	{
		if (value < tree->value)
			tree = tree->left;
		else if (value > tree->value)
			tree = tree->right;
		else if (tree->value == value)
		{
			nod = tree;
			break;
		}
	}
	if (nod->left != NULL)
		return maximum(nod->left);
	else
	{
		tree = nod;
		while (tree != NULL)
		{
			if (tree->value < nod->value)
			{
				return tree;
			}
			tree = tree->parent;
		}
		return tree;
	}
}

/*
*	Funcție care dealocă întreaga memorie alocată pentru un arbore binar
*		- root va pointa către NULL după ce se va apela funcția
*/
void destroyTree(Tree *root)
{
	if ((*root) != NULL)
	{
		if ((*root)->left != NULL)
			destroyTree(&(*root)->left);
		if ((*root)->right != NULL)
			destroyTree(&(*root)->right);
		free(*root);
		*root = NULL;
	}
}

/*
*	Funcție care șterge un nod cu o anumită valoare din arbore
*/
Tree delete (Tree root, Item value)
{
	// TODO 7
	if (root == NULL)
		return root;
	if (root->value > value)
		root->left = delete (root->left, value);
	else if (root->value < value)
		root->right = delete (root->right, value);
	else
	{
		Tree temp;
		if (root->left != NULL && root->right != NULL) //daca nu este frunza
		{
			temp = minimum(root->right);
			root->value = temp->value;
			root->right = delete (root->right, temp->value);
		}
		else
		{
			temp = root;
			if (root->left != NULL)
				root = root->left;
			else
				root = root->right;
			free(temp);
		}
	}
	return root;
}

/*
*	Funcție care determină cel mai apropiat strămoș comun pentru
* două noduri având cheile value1 și value2
*/
Tree lowestCommonAncestor(Tree root, Item value1, Item value2)
{
	// TODO 8
	if (root == NULL)
		return NULL;
	if (root->value > value1 && root->value > value2)
		return lowestCommonAncestor(root->left, value1, value2);
	if (root->value < value1 && root->value < value2)
		return lowestCommonAncestor(root->right, value1, value2);
	return root;
}
