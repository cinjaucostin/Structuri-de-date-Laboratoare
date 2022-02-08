#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *Key;
typedef int Value;
typedef long (*HashFunction)(Key, long);

typedef struct Element
{
  Key key;
  Value value;
  struct Element *next;
} Element;

typedef struct HashTable
{
  Element **elements;
  long size;
  HashFunction hashFunction;
} HashTable;

void initHashTable(HashTable **h, long size, HashFunction f)
{
  // Cerinta 1
  (*h) = malloc(sizeof(HashTable));
  (*h)->elements = malloc(sizeof(Element *));
  for (int i = 0; i < size; i++)
    (*h)->elements[i] = malloc(sizeof(Element));
  (*h)->size = size;
  (*h)->hashFunction = f;
}

int exists(HashTable *hashTable, Key key)
{
  // Cerinta 1
  long index;
  index = hashTable->hashFunction(key, hashTable->size);
  Element *parcurgere;
  parcurgere = hashTable->elements[index];
  while (parcurgere != NULL)
  {
    if (strcmp(parcurgere->key, key) == 0)
      return 1;
    parcurgere = parcurgere->next;
  }
  return 0;
}

Value get(HashTable *hashTable, Key key)
{
  // Cerinta 1
  if (exists(hashTable, key) == 0)
    return (Value)0;
  else
  {
    long index;
    index = hashTable->hashFunction(key, hashTable->size);
    Element *parcurgere;
    parcurgere = hashTable->elements[index];
    while (parcurgere != NULL)
    {
      if (strcmp(parcurgere->key, key) == 0)
        return parcurgere->value;
      parcurgere = parcurgere->next;
    }
  }
  return (Value)0;
}

void put(HashTable *hashTable, Key key, Value value)
{
  // Cerinta 1
  if (exists(hashTable, key) == 1) //Inseamna ca exista deja cheia in tabela deci trebuie suprascrisa
  {
    long index = hashTable->hashFunction(key, hashTable->size);
    Element *parcurgere;
    parcurgere = hashTable->elements[index];
    while (parcurgere != NULL)
    {
      if (strcmp(parcurgere->key, key) == 0)
      {
        parcurgere->value = value;
        break;
      }
      parcurgere = parcurgere->next;
    }
  }
  else
  {
    long index = hashTable->hashFunction(key, hashTable->size);
    Element *new_element = malloc(sizeof(Element));
    strcpy(new_element->key, key);
    new_element->value = value;
    new_element->next = NULL;
    if (hashTable->elements[index] == NULL) //Inseamna ca nu avem nimic pe pozitia index din vectorul elements si trebuie sa facem un cap de lista
    {
      hashTable->size++;
      hashTable->elements[index] = new_element;
    }
    else //Inseamna ca avem deja o lista pe pozitia index si noi trebuie sa inseram noul element la sfarsitul listei respective
    {
      Element *parcurgere = hashTable->elements[index];
      while (parcurgere != NULL)
      {
        parcurgere = parcurgere->next;
      }
      parcurgere->next = new_element;
    }
  }
}

void deleteKey(HashTable *hashTable, Key key)
{
  // Cerinta 1
  if (exists(hashTable, key) == 1)
  {
    long index;
    index = hashTable->hashFunction(key, hashTable->size);
    if (hashTable->elements[index]->next == NULL)
    {
      hashTable->size--;
      free(hashTable->elements[index]);
    }
    else
    {
      Element *parcurgere;
      while (parcurgere->next != NULL)
      {
        if (strcmp(parcurgere->next->key, key) == 0)
        {
          Element *temp = parcurgere->next;
          parcurgere->next = temp->next;
          free(temp);
          return;
        }
        parcurgere = parcurgere->next;
      }
    }
  }
  else
    return;
}

void print(HashTable *hashTable)
{
  // Cerinta 1
  Element *parcurgere;
  for (int i = 0; i < hashTable->size; i++)
  {
    parcurgere = hashTable->elements[i];
    while (parcurgere != NULL)
    {
      printf("%s %d", parcurgere->key, parcurgere->value);
      parcurgere = parcurgere->next;
    }
    printf("\n");
  }
}

void freeHashTable(HashTable *hashTable)
{
  // Cerinta 1
  for (int i = 0; i < hashTable->size; i++)
  {
    Element *parcurgere = hashTable->elements[i], *temp;
    if (parcurgere->next == NULL)
      free(parcurgere);
    else
    {
      while (parcurgere != NULL)
      {
        temp = parcurgere;
        parcurgere = parcurgere->next;
        free(temp);
      }
    }
  }
  free(hashTable->elements);
  free(hashTable);
}

long hash1(Key word, long size)
{
  // Cerinta 2
  long h = 0;
  for (int i = 0; i < strlen(word) - 1; i++)
  {
    h = h * 17 + word[i];
  }
  return h % size;
}

int main(int argc, char *argv[])
{
  HashTable *hashTable;
  FILE *f1, *f2;
  char word[256];
  long hashSize, common;

  hashSize = atoi(argv[1]);
  f1 = fopen(argv[2], "r");
  f2 = fopen(argv[3], "r");

  initHashTable(&hashTable, hashSize, &hash1);

  // Cerinta 3

  // ...

  // Cerinta 4

  // ...

  printf("Common words: %ld\n", common);

  fclose(f1);
  fclose(f2);
  return 0;
}
