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
            p->step++; // @@ [The height (step) is incremented before attaching to parent, but it should be set as parent's step + 1. Repeated increments occur when traversing multiple levels due to recursive calls modifying the same node's step.]
            tmp->left=p;printf("line 44,d %d s %d\n",p->data,p->step);
            return;
        }
        else    {
            p->step++; // @@ [Same issue: step is being incremented on every recursive call, leading to incorrect height calculation. The node's step should not be modified during traversal; instead, it should be assigned based on the parent's step when inserted.]
            addco(p,tmp->left);
        }        
    }
    if(p->data>=tmp->data)    {
        if(tmp->right==NULL){
            p->step++;printf("line 54,d %d s %d\n",p->data,p->step); // @@ [Same error: step is incremented just before assignment, but if the node went through multiple comparisons, step has already been incremented multiple times incorrectly.]
            tmp->right=p;
            return;
        }
        else    {
            p->step++; // @@ [Same root cause: modifying p->step during traversal leads to overcounting the height.]
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