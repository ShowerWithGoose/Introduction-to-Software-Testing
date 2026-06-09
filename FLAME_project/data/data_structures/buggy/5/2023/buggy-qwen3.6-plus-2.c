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
    p->a=p->a+q->a;
}
void Findinsert(dot *listc,dot *list){
        dot *p=listc;
        while(p->link!=NULL&&p->link->n>list->n){
            p=p->link;
        }
        if(p->link==NULL){
            insert(p,list);
        }
        else if(p->link->n==list->n){
            Add(p->link,list);
            free(list); // @@ [Memory leak: the node 'list' passed to Findinsert is allocated in main but not freed here when its coefficient is merged into an existing node]
            return;
        }
        else
        {
            insert(p,list);
        }
}
void Print(dot *p){
    while(p!=NULL){
        printf("%d %d  ",p->a,p->n); // @@ [Format error: prints two spaces after each term instead of one, causing mismatch with expected output which uses single spaces or standard formatting]
        p=p->link;
    }
    printf("\n");
}