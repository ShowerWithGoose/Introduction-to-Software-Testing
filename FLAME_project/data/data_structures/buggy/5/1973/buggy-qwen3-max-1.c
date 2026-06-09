#include<stdio.h>
#include <stdlib.h>

typedef struct pol {
    struct pol *last;
    int a;
    int n;
    struct pol *next;
}pol;
int main(){

    pol *list=NULL,*p=NULL,*q=NULL,*last,*f=NULL;
    char a;
    int i1=0,i2=0,ai=0,ni=0;
    pol a1[10],a2[10];
    do{
    scanf("%d",&a1[i1].a);
    scanf("%d",&a1[i1].n);
    a=getchar();
    i1++;
    }while(a!='\n');
    do{
        scanf("%d",&a2[i2].a);
        scanf("%d",&a2[i2].n);
        a=getchar();
        i2++;
    }while(a!='\n');
    for(int t=0;t<i1;t++){
    for(int r=0;r<i2;r++){
    ai=a1[t].a*a2[r].a;
    ni=a1[t].n+a2[r].n;
    f=list;
    if(list==NULL){
    list=(pol *)malloc(sizeof(pol));
    list->last=NULL;
    list->a=ai;
    list->n=ni;
    list->next=NULL;
    last=list;
    }
    else {
    while(f!=last){
    if(f->n<ni){
        p=(pol *)malloc(sizeof(pol));
        if(f==list){
        p->next=f;
        f->last=p;
        list=p;
        }
        else {
        f->last->next=p;
        p->last=f->last;
        p->next=f;
        f->last=p;        
        }
        p->a=ai;
        p->n=ni;
        break;
    }
    else if(f->n==ni){
        f->a+=ai;
        break;
    }
    else f=f->next;
    }
    
    if(f==last){
    if(last==list){
    if(f->n<ni){
        p=(pol *)malloc(sizeof(pol));
        p->next=f;
        f->last=p;
        list=p;
        p->last=NULL;
        p->a=ai;
        p->n=ni;
    }
    else if(f->n==ni){
        f->a+=ai;
    }
    else {
        p=(pol *)malloc(sizeof(pol));
        p->last=f;
        f->next=p;
        p->a=ai;
        p->n=ni;
        last=p;
        last->next=NULL;
    }
    }
    else {
    if(f->n<ni){
        p=(pol *)malloc(sizeof(pol));
        f->last->next=p;
        p->last=f->last;
        p->next=f;
        f->last=p;    
        p->a=ai;
        p->n=ni;
    }
    else if(f->n==ni){
        f->a+=ai;
        }
    else {
        p=(pol *)malloc(sizeof(pol));
        p->last=f;
        f->next=p;
        p->a=ai;
        p->n=ni;
        last=p;
        last->next=NULL;
        }
    }
    }
    }
    }
    }
    q=list;
    while(q!=NULL){
    printf("%d ",q->a);
    printf("%d ",q->n);
    q=q->next;
    free(q->last); // @@ [Attempting to free memory through q->last after q has been advanced leads to undefined behavior. Also, the loop frees nodes incorrectly and may double-free or access freed memory.]
    }
    
    
    
    


    
    
    
    
    return 0;
}