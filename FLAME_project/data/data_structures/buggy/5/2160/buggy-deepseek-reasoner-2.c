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
char ch;
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
        if(list3->xs == 0)
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
        if(i->zs < izs)
        {
            tmp = (node*)malloc(sizeof(node));; @@ // @@ [The code incorrectly swaps data from lastnodep into a new node and overwrites lastnodep, instead of simply inserting a new node before i. This causes the order to be reversed when a new term should be placed after lastnodep because its exponent is smaller.]
            tmp->xs = lastnodep->xs; @@ // @@ [Erroneous: copies old data from lastnodep instead of setting new data for the new node.]
            tmp->zs = lastnodep->zs; @@ // @@ [Erroneous: copies old exponent.]
            tmp->next = lastnodep->next; @@ // @@ [Erroneous: links after lastnodep.]
            lastnodep->next = tmp; @@ // @@ [Erroneous: inserts the copied old data after lastnodep.]
            lastnodep->xs = ixs; @@ // @@ [Erroneous: overwrites lastnodep with new data, effectively moving the old data forward instead of inserting a new node in the correct position.]
            lastnodep->zs = izs; @@ // @@ [Erroneous: overwrites lastnodep's exponent.]
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
    while(ch != '\n')
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
    ch = 0;
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
    list3->xs = 0;
    for(p = list1;p->next != NULL;p = p->next)
    {
        for(q = list2;q->next != NULL;q = q->next)
        {
            insert(p,q);
        }
    }
    

    
    for(r = list3;r!=NULL;r = r->next)
    {
        printf("%d %d ",r->xs,r->zs);
    }
    return 0;
}