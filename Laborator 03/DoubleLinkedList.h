#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
#include <stdlib.h>
/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------
/**
 *  Linked list representation -- R2 Curs2 (Slide 8)
 */
typedef struct ListNode
{
	Item elem;			   // Stored node value
	struct ListNode *next; // link to next node
	struct ListNode *prev; // link to prev node
} ListNode;

/**
 *  Double linked list representation -- desen Curs 3 (Slide 19)
 */
typedef struct List
{
	ListNode *first; // link to the first node
	ListNode *last;	 // link to the last node
} List;
// -----------------------------------------------------------------------------

/**
 * Create a new node
 *  [input]: Item
 *  [output]: List*
 */
ListNode *createNode(Item elem)
{
	// TODO: Cerinta 1a
	ListNode *node;
	node = malloc(sizeof(ListNode));
	node->elem = elem;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/**
 * Create a new (empty)  list  -- Silde-urile 13/14 Curs 2
 *  [input]: None
 *  [output]: List*
 */
List *createList(void)
{
	// TODO: Cerinta 1a
	List *l;
	l = malloc(sizeof(List));
	l->last = NULL;
	l->first = NULL;
	return l;
}
// -----------------------------------------------------------------------------

/**
 * Determines if the list is empty
 *  [input]: List*
 *  [output]: 1 - empty/ 0 - not empty
 */
int isEmpty(List *list)
{
	// TODO: Cerinta 1b
	if (list == NULL)
		return 1;
	else if (list->first == NULL || list->last == NULL)
		return 1;
	return 0;
}
// -----------------------------------------------------------------------------

/**
 * Determines if a list contains a specified element
 *  [input]: List*, Item
 *  [output]: int (1 - contains/ 0 - not contains)
 */
int contains(List *list, Item elem)
{
	// TDOO: Cerinta 1c
	ListNode *lista_aux;
	for (lista_aux = list->first; lista_aux != NULL; lista_aux = lista_aux->next)
	{
		if (lista_aux->elem == elem)
			return 1;
	}
	return 0;
}
// -----------------------------------------------------------------------------

/**
 * Insert a new element in the list at the specified position.
 * Note: Position numbering starts with the position at index zero
 *  [input]: List*, Item, int
 *  [output]: void
 */
void insertAt(List *list, Item elem, int pos)
{

	// Guard against young player errors
	if (list == NULL || pos < 0)
		return;
	else
	{
		int nr = 0;
		if (pos == 0) //inseamna ca trebuie sa inseram pe prima pozitie
		{
			if (isEmpty(list) == 0) //inseamna ca lista are un singur element si trebuie sa actualizam doar first
			{
				ListNode *new_cell;
				new_cell = createNode(elem);
				new_cell->next = list->first;
				list->first->prev = new_cell;
				list->first = new_cell;
			}
			else if (isEmpty(list) == 1) //inseamna ca lista este goala si trebuie sa actualizam atat first cat si last
			{
				ListNode *new_cell;
				new_cell = createNode(elem);
				list->first = list->last = new_cell;
			}
		}
		else //inseamna ca trebuie sa introducem pe parcursul listei sau la final
		{
			ListNode *lista_aux = list->first;
			int nr = 0, ok = 0;
			for (lista_aux = list->first; lista_aux != NULL; lista_aux = lista_aux->next)
			{
				if (nr == pos) //inseamna ca am ajuns la pozitia la care trebuie sa inseram
				{
					ListNode *new_cell;
					new_cell = createNode(elem);
					new_cell->prev = lista_aux->prev;
					lista_aux->prev->next = new_cell;
					new_cell->next = lista_aux;
					lista_aux->prev = new_cell;
					ok = 1;
				}
				nr++;
			}
			if (ok == 0 && pos <= nr) //inseamna ca nu s-a introdus pe parcurs si inseamna ca trebuie sa introducem la sfarsit
			{
				ListNode *new_cell;
				new_cell = createNode(elem);
				new_cell->prev = list->last;
				list->last->next = new_cell;
				list->last = new_cell;
			}
		}
	}
	// TODO: Cerinta 1d
}
// -----------------------------------------------------------------------------

/**
 * Delete the first element instance form a list.
 *  [input]: List*, Item
 *  [output]: void
 */
void deleteOnce(List *list, Item elem)
{
	// Guard against young player errors
	ListNode *temp;
	if (list == NULL)
		return;
	else
	{
		if (list->first == list->last && list->first != NULL) //inseamna ca lista are un singur element
		{
			if (list->first->elem == elem) //inseamna ca singurul element din lista este egal cu cel pe care noi trebuie sa il stergem
			{
				ListNode *temp=list->first;
				list->first = list->last = NULL;
				free(temp);
				return;
			}
		}
		else if(list->first != list->last && list->first !=NULL) //inseamna ca lista are mai mult de un element
		{
			if (list->first->elem == elem ) //inseamna ca trebuie sa stergem primul element din lista cu mai mult de un element(actualizam first)
			{
				ListNode *temp=list->first;
				list->first = list->first->next;
				list->first->prev=NULL;
				free(temp);
				return;
			}
			else // inseamna ca trebuie sa introducem pe parcurs sau la final
			{
				ListNode *lista_aux;
				for (lista_aux = list->first->next; lista_aux; lista_aux = lista_aux->next)
				{
					if (lista_aux->elem == elem) //inseama ca am gasit elementul ce trebuie sters si facem legaturile intre anteriorul si urmatorul
					{
						if (lista_aux->next != NULL)
						{   
							ListNode *temp=lista_aux;
							ListNode *urmator = lista_aux->next, *precedent = lista_aux->prev;
							precedent->next = urmator;
							urmator->prev = precedent;
							free(temp);
							return;
						}
					}
				}
				//Daca se ajunge in aceasta parte inseamna ca nu s-a sters nici de la inceput si nici de la final si verificam daca se sterge de la final
				if (list->last->elem == elem)
				{   
					ListNode *temp=list->last;
					list->last=list->last->prev;
					list->last->next=NULL;
					free(temp);
					return;
				}
			}
		}
	}
	//TODO: Cerinta 1e
}
// -----------------------------------------------------------------------------

/**
 * Compute list length
 *  [input]: List*
 *  [output]: int
 */
int length(List *list)
{
	// Guard against young player errors
	if (list == NULL)
		return 0;
	else
	{
		ListNode *lista_aux;
		int nr = 0;
		for (lista_aux = list->first; lista_aux != NULL; lista_aux = lista_aux->next)
			nr++;
		return nr;
	}
	// TODO: Cerinta 1f
}
// -----------------------------------------------------------------------------

/**
 * Destroy a list.
 *  [input]: List*
 *  [output]: void
 */
List *destroyList(List *list)
{
	// Guard against young player errors
	if (list == NULL)
		return NULL;
	//free(list->first);
	//free(list->last);
	//free(list);
	ListNode *lista_aux=list->first,*next;
	while(lista_aux)
	{
		next=lista_aux;
		lista_aux=lista_aux->next;
		free(next);
	}
	free(list);
	//TODO: Cerinta 1g
}
// -----------------------------------------------------------------------------

#endif //_DOUBLE_LINKED_LIST_H_
