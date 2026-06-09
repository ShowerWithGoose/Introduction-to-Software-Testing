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
        searchbst(root,leaf[i].data1); // @@ [searchbst uses global count1 which is not reset properly between calls; also, it assumes the key exists and overwrites count1=0 only on match, causing incorrect height calculation.]
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
        num++;
    }
}
void searchbst(BTNodeptr p,int key)
{
    if(p!=NULL)
    {
        count1++; // @@ [count1 is a global variable and accumulates across recursive calls and different invocations of searchbst, leading to incorrect height values. Height should be computed per search path, not globally.]
        if((key==p->data))
        {
            leaf[num1].count=count1;
            num1++;
            count1=0; // @@ [Resetting count1 here only works if every search ends in a match, but if multiple searches are done, leftover state from previous calls corrupts results. Also, num1 may not correspond to the correct leaf index.]
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