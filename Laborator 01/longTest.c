#include <stdio.h>
#include <string.h>

typedef long T;
#include "OrderedSet.h"

/*
  Function that returns an ordered set with long elements between
  @start and @end that are multiples of @div
*/

int* generator(int left,int right,int div)
{
    int *v,k=0;
    v=malloc(100*sizeof(long));
    for(int i=left; i<=right; i++)
    {
        if(i%div == 0)
        {   
            k++;
            v[k]=i;
        }
    }
    v[0]=k;
    return v;
}
OrderedSet* array(int *v) {
  long len = v[0];
  long idx;

  OrderedSet* set = createOrderedSet(len);
  for (idx=0; idx < len; idx++)
  {
      v[idx]=v[idx+1];
  }
  for (idx = 0; idx < len; idx++)
    add(set, v[idx]);
  free(v);
  return set;
}
// -----------------------------------------------------------------------------

/*
  Function that prints the size and the elements of an ordered set.
*/

void printOrderedCharSet(OrderedSet* set) {
  long idx;
  printf("There are %ld elements:", set->size);
  for(idx = 0; idx < set->size; idx++)
    printf(" %ld", set->elements[idx]);                     
  printf("\n");
}

// -----------------------------------------------------------------------------


int main(int argc, char* argv[]) {
  OrderedSet *s1, *s2, *sU, *sI;

  s1 = array(generator(4,25,3));           
  printOrderedCharSet(s1);

  s2 = array(generator(5,30,4));                       
  printOrderedCharSet(s2);

  sU = unionOrderedSets(s1, s2);                   
  printOrderedCharSet(sU);

  sI = intersectOrderedSets(s1, s2);
  printOrderedCharSet(sI);

  return 0;
}