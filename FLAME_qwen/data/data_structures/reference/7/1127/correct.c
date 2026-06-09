#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <assert.h>
typedef struct tree
{
  int data;
  int depth;
  struct tree *lchild,*rchild;
}tree;
tree* create(tree * r,int d);
void printtree(tree* r);
int dp;
int main() 
{ 
    int i=0,j=0,k=0,m=0,n=0,x=0,y=0,z=0,flag=0;
    tree *t;
    t=NULL;
    int hold=0,dep=0;
    scanf("%d ",&n);
    while(n--)
    {
      scanf("%d",&hold);
      dp=0;
      t=create(t,hold);
    }
    printtree(t);
    system("pause");
    return 0; 
} 
tree* create(tree * r,int d)
{
  if(r==NULL)
  {
    r=(tree*)malloc(sizeof(tree));
    r->data=d;
    r->lchild=NULL;
    r->rchild=NULL;
    dp++;
    r->depth=dp;
    
  }
  else 
  {
    if(d<r->data)
    {
       dp++;
       r->lchild=create(r->lchild,d);   
    }
    else
    {
      dp++;
      r->rchild=create(r->rchild,d);
    }
    
  }
  return r;
}
void printtree(tree* r)
{
  if(r!=NULL)
  {
    if(r->lchild==NULL&&r->rchild==NULL)
    {
      printf("%d %d\n",r->data,r->depth);
    }
    printtree(r->lchild);
    printtree(r->rchild);
  }
}



