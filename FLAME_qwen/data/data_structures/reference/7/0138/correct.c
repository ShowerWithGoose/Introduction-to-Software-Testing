#include<time.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define eps 1e-5
#define datatype int
typedef struct BTnode{
	datatype data ;
	struct BTnode *lchild;		
	struct BTnode *rchild;
}btnode,*BiTree;

void Initial(BiTree T){
	T=NULL;
} 

void Preorder(BiTree T,int h){
	if(T==NULL) return ;
	else {
		///////do anything you want
		if(T->lchild==NULL&&T->rchild==NULL){
			printf("%d %d\n",T->data,h); 
			free(T);
			return;
		}
		Preorder(T->lchild,h+1);
		Preorder(T->rchild,h+1); 
	}
}
BiTree T;
int main()
{
	int n,x,i;
	
	btnode *p;
	Initial(T);///PROBLEM?    要记得初始化指针时 要想改动原函数的值 你需要以地址参数来传递 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(T==NULL){
			T=(BiTree)malloc(sizeof(btnode));
			T->data=x;////这里需要把了lchild rchild初始化吗
			//T->lchild=NULL;
			//T->rchild=NULL;
			p=T; 
		}
		else{
			while(1){
				if(x<p->data){
					if(!(p->lchild)) {
						p->lchild=(BiTree)malloc(sizeof(btnode));
						p->lchild->data=x;
						//p->lchild->lchild=NULL;
						//p->lchild->rchild=NULL;//if need? 
						p=T;
						break;
					}
					p=p->lchild;
				}
					
				else {
					if(!(p->rchild)) {
						p->rchild=(BiTree)malloc(sizeof(btnode));
						p->rchild->data=x;
						//p->rchild->lchild=NULL;
					//	p->rchild->rchild=NULL; 
						p=T;
						break;
					}
					p=p->rchild;
				}
			} 
		
		}
	}
	Preorder(T,1);
	//free(T);
	return 0;
}


