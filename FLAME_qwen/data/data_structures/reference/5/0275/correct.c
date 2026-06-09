#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct node{
    int a;
    int n;
    struct node* next;
}node;

typedef struct linklist{
    node *head;
    int size;
}linklist;

node *initnode(int a,int n){
    node *p=(node *)malloc(sizeof(node ));
    p->next=NULL;
    p->a=a;
    p->n=n;
    return p;
}


linklist *init(){
    linklist* l=(linklist *)malloc(sizeof(linklist));
    l->head=initnode(0,0);
    l->size=0;
    return l;
}

void add(linklist *l,node *new){
    node *p=l->head;
    while(p->next!=NULL && p->next->n>new->n){
        p=p->next;
    }
    if(p->next==NULL){
        p->next=new;
        return;
    }
    
    if(p->next->n==new->n){
        p->next->a+=new->a;
        return;
    }
    new->next=p->next;
    p->next=new;
    return;
}

void output(linklist *l){
    node *p=l->head->next;
    while(p!=NULL){
        printf("%d %d ",p->a,p->n);
        p=p->next;
    }
    return;
}

int main(){
    linklist* f1=init();
    linklist* f2=init();
    linklist* l=init();
    int a,n;
    char c;
    while(~scanf("%d%d%c",&a,&n,&c)){
        node *new=initnode(a,n);
        add(f1,new);
        if(c=='\n')break;
    }
    while(~scanf("%d%d%c",&a,&n,&c)){
        node *new=initnode(a,n);
        add(f2,new);
        if(c=='\n')break;
    }
    
    node *p=f1->head->next,*q=f2->head->next;
    while(p!=NULL){
        q=f2->head->next;
        while(q!=NULL){
            node *new=initnode(p->a*q->a, p->n+q->n);
            add(l,new);
            q=q->next;
        }
        p=p->next;
    }
    output(l);
}

