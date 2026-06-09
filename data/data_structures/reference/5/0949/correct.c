#include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>
typedef struct node{
    int c,r;
    struct node *next;
}Linklist;
Linklist *listC;
Linklist *headC;
void read();
void Free(Linklist *p);
void Create(int C,int R);
int main()
{
    listC=(Linklist *)malloc(sizeof(Linklist));
    headC=listC;
    headC->next=NULL;
    read();
    listC=headC->next;
    while(listC!=NULL)
    {
        if(listC->c!=0)printf("%d %d ",listC->c,listC->r);
        listC=listC->next;
    }
    Free(headC);
    return 0;
}
void Free(Linklist *p)
{
    Linklist *cur=p;
    while(cur!=NULL){
        Linklist *nex=cur->next;
        free(cur);
        cur=nex;
    }
}
void Create(int C,int R)
{
    Linklist *cur=headC->next;
    if(cur==NULL)
    {
        Linklist *temp=(Linklist *)malloc(sizeof(Linklist));
        headC->next=temp;
        temp->c=C;
        temp->r=R;
        temp->next=NULL;
        return;
    }
    cur=headC;
    if(cur->next!=NULL&&R>(cur->next->r))
    {
        Linklist *temp=(Linklist *)malloc(sizeof(Linklist)),*cur1;
        cur1=headC->next;
        headC->next=temp;
        temp->next=cur1;
        temp->c=C;
        temp->r=R;
        return;
    }
    while(cur->next!=NULL&&R<(cur->next->r))cur=cur->next;
    if(cur->next!=NULL&&(cur->next->r)==R)
    {
        cur->next->c+=C;
    }
    else{
        Linklist *temp=(Linklist *)malloc(sizeof(Linklist)),*cur1;
        if(cur->next!=NULL){
            cur1=cur->next;
            cur->next=temp;
            temp->next=cur1;
        }
        else {
            cur->next=temp;
            temp->next=NULL;
        }
        temp->c=C;
        temp->r=R;
        
    }
}
void read()
{
    Linklist *listA=(Linklist *)malloc(sizeof(Linklist)),*headA=listA;
    Linklist *listB=(Linklist *)malloc(sizeof(Linklist)),*headB=listB;
    int c1,r1;
    while(1)
    {
        scanf("%d%d",&c1,&r1);
        Linklist *temp=(Linklist *)malloc(sizeof(Linklist));
        listA->c=c1;
        listA->r=r1;
        listA->next=temp;
        listA=listA->next;
        if(getchar()=='\n')break;
    }
    while(1)
    {
        scanf("%d%d",&c1,&r1);
        Linklist *temp=(Linklist *)malloc(sizeof(Linklist));
        temp->next=NULL;
        listB->c=c1;
        listB->r=r1;
        listB->next=temp;
        listB=listB->next;
        if(getchar()=='\n')break;
    }
    Linklist *cur1=headA,*cur2=headB;
    int R,C;
    while(cur1!=NULL&&cur1->c!=0)
    {
        while(cur2!=NULL&&cur2->c!=0)
        {
            C=cur1->c*cur2->c;
            R=cur1->r+cur2->r;
            Create(C,R);
            cur2=cur2->next;
        }
        cur1=cur1->next;
        cur2=headB;
    }
    Free(headA);
    Free(headB);
}


