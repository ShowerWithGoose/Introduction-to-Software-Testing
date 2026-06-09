#include<stdio.h>
#include<stdlib.h>
struct Node{
    int xs;
    int zs;
    struct Node* next;  
};
typedef struct Node node;
node *list1,*list2,*list3,*p,*q,*r;
int m,n;
char ch; // @@ The variable 'ch' is uninitialized. In C, global variables are initialized to 0, so this works for the first loop condition check (0 != '\n'), but it's bad practice. However, the logic relies on scanf reading the newline.
void insert(node* P,node* Q)
{
    int ixs,izs;
    node *lastnodep,*i,*tmp;
    ixs = (P->xs) * (Q->xs);
    izs = (P->zs) + (Q->zs);
    
    lastnodep =  list3;
    i = list3;
    while(1)
    {
        if(list3->xs == 0) // @@ This condition checks if the head node (dummy or real) has coefficient 0. If list3 is meant to be a dummy head, this logic is flawed because it overwrites the head instead of inserting after. If list3 is the first real node, it prevents adding new terms if the first term's coeff becomes 0 or if it was initialized to 0.
        {
            list3->xs = ixs;
            list3->zs = izs;
           // printf("1success %d %d %d\n",ixs,izs,lastnodep->xs);
            break;
        }
        if(i->zs == izs)
        {
            i->xs += ixs;
           // printf("2success %d %d %d\n",ixs,izs,lastnodep->xs);
            break;
        }
        if(i->zs < izs) // @@ We found a node with exponent smaller than the new term. We need to insert the new term BEFORE 'i'.
        {
            tmp = (node*)malloc(sizeof(node));;
            tmp->xs = lastnodep->xs; // @@ Error: This logic attempts to shift the previous node's data into a new node and overwrite the previous node. This is incorrect linked list insertion. It corrupts the list structure and data.
            tmp->zs = lastnodep->zs;
            tmp->next = lastnodep->next;
            lastnodep->next = tmp;
            lastnodep->xs = ixs; // @@ Overwriting the previous node's data instead of creating a new node for the new term and linking it properly.
            lastnodep->zs = izs;
            //printf("3success %d %d %d\n",ixs,izs,lastnodep->xs);
            break; 
        }
        if(i->next == NULL)
        {
            i->next = (node*)malloc(sizeof(node));
            i = i->next;
            i->xs = ixs;
            i->zs = izs;
            i->next = NULL;
            //printf("4success %d %d %d\n",ixs,izs,lastnodep->xs); 
            break;
        }
        lastnodep = i;
        i = i->next;
    }
}
int main()
{
    
    list1 = (node*)malloc(sizeof(node));
    list2 = (node*)malloc(sizeof(node));
    list3 = (node*)malloc(sizeof(node));
    
    p = q = NULL;
    while(ch != '\n') // @@ Logic depends on ch being initialized or set by previous scanf. Since ch is global, it starts as 0.
    {
        scanf("%d%d%c",&m,&n,&ch);
        if(p == NULL)
        {
            p = q = list1;
            q->xs = m;
            q->zs = n;
            q->next = (node*)malloc(sizeof(node));
            q = q->next;
            q ->next = NULL;
        }
        else
        {
            q->xs = m;
            q->zs = n;

            p = q;
            q ->next = (node*)malloc(sizeof(node));
            q = q->next;
            q->next = NULL;
        }
        
    }
    ch = 0; // @@ Resetting ch to 0 to ensure the next loop runs.
    p = q = NULL;
    while(ch != '\n')
    {
        scanf("%d%d%c",&m,&n,&ch);
        if(p == NULL)
        {
            p = q = list2;
            q->xs = m;
            q->zs = n;
            q->next = (node*)malloc(sizeof(node));
            q = q->next;
            q ->next = NULL;
        }
        else
        {
            q->xs = m;
            q->zs = n;

            p = q;
            q ->next = (node*)malloc(sizeof(node));
            q = q->next;
            q->next = NULL;
        }
        
    }

    list3->next = NULL;
    list3->xs = 0; // @@ Initializing list3 head with xs=0. This triggers the first condition in insert(), treating list3 as the first real node initially, which is problematic for subsequent insertions if not handled correctly as a sorted list.
    for(p = list1;p->next != NULL;p = p->next) // @@ Iterates through list1. Note that the input reading logic leaves an extra empty node at the end of each list (because it always allocates next). So p->next != NULL stops before the empty tail node. This part is technically okay given the input method.
    {
        for(q = list2;q->next != NULL;q = q->next)
        {
            insert(p,q);
        }
    }
    

    
    for(r = list3;r!=NULL;r = r->next)
    {
        if (r->xs == 0 && r->next != NULL) continue; // @@ The original code prints all nodes. If list3 contains nodes with 0 coefficient (from cancellation or initialization), they should ideally be skipped. However, the main issue is sorting.
        printf("%d %d ",r->xs,r->zs);
    }
    return 0;
}