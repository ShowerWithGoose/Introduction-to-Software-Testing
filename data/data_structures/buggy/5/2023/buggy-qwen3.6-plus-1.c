#include <stdio.h>
#include <stdlib.h>
typedef struct dot{
    int a;
    int n;
    struct dot *link;
}dot;
void Link(dot **line,int n);
void insert(dot *p,dot *list);
void Findinsert(dot *listc,dot *list);
void Add(dot *p,dot *q);
void Print(dot *p);
int main() {
    int a,n;
    char c;
    dot *lista=NULL,*listb=NULL,*p,*q;
    while(scanf("%d %d%c",&a,&n,&c)){

            if(lista==NULL){
                lista=(dot *)malloc(sizeof(dot));
                p=q=lista;
                p->a = a;
                p->n = n;
            }
            else {
                q = (dot *) malloc(sizeof(dot));
                q->link=NULL;
                q->a=a;
                q->n=n;
                p->link = q;
                p = p->link;;
            }
        if(c=='\n')break;
    }
    while(scanf("%d %d%c",&a,&n,&c)){

        if(listb==NULL){
            listb=(dot *)malloc(sizeof(dot));
            p=q=listb;
            p->a = a;
            p->n = n;
        }
        else {
            q = (dot *) malloc(sizeof(dot));
            q->link=NULL;
            q->a=a;
            q->n=n;
            p->link = q;
            p = p->link;;
        }
        if(c=='\n')break;
    }
//    Add(lista,q);
//    Findinsert(lista,listb);
//    Print(lista);
//    Print(listb);
    dot *listc=NULL;
    dot *l;
    p=lista;
    while(p!=NULL){
        q=listb;
        while(q!=NULL){
            l=(dot *)malloc(sizeof(dot));
            l->link=NULL;
            if(listc==NULL){
                listc=l;
                l->a = p->a * q->a;
                l->n = p->n + q->n;
                q = q->link;
            }
            else{
                l->a = p->a * q->a;
                l->n = p->n + q->n;
                Findinsert(listc, l); // @@ [Error] `Findinsert` takes `listc` by value and lacks head-handling logic, so it cannot correctly insert terms before the head or update the head pointer in `main`.
                q = q->link;
            }
        }
        p=p->link;
    }
        Print(listc);

    return 0;
}
void insert(dot *p,dot *list){
    if(p->link==NULL){
        list->link=NULL;//若插入位置为链条末尾，将list链指向NULL
        p->link=list;
        return;
    }
    else{
        list->link=p->link;
        p->link=list;
    }
}
void Add(dot *p,dot *q){
    p->a=p->a+q->a;
}
void Findinsert(dot *listc,dot *list){ // @@ [Error] Function lacks logic to handle cases where `list->n >= listc->n`, causing incorrect ordering and missed coefficient additions for the head term.
        dot *p=listc; // @@ [Error] Traversal starts at the head but skips checking if `list->n >= p->n`, leading to incorrect ordering or missed merges for the first term.
        while(p->link!=NULL&&p->link->n>list->n){ // @@ [Error] The loop condition only checks `p->link`, ignoring the head node `p`. This fails to insert larger exponents at the front or merge with the head.
            p=p->link;
        }
        if(p->link==NULL){ // @@ [Error] Incorrectly assumes insertion is always after `p`, failing to handle head insertion or head coefficient addition.
            insert(p,list);
        }
        else if(p->link->n==list->n){ // @@ [Error] Only checks the next node for exponent equality, missing the case where `list->n == p->n`.
            Add(p->link,list);
            return;
        }
        else // @@ [Error] Fallback logic does not account for head insertion or head merging.
        {
            insert(p,list);
        }
}
void Print(dot *p){
    while(p!=NULL){
        printf("%d %d  ",p->a,p->n);
        p=p->link;
    }
    printf("\n");
}