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
            addco(p,roof); // @@ [The function call passes arguments in wrong order: should be addco(roof, p) or adjust function definition accordingly. As implemented, 'p' (new node) is passed as first argument and 'tmp' (root) as second, but inside addco, 'tmp' is treated as current tree node and 'p' as new node to insert. However, the recursive calls pass 'p' unchanged and increment its step multiple times during traversal, leading to incorrect height calculation.]
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
            p->step++; // @@ [Incrementing step here is incorrect because step was already incremented during traversal. This leads to double increment at insertion point. The step should only be set based on parent's step + 1, not by incrementing during each recursive call.]
            tmp->left=p;printf("line 44,d %d s %d\n",p->data,p->step);
            return;
        }
        else    {
            p->step++; // @@ [Incrementing p->step during traversal causes incorrect height accumulation. Each time we go down a level, we increment the same node's step, but if the path changes direction or backtracks (which it doesn't here due to recursion), this would be wrong. More critically, if both left and right conditions are checked (as they are, since no else), p->step may be incremented twice for the same node.]
            addco(p,tmp->left);
        }        
    }
    if(p->data>=tmp->data)    { // @@ [This should be 'else if' to prevent both branches from executing when p->data == tmp->data. As written, when equal, both left and right branches may be taken in sequence, causing double increment of p->step and potentially inserting the node in both subtrees (though insertion only happens once due to NULL checks, the step count becomes wrong).]
        if(tmp->right==NULL){
            p->step++;printf("line 54,d %d s %d\n",p->data,p->step); // @@ [Same issue: extra increment on top of traversal increments.]
            tmp->right=p;
            return;
        }
        else    {
            p->step++; // @@ [Same traversal increment error.]
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