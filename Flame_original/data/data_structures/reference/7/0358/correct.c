#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
//#include<windows.h>
#include<ctype.h>

typedef struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int depth;
}Tree,*Treep;

Treep rootnode = NULL;

void visit(Treep t)
{
    if(t!=NULL)
    {
        if(t->left==NULL && t->right==NULL)
        	printf("%d %d\n",t->val,t->depth);
        else
            {visit(t->left);visit(t->right);}
    }
}

void insert(Treep *t,int value,int depth)
{
    if(*t==NULL)
    {
        *t=(Treep)malloc(sizeof(Treep));
        (*t)->left=(*t)->right=NULL;
		(*t)->val=value;
		(*t)->depth=depth;
    }
    
    else
    {
        if((*t)->val <= value)//right
        {
            insert(&((*t)->right),value,depth+1);
        }
        if((*t)->val > value)//left 
        {
            insert(&((*t)->left),value,depth+1);
        }
    }
}

int main()
{
    int n,i,treevalue;
    Treep root = NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&treevalue);
        insert(&root,treevalue,1);
    }
    visit(root);
    //system("pause");
    return 0;
}



