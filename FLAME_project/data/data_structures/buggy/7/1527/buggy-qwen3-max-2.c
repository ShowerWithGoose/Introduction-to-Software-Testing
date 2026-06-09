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
            p->step++; // @@ [The height (step) of the new node should be tmp->step + 1, not incrementing p->step which starts at 1. This leads to incorrect height calculation.]
            tmp->left=p;printf("line 44,d %d s %d\n",p->data,p->step);
            return;
        }
        else    {
            p->step++; // @@ [Same issue: p->step is being incremented during traversal, but it should reflect depth from root, not number of moves. Correct approach is to set p->step = tmp->step + 1 when attaching.]
            addco(p,tmp->left);
        }        
    }
    if(p->data>=tmp->data)    {
        if(tmp->right==NULL){
            p->step++;printf("line 54,d %d s %d\n",p->data,p->step); // @@ [Same error: height should be tmp->step + 1, not p->step++.]
            tmp->right=p;
            return;
        }
        else    {
            p->step++; // @@ [Same error: incorrect height propagation by incrementing p->step instead of setting based on parent's height.]
            addco(p,tmp->right);
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