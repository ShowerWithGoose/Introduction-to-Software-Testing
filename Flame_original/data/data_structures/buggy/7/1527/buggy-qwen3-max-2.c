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
            p->step++; // @@ [The height (step) is incremented before attaching, but it should reflect the depth from root. However, the real error is that 'step' is being modified multiple times during recursive descent, leading to overcounting. Each recursive call increments 'step', so the final value becomes more than actual depth.]
            tmp->left=p;printf("line 44,d %d s %d\n",p->data,p->step);
            return;
        }
        else    {
            p->step++; // @@ [Same issue: 'step' is incremented on every recursive call, causing incorrect height calculation. The height should be set based on parent's height + 1, not by repeatedly incrementing the same node's step during traversal.]
            addco(p,tmp->left);
        }        
    }
    if(p->data>=tmp->data)    {
        if(tmp->right==NULL){
            p->step++;printf("line 54,d %d s %d\n",p->data,p->step); // @@ [Same over-incrementation problem: 'step' has already been incremented in previous recursive calls, and this adds yet another increment, making height too large.]
            tmp->right=p;
            return;
        }
        else    {
            p->step++; // @@ [Again, incorrect repeated increment of 'step'. This leads to height values that are much larger than the actual tree depth.]
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