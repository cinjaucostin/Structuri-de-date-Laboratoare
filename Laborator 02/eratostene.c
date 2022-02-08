#include <stdio.h>

typedef int T;
#include "SortedList.h"

TSortedList getNaturals(int A, int B)
{
    TSortedList nats = NULL;
    int i;
    for (i = A; i <= B; i++)
    {
        nats = insert(nats, i);
    }
    return nats;
}

int prim(int n)
{
    int ok = 1;
    if (n < 2)
        ok = 0;
    else
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                ok = 0;
                break;
            }
        }
    }
    return ok;
}

TSortedList getPrimes(int N)
{
    TSortedList nats = getNaturals(2, N);
    TSortedList list = nats;
    // TODO: Cerința Bonus
    while(list!=NULL)
    {
        if(prim(list->value))
        {
            TSortedList lista_aux;
            T valoare=list->value;
            list=list->next;
            lista_aux = list;
            while(lista_aux->next!=NULL)
            {
                if(lista_aux->next->value % valoare == 0)
                {
                    lista_aux->next=lista_aux->next->next;
                }
                else
                {
                    lista_aux=lista_aux->next;
                }
            }
            list=lista_aux;
        }
        else
        {
            list=list->next;
        }
        
    }
    return list;
}

void printInts(TSortedList list)
{
    while (!isEmpty(list))
    {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    printInts(getPrimes(100));
    return 0;
}
