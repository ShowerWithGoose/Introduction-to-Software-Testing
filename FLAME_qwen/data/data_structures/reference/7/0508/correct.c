#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define eps 1e-10
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define arraynum(x) (sizeof(x)/sizeof(x[0]))
#define Malloc(type,size) (type *)malloc(sizeof(type)*size)
#define MAX 100
typedef struct bitnode
{
    int data;
    int depth;
    struct bitnode *left;
    struct bitnode *right;
}BitNode,*BitTree;
BitTree root=NULL;
typedef struct node
{
    BitTree Tree;
    struct node *next;
}LNode,*LinkList;

void InItem(LinkList *Front,LinkList *Rear,BitTree t);
BitTree OutItem(LinkList *Front,LinkList *Rear);
void InitTree(BitTree *t);
bool Isempty(BitTree t);
int TreeDepth(BitTree t);
void Visit(BitTree t);
int NodeDepth(BitTree t,BitTree l);
void PreOrder(BitTree t);
void PreOrder1(BitTree t);
void InOrder(BitTree t);
void LevelOrder(BitTree t);
void PostOrder(BitTree t);
BitTree Parent(BitTree t,BitTree l);
BitTree Sibling(BitTree t,BitTree l);
void DestroyTree(BitTree *t);
void InsertItem(BitTree *t,int temp,int depth);


int main()
{
    int n,temp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        InsertItem(&root,temp,1);
    }

    PreOrder(root);
    DestroyTree(&root);
    return 0;
}



void InItem(LinkList *Front,LinkList *Rear,BitTree t)
{
    LinkList p;
    p=(LinkList)malloc(sizeof(LNode));
    p->Tree=t;
    p->next=NULL;
    if((*Front)==NULL)
    {
        (*Front)=p;
    }
    else
    {
        (*Rear)->next=p;
    }
    (*Rear)=p;
}
BitTree OutItem(LinkList *Front,LinkList *Rear)
{
    LinkList p;
    BitTree item;
    if((*Front)==NULL)
    {
        printf("Empty Quene");
        return NULL;
    }
    else
    {
        p=(*Front);
        (*Front)=(*Front)->next;
        item=p->Tree;
        free(p);
        return item;
    }
}
void InitTree(BitTree *t)
{
    *t=NULL;
}
bool Isempty(BitTree t)
{
    if(t==NULL) return true;
    else return false;
}
int TreeDepth(BitTree t)
{
    int a,b;
    if(t==NULL) return 0;
    a=TreeDepth(t->left)+1;
    b=TreeDepth(t->right)+1;
    return a>b?a:b;
}

void Visit(BitTree t)
{
    printf("%d\n",t->data);
}
int NodeDepth(BitTree t,BitTree l)//begin from 1
{
    BitTree p=l;
    int depth=1;
    while(p!=t)
    {
        p=Parent(t,p);
        depth++;
    }
    return depth;
}
void PreOrder(BitTree t)
{
    if(t!=NULL)
    {
        if(t->left==NULL&&t->right==NULL)
        {
            printf("%d %d\n",t->data,t->depth);
        }
        PreOrder(t->left);
        PreOrder(t->right);
    }
}
void PreOrder1(BitTree t)
{
    if(t!=NULL)
    {
        //Visit(t);
        PreOrder1(t->left);
        PreOrder1(t->right);
    }
}
void InOrder(BitTree t)
{
    if(t!=NULL)
    {
        InOrder(t->left);
        Visit(t);
        InOrder(t->right);
    }
}

void LevelOrder(BitTree t)
{
    LinkList Front=NULL,Rear=NULL;
    BitTree l;
    InItem(&Front,&Rear,t);
    while(Front!=NULL)
    {
        l=OutItem(&Front,&Rear);
        Visit(l);
        if(l->left!=NULL) InItem(&Front,&Rear,t->left);
        if(l->right!=NULL) InItem(&Front,&Rear,t->right);
    }
}
void PostOrder(BitTree t)
{
    if(t!=NULL)
    {
        PostOrder(t->left);
        PostOrder(t->right);
        Visit(t);
    }
}
BitTree Parent(BitTree t,BitTree l)
{
    if(t!=NULL)
    {
        if(t->left==l||t->right==l) return t;
        PreOrder1(t->left);
        PreOrder1(t->right);
    }
    return NULL;
}
BitTree Sibling(BitTree t,BitTree l)
{
    BitTree p;
    p=Parent(t,l);
    if(p==NULL) return NULL;
    else if(p->left==l) return p->right;
    else return p->left;
}

void DestroyTree(BitTree *t)
{
    BitTree l;
    if((*t)!=NULL)
    {
        DestroyTree(&((*t)->left));
        DestroyTree(&((*t)->right));
        l=*t;
        free(l);
    }
}

void InsertItem(BitTree *t,int temp,int depth)
{
    BitTree q=*t;
    if(*t==NULL)
    {
        q=(BitTree)malloc(sizeof(BitTree));
        q->left=q->right=NULL;
        q->data=temp;
        q->depth=depth;
        *t=q;
    }
    else if(temp<q->data)
        InsertItem(&(q->left),temp,depth+1);
    else InsertItem(&(q->right),temp,depth+1);
}

