#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node1{
    int data1;
    int count;
};
struct node1 leaf[100];
int count,num,num1,count1; // @@ [Global variables are uninitialized, leading to undefined behavior when used as counters]
typedef struct node BTNode;
typedef struct node* BTNodeptr;
BTNodeptr insertbst(BTNodeptr p,int a);
void visit(BTNodeptr t);
void preorder(BTNodeptr m);
void searchbst(BTNodeptr p,int key);
BTNodeptr root=NULL;
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        root=insertbst(root,a);
    }
    preorder(root);
    for (int i=0;i<num;i++)
    {
        searchbst(root,leaf[i].data1); // @@ [searchbst resets count1 only after finding the key, but count1 is global and not reset before each call, causing incorrect height calculation]
        printf("%d %d\n",leaf[i].data1,leaf[i].count);
    }
    return 0;
}
BTNodeptr insertbst(BTNodeptr p,int a)
{
    if(p==NULL)
    {
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=a;
        p->left=p->right=NULL;
    }
    else if(a<p->data)
    {
        p->left=insertbst(p->left,a);
    }
    else if(a>=p->data)
    {
        p->right=insertbst(p->right,a);
    }
    return p;
}
void preorder(BTNodeptr m)
{
    if(m!=NULL)
    {
        visit(m);
        preorder(m->left);
        preorder(m->right);
    }
}
void visit(BTNodeptr t)
{
    if((t->left==NULL)&&(t->right==NULL))
    {
        leaf[num].data1=t->data;
        num++; // @@ [num is uninitialized; using it as an index leads to undefined behavior]
    }
}
void searchbst(BTNodeptr p,int key)
{
    if(p!=NULL)
    {
        count1++; // @@ [count1 is global and not initialized before each search, so it accumulates across calls, giving wrong height]
        if((key==p->data))
        {
            leaf[num1].count=count1;
            num1++; // @@ [num1 is uninitialized; using it as an index leads to undefined behavior]
            count1=0; // @@ [Resetting count1 here doesn't help because it's already corrupted by previous calls]
        }
        else if(key<p->data)
        {
            searchbst(p->left,key);
        }
        else if(key>=p->data)
        {
            searchbst(p->right,key);
        }
    }
}