#include<stdio.h>  
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct _node{
	int num;
	int high;
	int flag;
	struct _node *left,*right;
}node,*pnode;
pnode insertbst(pnode p,int m,int h);

void preorder(pnode root);
int main()
{ 
  int i,m,n,h=1;
  pnode p,root;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  	scanf("%d",&m);
  	root=insertbst(root,m,h);//建树 
  }
   preorder(root);//中序遍历输出叶节点 
return 0;
}
pnode insertbst(pnode p,int m,int h)
{
	
	if(p==NULL)
	{
		p=(pnode)malloc(sizeof(node));
		p->num=m;
		p->left=p->right=NULL;
		p->high=h;//记录层数 
		p->flag=1;//1表示为叶节点 
	}
	else if(m<p->num)
	{
		h++;
		p->left=insertbst(p->left,m,h);
		p->flag=0;
	}
	else if(m>=p->num)
	{
		h++;
		p->right=insertbst(p->right,m,h);
		p->flag=0;
	}
	return p;
 } 
 void preorder(pnode p)
 {
 	if(p!=NULL)
 	{
 		preorder(p->left);
 		if(p->flag==1)
 		{
 			printf("%d %d\n",p->num,p->high);
		}
		preorder(p->right);
	}
 }


