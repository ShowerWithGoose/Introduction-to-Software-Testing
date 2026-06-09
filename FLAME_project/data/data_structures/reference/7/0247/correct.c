#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tree{
  int a;
struct tree *l;
struct tree *r;
int h;
};
typedef struct tree p,*pp;
pp make(pp root,int num,int len)
{
  len++;
if(root==NULL)
{
   root  = (pp)malloc(sizeof(p));
   memset(root,0,sizeof(p));
   root->h=len;
   root->a=num;
   root->l=NULL;
   root->r=NULL;
}
else{
if(num<root->a)
{
  root->l=make(root->l,num,len);
}
else if(num>=root->a)
{
  root->r=make(root->r,num,len);
}
}
return root;
}
void preorder(pp root)
{
  if(root!=NULL)
  {
    if(root->l==NULL&&root->r==NULL)
    {
      printf("%d %d\n",root->a,root->h);
    }
    else
    {
      preorder(root->l);
      preorder(root->r);
    }
  }
}
int main()
{
  int len = 0;
  pp root=NULL;
  int n;
  scanf("%d",&n);
  int num1;
  for(int i=0;i<n;i++)
  {
    scanf("%d",&num1);
    root = make(root,num1,len);
    len=0;
  }
  preorder(root);
  return 0;
}
