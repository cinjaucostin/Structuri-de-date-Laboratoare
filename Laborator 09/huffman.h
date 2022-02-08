#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include <string.h>

typedef struct
{
    unsigned char value;
    int left, right;
} HuffmanNode;

#define Item int

// Including below so `Item` is defined.
#include "heap.h"

void computeFreqs(char *text, int size, int freqs[256])
{
    for (int i = 0; i < 256; i++)
        freqs[i] = 0;
    for (int i = 0; i < size; i++)
        freqs[text[i] - 'a']++;
}

HuffmanNode *makeTree(int freqs[256], int *size)
{
    APriQueue hp = makeQueue((*size) + 1);
    for (int i = 0; i < 256; i++)
    {
        if (freqs[i] != 0)
        {
            ItemType x;
            x.content = i;
            x.prior = freqs[i];
            insert(hp, x);
        }
    }
    (*size) = hp->size;
    for (int i = 0; i < *size; i++)
        printf("%c %d\n", hp->elem[i].content + 'a', hp->elem[i].prior);
    HuffmanNode *cozonac;
    cozonac = malloc(hp->size * sizeof(HuffmanNode));
    int i = 0;
    while (hp->size >= 2)
    {
        ItemType MIN1, MIN2;
        MIN1 = removeMin(hp);
        MIN2 = removeMin(hp);
    }
}

void makeCodes(int index, HuffmanNode *nodes, char **codes, char *code)
{
}

char *compress(char *text, int textSize, HuffmanNode *nodes, int numNodes)
{
}

char *decompress(char *text, int textSize, HuffmanNode *nodes, int numNodes)
{
}

#endif
