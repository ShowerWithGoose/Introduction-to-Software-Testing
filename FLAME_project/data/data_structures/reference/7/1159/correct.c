#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int n,t,i,time,tem1,tem2;
typedef struct tree{
	int num;
	struct tree *lchild;
	struct tree *rchild;
	int depth;
}tree,*treep ; 
treep root=NULL;
treep createtree(treep temp,int t,int dep);
void inorder(treep temp);
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		root=createtree(root,t,1);
		
	}
	inorder(root);	
return 0;
}

treep createtree(treep temp,int t,int dep){
	if(temp==NULL){
		treep temp0=(treep)malloc(sizeof(tree));
		temp=temp0;
		temp->lchild=NULL;
		temp->rchild=NULL;
		temp->num=t;
		temp->depth=dep;
	}
	else if(t<temp->num){
		dep++;
		temp->lchild=createtree(temp->lchild,t,dep);
	}
	else if(t>=temp->num){
		dep++;
		temp->rchild=createtree(temp->rchild,t,dep);
	}
	return temp;
}//创建二叉排序树 



void inorder(treep temp){
		if(temp->lchild!=NULL){
			inorder(temp->lchild);
		}
		if(temp->lchild==NULL&&temp->rchild==NULL){
			printf("%d %d\n",temp->num,temp->depth);
		}
		if(temp->rchild!=NULL){
			inorder(temp->rchild);
		}
}//中序遍历输出 

