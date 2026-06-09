#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef int datatype;
struct node
    {
    datatype data;
    struct node *left,*right;
    };
typedef struct node Node,*ptr;

ptr insert(ptr p,datatype item);


void xianxu(ptr zhen,int i)
    {
    if(zhen==NULL)
	  {
	  	i-=1;
	  return;//返回上一节点
	  }
    if(zhen->left==NULL&&zhen->right==NULL)
	  {
	 // printf("%d %d\n",zhen->data,//j);
	 printf("%d %d\n",zhen->data,i);
	  }
    xianxu(zhen->left,i+1);
    xianxu(zhen->right,i+1);
    }

int main()
    {
    int i,t;
    int n;
    ptr root=NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++)
	  {
	  scanf("%d",&t);
	  root=insert(root,t);
	  }//至此构建完了一颗完整的二叉树
//接下来先序遍历根节点
    xianxu(root,1);
    return 0;
    }
ptr insert(ptr p,datatype item)
    {
    if(p==NULL)
	  {
	  p=(ptr)malloc(sizeof(Node));
	  p->data=item;
	//  p->num=1;
	  p->left=p->right=NULL;
	  }
    else if(item<p->data)
	  {
	  p->left=insert(p->left,item);
	  }
    else if(item>p->data)
	  {
	  p->right=insert(p->right,item);
	  }
    else //插入数与根节点一样大时
	  {
	  p->right=insert(p->right,item);
	  }
    return p;
    }

