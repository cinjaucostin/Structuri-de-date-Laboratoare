#ifndef ORDERED_SET_H
#define ORDERED_SET_H

#include <stdio.h>                                          // needed for printf
#include <stdlib.h>                           // needed for alloc, realloc, free

/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------

/*
  OrderedSet represents a set with elements of type T stored in memory
  in an ordered fashion.
*/

typedef struct OrderedSet {
  T* elements;                    // pointer to where the elements are in memory
  long size;                                // the number of elements in the set
  long capacity;                      // the current capacity (allocated memory)
} OrderedSet;

// -----------------------------------------------------------------------------

/*
  Function that creates an OrderedSet with elements of type T with a given
  initial capacity.
*/

OrderedSet* createOrderedSet(long initialCapacity) {

  OrderedSet* newSet = (OrderedSet*) malloc(sizeof(OrderedSet));

  newSet->size = 0;                        // initially, the set is empty
  newSet->capacity = initialCapacity;
  newSet->elements = (T*) malloc(initialCapacity * sizeof(T));

  return newSet;
}

// -----------------------------------------------------------------------------

/*
  Function that checks if an element exists in a given set. As the
  elements of the set are ordered in memory, this function uses binary
  search.

  Function returns 1 if the given element exists in the set, and 0
  otherwise.
*/

int contains(OrderedSet* set, const T element) {
    // TODO : Cerința 2
    int inf=0,sup=set->size-1,mij=0;
    while(inf <= sup)
    {
        mij=(inf+sup)/2;
        if(set->elements[mij]==element)
            return 1;
        else if(set->elements[mij] < element)
            inf=mij+1;
        else if(set->elements[mij] > element)
            sup=mij-1;
    }
    return 0;
}

// -----------------------------------------------------------------------------

/*
  Function that adds a new element to a set. If the element was
  already in the set, nothing changes. Otherwise, the element is added
  to the set. In the end, the elements must be in ascending order.
*/

void add(OrderedSet* set, const T newElement) {
    // TODO : Cerința 2
    int poz=-1;
    if(contains(set,newElement) == 0)
    {
        if(set->size == set->capacity)
        {
            set->capacity*=2;
            set->elements=realloc(set->elements,set->capacity*sizeof(T));    
        }
        for(int i=0; i<set->size; i++)
        {
            if(set->elements[i] > newElement)
            {    
                poz=i;
                break;
            }
        }
        set->size++;
        if( poz == -1)
            set->elements[set->size-1]=newElement;
        else
        {
          for(int i=set->size; i>=poz+1; i--)
          {
              set->elements[i]=set->elements[i-1];
          }
          set->elements[poz]=newElement;
        }
    }
}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the union of
  the two
*/

OrderedSet* unionOrderedSets(OrderedSet* s1, OrderedSet* s2)
{
    // TODO : Cerința 3
    OrderedSet* s3;
    s3=createOrderedSet(s1->size+s2->size);
    int i=0,j=0,k=0;
    while(i<s1->size && j<s2->size)
    {
        if(s1->elements[i] < s2->elements[j])
        {
            add(s3,s1->elements[i]);
            k++;
            i++;
        }
        else if(s1->elements[i] > s2->elements[j])
        {
            add(s3,s2->elements[j]);
            k++;
            j++;
        }
        else
        {
            add(s3,s2->elements[j]);
            k++;
            i++;
            j++;
        }
    }
    while( i< s1->size)
    {
        add(s3,s1->elements[i]);
        k++;
        i++;
    }

    while( j< s2->size)
    {
        add(s3,s2->elements[j]);
        k++;
        j++;
    }
    return s3;
    return createOrderedSet(1);
}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the
  intersection of the two
*/

OrderedSet* intersectOrderedSets(OrderedSet* s1, OrderedSet* s2) {
  // TODO : Cerința 3
  OrderedSet* s3;
  s3=createOrderedSet(s1->size);
  int i=0,j=0,k=0;
  while(i<s1->size && j<s2->size)
  {
      if(s1->elements[i] == s2->elements[j])
      { 
        add(s3,s1->elements[i]);
        k++;
        i++;
        j++;
      }
      else if (s1->elements[i] < s2->elements[j])
      {
        i++;
      }
      else if (s1->elements[i] > s2->elements[j])
      {
        j++;
      }
  }
  return s3;
  return createOrderedSet(1);
}
// -----------------------------------------------------------------------------
#endif