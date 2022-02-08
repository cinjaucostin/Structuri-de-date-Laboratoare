#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdlib.h>
#include <assert.h>

/*
    IMPORTANT!

    As we stick to pure C, we cannot use templates. We will just asume
    some type T was previously defined.
*/

// -----------------------------------------------------------------------------

typedef struct node {
    T value;
    struct node* next;
} TNode, *TSortedList;

// TODO : Cerința 1 & Cerința 2

TSortedList create(T value) {
    // TODO (se va completa la Cerința 2)
    TSortedList nod;
    nod=(TSortedList)malloc(sizeof(TNode));
    nod->value=value;
    nod->next=NULL;
    return nod;
}
int isEmpty(TSortedList list)
{
    if(list == NULL)//inseamna ca lista este vida
        return 1;
    return 0;
}
TSortedList freeTSortedList(TSortedList list)
{
    TSortedList next;
    while(list != NULL)
    {
        next=list;
        list=list->next;
        free(next);
    }
    return list;
}
TSortedList insert(TSortedList list, T element)
{
    TSortedList iter, de_introdus, urmator;
    if(list == NULL)
    {
        iter=create(element);
        return iter;
    }
    else if(list->value > element)
    {
        urmator=create(element);
        urmator->next=list;
        return urmator;
    }
    iter = list;
    while(iter->next != NULL)
    {
        if(element < iter->next->value)
        {
            de_introdus=create(element);
            de_introdus->next=iter->next;
            iter->next=de_introdus;
            return list;
        }
        iter = iter->next;
    }
    urmator=create(element);
    iter->next=urmator;
    return list;
}
int length(TSortedList list)
{
    TSortedList iter=list;
    int nr=0;
    while(iter!=NULL)
    {
        nr++;
        iter=iter->next;
    }
    return nr;
}
int contains(TSortedList list, T element)
{
    TSortedList itr;
    itr=list;
    while(itr!=NULL && itr->value != element)
    {
        itr=itr->next;
    }
    if(itr==NULL)//Inseamna ca nu s-a gasit elementul in lista
        return 0;
    else
        return 1;//Inseamna ca s-a gasit elementul in lista
}
TSortedList deleteOnce(TSortedList list, T element)
{
    TSortedList itr = list, eliminat;
    while(itr->next!=NULL)
    {
        if(itr->next->value == element)
        {    
            eliminat=itr->next;
            itr->next=eliminat->next;
            free(eliminat);
            return list;
        }
        itr=itr->next;
    }
}
T getNth(TSortedList list, int N)
{
    TSortedList itr=list;
    T valoare;
    int nr=0;
    while(itr!=NULL)
    {
        if(nr==N)
        {
            valoare=itr->value;
            break;
        }
        itr=itr->next;
        nr++; 
    }
    return valoare;
}
#endif
