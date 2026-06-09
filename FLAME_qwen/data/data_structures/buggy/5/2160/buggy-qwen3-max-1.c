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
            tmp = (node*)malloc(sizeof(node));;
            tmp->xs = lastnodep->xs;
            tmp->zs = lastnodep->zs;
            tmp->next = lastnodep->next;
            lastnodep->next = tmp;
            lastnodep->xs = ixs;
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
    while(ch != '\n') // @@ [ch is uninitialized on first use, leading to undefined behavior; the loop may not execute as expected]
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
    while(ch != '\n') // @@ [after setting ch=0, this loop condition is always true initially, but more critically, the input reading logic doesn't handle end-of-input robustly and may cause infinite loops or buffer over-reads]
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
    for(p = list1;p->next != NULL;p = p->next) // @@ [the loop stops before the last node because it checks p->next != NULL, so the last term of the first polynomial is never processed]
    {
        for(q = list2;q->next != NULL;q = q->next) // @@ [same issue: last term of second polynomial is skipped due to q->next != NULL condition]
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