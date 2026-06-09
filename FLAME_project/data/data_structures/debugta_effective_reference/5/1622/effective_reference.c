#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct polymial{
    int coef;
    int expn;
    struct polymial *next;
}polymial,*linklist;

linklist poly1=NULL,poly2=NULL,poly=NULL;

void insert(linklist p,int c,int e){
    linklist q;
    q=(linklist)malloc(sizeof(polymial));
    q->coef=c;
    q->expn=e;
    q->next=NULL;              
    if(poly==NULL)
        poly=q;
    else if(p==NULL){
        q->next=poly;
        poly=q;
    }
    else{
        q->next=p->next;
        p->next=q;
    }
    return;
}

void search(int c,int e){
    linklist p,q=NULL;
    for(p=poly;p!=NULL;q=p,p=p->next){
        if(e>p->expn) 
            break;
        else if(e==p->expn){
            p->coef+=c;
            return;
        }
    }
    insert(q,c,e);
    return;
}


void multi(){
    linklist p,q;
    int r1,r2;
    for(p=poly1;p!=NULL;p=p->next){
        for(q=poly2;q!=NULL;q=q->next){
            r1=p->coef*q->coef;
            r2=p->expn+q->expn;
            search(r1,r2);
        }
    }
    return;
}

int main(){
    linklist pp;
    int coef,expn;
    linklist p,q;
    char ch;
    do{
        scanf("%d%d%c",&coef,&expn,&ch);
        q=(linklist)malloc(sizeof(polymial));
        q->coef=coef;
        q->expn=expn;
        q->next=NULL;
	    if(poly1==NULL)
            poly1=p=q;
        else
            p->next=q;      
	    p=q;
    }while(ch!='\n');
    do{
        scanf("%d%d%c",&coef,&expn,&ch);
        q=(linklist)malloc(sizeof(polymial));
        q->coef=coef;
        q->expn=expn;
        q->next=NULL;
	    if(poly2==NULL)
            poly2=p=q;
        else
            p->next=q;      
	    p=q;
    }while(ch!='\n');
    multi();
    for(pp=poly;pp!=NULL;pp=pp->next)
        printf("%d %d ",pp->coef,pp->expn);
    return 0;
}

