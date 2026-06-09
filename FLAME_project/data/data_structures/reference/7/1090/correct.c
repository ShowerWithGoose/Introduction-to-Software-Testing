#include<stdio.h>
#include<stdlib.h>//没有这个会malloc报错
struct node{
  int data;
  struct node *left,*right;
  int depth;
};
typedef struct node Tree,*ptr;

ptr insertBST(ptr p,int item,int depth);
ptr searchLeaf(ptr t);//遍历叶结点

int n;
ptr root=NULL;

int main()
{
  int i=0;
  int num;

  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&num);
    root=insertBST(root,num,1);//建立树
  }
  //遍历每一个叶结点
  searchLeaf(root);
  return 0;
}

ptr insertBST(ptr p,int item,int depth)//建立一棵查找二叉树
{
  if(p==NULL){
    p=(ptr)malloc(sizeof(struct node));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    p->depth=depth;
  }
  else if(item<p->data)
  {p->left=insertBST(p->left,item,depth+1);}
  else if(item>=p->data)
  {p->right=insertBST(p->right,item,depth+1);}
  return p;
}

ptr searchLeaf(ptr t)
{
    if(t!=NULL)
  {
       if(t->left!=NULL)
    {
      searchLeaf(t->left);
    }

    if(t->left==NULL&&t->right==NULL)
    {
      printf("%d %d\n",t->data,t->depth);
    }
 
    if(t->right!=NULL)
    {
      searchLeaf(t->right);
    }
  }
}



