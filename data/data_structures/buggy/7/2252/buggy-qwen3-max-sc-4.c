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
int count,num,num1,count1; // @@ [Global variables are uninitialized, leading to undefined behavior when used (e.g., num, num1, count1). They should be initialized to 0.]
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
        searchbst(root,leaf[i].data1); // @@ [The function searchbst uses a global count1 that is not reset properly across calls, and it assumes the key exists and will be found exactly once, which may not hold if duplicates exist. Also, count1 is not initialized before each search.]
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
        num++; // @@ [num is uninitialized (global), so incrementing it leads to undefined behavior.]
    }
}
void searchbst(BTNodeptr p,int key)
{
    if(p!=NULL)
    {
        count1++; // @@ [count1 is uninitialized (global) and not reset before each call to searchbst in main, leading to incorrect height calculation.]
        if((key==p->data))
        {
            leaf[num1].count=count1; // @@ [num1 is uninitialized (global), so indexing leaf with it is undefined behavior. Also, this assigns count only after finding the node, but doesn't handle duplicates correctly or ensure it's the correct path.]
            num1++;
            count1=0;
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