#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
    int data;
    int step;
    struct node *left;
    struct node *right;
};
typedef struct node co;
co* getco(int num);
void addco(co* p,co* tmp);
void searchLeave(co* roof);
int main()
{
    int n,num;
    scanf("%d",&n);
    co* roof=NULL;
    co* p=NULL; 
    while(n--)    {
        scanf("%d",&num);//printf("%d",num);
        p=getco(num);
        if(roof==NULL)
            roof=p;
        else
            addco(p,roof);
    }
    searchLeave(roof);
    return 0;
}
co* getco(int num)
{
    co*p=(co*)malloc(sizeof(co));
    p->data=num;
    p->left=NULL;
    p->right=NULL;
    p->step=1;
    return p;
}
void addco(co* p,co* tmp)
{
    if(p->data<tmp->data)    {
        if(tmp->left==NULL){
            p->step = tmp->step + 1; // @@ The height of the new node should be the parent's height + 1. The original code incorrectly incremented the node's own step variable recursively or statically, failing to propagate the correct depth from the root.
            tmp->left=p;printf("line 44,d %d s %d\n",p->data,p->step);
            return;
        }
        else    {
            addco(p,tmp->left); // @@ Removed incorrect increment. The step calculation is now handled at the insertion point based on the parent's step.
        }        
    }
    if(p->data>=tmp->data)    {
        if(tmp->right==NULL){
            p->step = tmp->step + 1; // @@ The height of the new node should be the parent's height + 1.
            tmp->right=p;printf("line 54,d %d s %d\n",p->data,p->step);
            return;
        }
        else    {
            addco(p,tmp->right); // @@ Removed incorrect increment. The step calculation is now handled at the insertion point based on the parent's step.
        }
    }
}
void searchLeave(co* roof)
{
    if(roof==NULL)
        return;    
    else if((roof->left)==NULL&&(roof->right)==NULL)    {
        printf("%d %d\n",roof->data,roof->step);
        return;
    }
    else    {
        searchLeave(roof->left);
        searchLeave(roof->right);
    }
    
}