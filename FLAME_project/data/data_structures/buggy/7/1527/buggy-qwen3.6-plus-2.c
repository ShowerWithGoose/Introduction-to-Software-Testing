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
            p->step = tmp->step + 1; // @@ The height of the new node should be the parent's height + 1. The original code incorrectly incremented the node's own step (which was initialized to 1) by 1, resulting in a constant height of 2 for direct children, and incorrect cumulative logic for deeper nodes.
            tmp->left=p;printf("line 44,d %d s %d\n",p->data,p->step);
            return;
        }
        else    {
            addco(p,tmp->left); // @@ Removed p->step++ here because the step is correctly calculated at the insertion point (base case). Incrementing it during recursion leads to double counting or incorrect values depending on implementation. The height should only be set when the node is actually placed.
        }        
    }
    if(p->data>=tmp->data)    {
        if(tmp->right==NULL){
            p->step = tmp->step + 1; // @@ Similarly, the height of the new node should be the parent's height + 1.
            tmp->right=p;printf("line 54,d %d s %d\n",p->data,p->step);
            return;
        }
        else    {
            addco(p,tmp->right); // @@ Removed p->step++ here for the same reason as above. The height is determined at the point of insertion based on the parent's height.
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