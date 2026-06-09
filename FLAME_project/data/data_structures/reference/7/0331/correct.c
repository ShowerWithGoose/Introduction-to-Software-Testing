#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct btree
{
  int data;
  struct btree *left,*right;
  int h;
}*p,*q,*r;


struct btree* btreecreate(int key,struct btree* x,int hei)
{
  
  if (x==NULL)
  {
    x=(struct btree*)malloc(sizeof(struct btree));
    x->data=key;
    x->left=NULL;
    x->right=NULL;
    (x->h)=hei+1;
    return x;
  }
  else if (key<x->data)
  {
      x->left=btreecreate(key,x->left,++hei);
  }
  else if (key>=x->data)
  {
      x->right=btreecreate(key,x->right,++hei);
  }
 return x;
}
void btreeprint(struct btree* y)
{
   if (y!=NULL)
   {
      btreeprint(y->left);
      btreeprint(y->right);
      if (y->left==NULL&&y->right==NULL)
      {
        printf("%d %d\n",y->data,y->h);
      }
     
   }
   return;

}

int main()
{
    p=NULL;
   int n,key;
   scanf("%d",&n);
   for (int i = 0; i < n; i++)
   {
       scanf("%d",&key);
       p=btreecreate(key,p,0);
      
   }
   btreeprint(p);
   



    return 0;
}


