#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define ull unsigned long long

struct node
{
    int data;
    struct node*lchild,*rchild;
};
typedef struct node BTNode,*BTNodeptr;
int dep=1;
BTNodeptr insertBST(BTNodeptr,int);
void pre(BTNodeptr);


int main()
{
	int n,num;
    BTNodeptr root=NULL;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
       root= insertBST(root,num);
    }
    pre(root);
    return 0;
        
}

BTNodeptr insertBST(BTNodeptr R,int item)
{
    if(R==NULL)
    {
        R=(BTNodeptr)malloc(sizeof(BTNode));
        R->data=item;
        R->lchild=R->rchild=NULL;
    }
    else if(item<R->data)
    {
        R->lchild=insertBST(R->lchild,item);
    }
    else if(item>=R->data)
    {
        R->rchild=insertBST(R->rchild,item);
    }
    return R;
}

void pre(BTNodeptr R)
{
    if(R==NULL)return;
    else 
    {
        if((R->lchild==NULL)&&(R->rchild==NULL))
        
            printf("%d %d\n",R->data,dep);
            dep++;
        
        pre(R->lchild);
        pre(R->rchild);
        dep--;//!!
    }
}
