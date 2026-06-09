#include<stdio.h>
#include<stdlib.h>
struct tree
{
    struct tree *left;
    int num;
    struct tree *right;
    int hight;
};
typedef struct tree Tree;
Tree* creattree(Tree* tree,int t,int hight)
{ 
    if(tree==NULL)
    {
        tree=(Tree*)malloc(sizeof(Tree));
        tree->num=t;
        tree->left=NULL;
        tree->right=NULL;
        tree->hight=hight;    
    }
    else{
        if(t<tree->num)
        {
            tree->left=creattree(tree->left,t,hight+1);
        }
        if(t>=tree->num){
            tree->right=creattree(tree->right,t,hight+1);
        }
    }
    return tree;
}
void outputleaf(Tree* tree)
{
    if(tree!=NULL)
    {
       if(tree->left==NULL&&tree->right==NULL) printf("%d %d\n",tree->num,tree->hight);
        else{
            outputleaf(tree->left);
            outputleaf(tree->right);
        } 
    }   
}
int main()
{
    int n,i; 
    Tree *treeroot=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        treeroot=creattree(treeroot,t,1);
    } 
    outputleaf(treeroot);
}
