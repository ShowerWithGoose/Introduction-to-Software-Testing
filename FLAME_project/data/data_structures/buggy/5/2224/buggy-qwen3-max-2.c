#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct NUM{
    int a;
    int b;
    struct NUM *link;
}num,*pnum;
pnum Creatnode(int a,int b){
    pnum p;
    p=(pnum)malloc(sizeof(num));
    p->a=a;
    p->b=b;
    p->link=NULL;
    p->link->link=NULL; // @@ Dereferencing NULL pointer: p->link is NULL, so p->link->link is invalid and causes runtime error.
    p->link->link->link=NULL; // @@ Same issue: continuing to dereference NULL pointers.
    p->link->link->link->link=NULL; // @@ Same issue: multiple levels of NULL dereference.
    return p;
}
pnum Creatlist(){
    pnum p=NULL,q=NULL,list=NULL;
    int a=0,b=0;
    while(scanf("%d %d",&a,&b)!=EOF){
        char c=getchar();
        p=Creatnode(a,b);
        if(list==NULL){
            list=q=p;
        }else{
            q->link=p;
            q=p;
        }
        if(c=='\n'){
            break;
        }
    }
    return list;
}
pnum CreatEndlist(pnum list1,pnum list2){
    pnum p=list2,q=list1,f=NULL,h=NULL;
    pnum list3=NULL;
    while(q!=NULL){
        while(p!=NULL){
            int a=q->a*p->a,b=q->b+p->b;
            f=Creatnode(a,b);
            if(list3==NULL){
                list3=h=f;
            }else{
                h->link=f;
                h=f;
            }
            p=p->link;
        }
        p=list2;
        q=q->link;
    }
    return list3;
}
pnum Endcmp(pnum list){
        int i=0;
    do{
i=0;
    pnum p=list,q=p->link,h=q->link; // @@ If list has less than 3 nodes, q or h could be NULL, leading to NULL dereference in loop condition or body.
        do{
            if(q->b<h->b){ // @@ If h is NULL (e.g., only two nodes), this causes runtime error.
            p->link=h;
            q->link=h->link;
            h->link=q;
            i++;
            p=h;
            h=q->link; 
        }else{
            p=q;
            q=h;
            h=h->link; 
        }
        }while(h!=NULL);
    }while(i!=0);
    return list;
}
void Endlist(pnum list){
    pnum p=list->link; // @@ If list is NULL or only has one node (dummy head), list->link may be NULL, but loop assumes at least one valid node. Also, if multiplication result is zero polynomial, nothing should print, but this may crash or misbehave.
    while(p!=NULL){
        printf("%d %d ",p->a,p->b);
        p=p->link;
    }
}
pnum Enddiff(pnum list){
    pnum p=list,q=p->link,h=q->link; // @@ If list has fewer than 3 nodes, h may be NULL, causing crash in loop condition or body.
    do{
        if(q->b==h->b){ // @@ If h is NULL, this causes runtime error.
            q->a=q->a+h->a;
            q->link=h->link;
            h=h->link;
        }else{
            q=h;
            h=h->link;
        }
    }while(h!=NULL);
    return list;
}
int main(){
    pnum list1=NULL,list2=NULL,list3=NULL;
    list1=Creatlist();
    list2=Creatlist();
    list3=Creatnode(0,0); // @@ Creates a dummy node with (0,0), which may interfere with polynomial representation and merging logic.
    list3->link=CreatEndlist(list1,list2);
    list3=Endcmp(list3);
    list3=Enddiff(list3);
    Endlist(list3);
}