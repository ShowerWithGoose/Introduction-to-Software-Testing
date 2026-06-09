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
            free(list); // @@ [Memory leak: allocated node 'list' is not freed when its exponent matches an existing term and its coefficient is added to the existing term. This causes memory leak and also leads to double-free or use-after-free if not handled. However, more critically, in the main loop, when listc is NULL, the first term is inserted without being processed by Findinsert, so if later terms have same exponent as first term, they won't be merged because Findinsert starts comparing from listc (which has no dummy head), and the first node is never checked for merging.]
            return;
        }
        else
        {
            insert(p,list);
        }
}
void Print(dot *p){
    while(p!=NULL){
        printf("%d %d  ",p->a,p->n); // @@ [Extra space: prints two spaces between terms and after last term, but expected output has single space separation. The problem says "a space after the last exponent is optional", but the test case expected output uses single spaces only. More importantly, the real issue is that the first term inserted into listc is never merged with others of same exponent because Findinsert doesn't check the head node.]
        p=p->link;
    }
    printf("\n");
}