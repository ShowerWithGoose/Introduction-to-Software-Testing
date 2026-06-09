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
            p->step++; // @@ [The height (step) is incremented before attaching, but it should reflect the depth from root. However, the real issue is that 'step' is being modified multiple times during recursive descent, leading to overcounting. The increment should happen based on parent's step, not by repeatedly incrementing during traversal.]
            tmp->left=p;printf("line 44,d %d s %d\n",p->data,p->step);
            return;
        }
        else    {
            p->step++; // @@ [Same error: step is incremented at every recursive call, causing incorrect height calculation. Height should be parent's height + 1, not cumulative increments during descent.]
            addco(p,tmp->left);
        }        
    }
    if(p->data>=tmp->data)    {
        if(tmp->right==NULL){
            p->step++;printf("line 54,d %d s %d\n",p->data,p->step); // @@ [Same error: step is incremented again here, compounding the overcounting issue.]
            tmp->right=p;
            return;
        }
        else    {
            p->step++; // @@ [Same error: repeated increment leads to wrong height values.]
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