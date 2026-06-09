#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	int depth;
	struct node *lchild,*rchild;
};
typedef struct node *BTNodeptr;
BTNodeptr t,p,q;
int i,j,k;
int n; 
BTNodeptr print_tree(BTNodeptr t){
	if(t==NULL){
		return NULL;
		
	}
	if(t->lchild==NULL&&t->rchild==NULL){
		printf("%d %d\n",t->data,t->depth);
		
	}
	print_tree(t->lchild);
	print_tree(t->rchild);
	return NULL;
}
int main(){
	scanf("%d",&n);
	int dep=0;
	for(i=0;i<n;i++){
		p=(BTNodeptr)malloc(sizeof(BTNodeptr));
		p->lchild=p->rchild=NULL;
		scanf("%d",&p->data);
		if(t==NULL){
			p->depth=1;
			t=q=p;//在空树上建立结点
		    dep=t->depth;
			continue; 
		}
		else if(t!=NULL){
			for(j=0;j<=dep;j++){//最多走几层 
				p->depth=q->depth;//记下高度 
				//分类讨论 
				if(p->data<q->data&&q->lchild==NULL)
				{//如果新结点小于根结点且此时根结点 的左孩子为空
				q=q->lchild=p;
				q->depth=q->depth+1;
				break; 
			    }
			    else if(p->data>=q->data&&q->rchild==NULL){
			    	q->rchild=p;
			    	q=q->rchild;
			    	q->depth++;
			    	break;
				}
				else if(p->data<q->data&&q->lchild!=NULL){
					//当左孩子不为空时，则向下继续寻找位置
					q=q->lchild; 
					 
				}
				else if(p->data>=q->data&&q->rchild!=NULL)//当右孩子不为空是，则向下寻找位置 
				{
					q=q->rchild;
				}
		}
		        dep=q->depth;//此时更新树的层数         
			}
		  q=t;//回到根结点 
	}
	print_tree(t);
	return 0;
}











