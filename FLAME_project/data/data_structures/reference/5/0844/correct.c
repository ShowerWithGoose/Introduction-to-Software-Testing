#include<stdio.h>
#include<stdlib.h>

typedef struct Node *Node;

struct Node{
    int coe;
    int deg;
    Node next;
};

Node createNode(){
    Node a=malloc(sizeof(struct Node));
    a->next=NULL;
    return a;
}
void Insert(Node New,Node P){
    Node tmp=P->next;
    P->next=New;
    New->next=tmp;
}
void addNode(Node New,Node P){
    Node ptr=P;

    while(ptr->next!=NULL&&ptr->next->deg>New->deg){
        ptr=ptr->next;
    }

    if(ptr->next==NULL){
        ptr->next=New;
    }
    else if(ptr->next->deg==New->deg){
        ptr->next->coe+=New->coe;
        free(New);
    }
    else if(ptr->next->deg<New->deg){
        Insert(New,ptr);
    }
}
void printPoly(Node P){
    for(Node i=P->next;i!=NULL;i=i->next){
        if(i->coe==0)continue;
        printf("%d %d ",i->coe,i->deg);
    }
}
int main(void){
    Node poly1,poly2,poly3;
    poly1=createNode();
    poly2=createNode();
    poly3=createNode();

    Node ptr=poly1;
    while(1){
        ptr->next=createNode();
        ptr=ptr->next;
        scanf("%d %d",&ptr->coe,&ptr->deg);
        char c=getchar();
        if(c=='\n')break;
    }

    ptr=poly2;
    while(1){
        ptr->next=createNode();
        ptr=ptr->next;
        scanf("%d%d",&ptr->coe,&ptr->deg);
        char c=getchar();
        if(c=='\n')break;
    }

    for(Node i=poly1->next;i!=NULL;i=i->next){
        for(Node j=poly2->next;j!=NULL;j=j->next){
            Node New=createNode();
            New->coe=i->coe*j->coe;
            New->deg=i->deg+j->deg;
            addNode(New,poly3);
        }
    }

    printPoly(poly3);

    return 0;
}
