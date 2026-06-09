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
                p->n = n; // @@ Missing initialization of p->link to NULL, causing undefined behavior or crash when traversing a single-term polynomial.
            }
            else {
                q = (dot *) malloc(sizeof(dot));
                q->link=NULL;
                q->a=a;
                q->n=n;
                p->link = q;
                p = p->link;; // @@ Double semicolon is a syntax typo.
            }
        if(c=='\n')break;
    }
    while(scanf("%d %d%c",&a,&n,&c)){

        if(listb==NULL){
            listb=(dot *)malloc(sizeof(dot));
            p=q=listb;
            p->a = a;
            p->n = n; // @@ Missing initialization of p->link to NULL.
        }
        else {
            q = (dot *) malloc(sizeof(dot));
            q->link=NULL;
            q->a=a;
            q->n=n;
            p->link = q;
            p = p->link;; // @@ Double semicolon is a syntax typo.
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
                Findinsert(listc, l);
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
    p->a=p->a+q->a; // @@ Does not check if the resulting coefficient becomes zero, which may lead to printing zero terms that should be omitted.
}
void Findinsert(dot *listc,dot *list){
        dot *p=listc;
        while(p->link!=NULL&&p->link->n>list->n){ // @@ Fails to handle the case where list->n equals listc->n (head node), causing duplicate terms instead of merging. Also fails to insert at the head if list->n > listc->n.
            p=p->link;
        }
        if(p->link==NULL){
            insert(p,list);
        }
        else if(p->link->n==list->n){
            Add(p->link,list);
            return;
        }
        else
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