#include <stdio.h>

typedef int Item;
typedef struct node *link;
typedef struct node {
    Item elem;
    link next;
}ListNode;

link jcreate(int n)
{
    link x;
    link head = malloc(sizeof *head);
    x = head;
    head->elem = 1;
    head->next = head;
    for( int i=2; i<=n; i++)
    {
        x = (x->)
    }

}
int main()
{
    return 0;
}