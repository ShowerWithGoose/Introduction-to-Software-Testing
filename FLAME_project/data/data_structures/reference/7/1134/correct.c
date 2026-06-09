#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define NodeNum  100

typedef struct TreeNode *BinTree;
struct TreeNode{
    int Data;
    int layer;
    BinTree left;
    BinTree right;
};
void visit(BinTree t)
{
    if(t->left==NULL&&t->right==NULL)
    {
        printf("%d %d\n",t->Data,t->layer);
    }
    
}
void  dlrorder(BinTree t)
{
      if(t!=NULL){
            visit(t);      
             dlrorder(t->left);
             dlrorder(t->right);
       }
}

void  ldrorder(BinTree t)
{
      if(t!=NULL){
             ldrorder(t->left);
             visit(t);      
             ldrorder(t->right);
       }
}

void  lrdorder(BinTree t)
{
      if(t!=NULL){
             lrdorder(t->left);
             lrdorder(t->right);
             visit(t);       
      }
}
BinTree tree[NodeNum],p;
int main()
{
    
    int num[NodeNum];
    
    int i=1,rec,q,flag=0;
    int n;
    scanf("%d",&n);
   for( i=1;i<=n;i++)
   {
       scanf("%d",&num[i]);
   }
    
    tree[1]=(BinTree)malloc(sizeof(struct TreeNode));
    tree[1]->Data=num[1];
    tree[1]->left=NULL;
    tree[1]->right=NULL;
    tree[1]->layer=1;
   int lay;
    for(int i=2;i<=n;i++)
    {
        flag=0;
        q=1;
        lay=1;
        do {
            if(num[i]<tree[q]->Data)
            {
                if(tree[2*q]!=NULL)
                {
                    q*=2;
                    lay++;
                }
                else{
                    tree[2*q]=(BinTree)malloc(sizeof(struct TreeNode));
                    tree[2*q]->left=NULL;
                    tree[2*q]->right=NULL;
                    tree[2*q]->Data=num[i];
                    tree[2*q]->layer=lay+1;
                    tree[q]->left=tree[2*q];
                    flag=1;
                    break;
                }

            }
            else {
                if(tree[2*q+1]!=NULL)
                {
                    q=q*2+1;
                    lay++;
                }
                else{
                    tree[2*q+1]=(BinTree)malloc(sizeof(struct TreeNode));
                    tree[2*q+1]->left=NULL;
                    tree[2*q+1]->right=NULL;
                    tree[2*q+1]->Data=num[i];
                    tree[2*q+1]->layer=lay+1;
                    tree[q]->right=tree[2*q+1];
                    flag=1;
                    break;
                }
            }
        }while(!flag);
    }
    lrdorder(tree[1]);


    return 0;
}
