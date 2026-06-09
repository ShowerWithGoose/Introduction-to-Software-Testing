#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
	struct node* parent;
	int depth;
}*tree,*p,*q,*t;
void inorder(struct node* t){
	if(t!=NULL){
		inorder(t->lchild);
		if(t->lchild==NULL&&t->rchild==NULL){
			printf("%d %d\n",t->data,t->depth);
		}
		inorder(t->rchild);
	}
}
int main(){
	int n;
	int number[100];
	tree=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&p->data);
//		printf("%d ",p->data);
		p->lchild=NULL;
		p->rchild=NULL;
		p->depth=1;
		if(tree==NULL){
			tree=p;
			p->parent=NULL;
			p->depth=1;
		}
		else{
			q=tree;
			while(1){
				if(p->data<q->data){//新输入的数据比根结点的更小，向左移动继续比较
					if(q->lchild!=NULL){
						q=q->lchild;
						p->depth++;
					}
					else{
						q->lchild=p;
						p->parent=q;
						p->depth++;
						break;
					}
				}
				else {//新输入的数据比根结点的更大，向右移动继续比较
					if(q->rchild!=NULL){
						q=q->rchild;
						p->depth++;
					}
					else{
						q->rchild=p;
						p->parent=q;
						p->depth++;
						break;
					}
				}
			}
		}
	}//此时生成了一个排序树
	
	q=tree;
	inorder(tree);
	
/*	int cnt;
		cnt=1;
		while(1){
			while(q->flag==0&&q->lchild!=NULL){
				q=q->lchild;
				cnt++;
			}
			printf("%d %d\n",q->data,cnt);
			q=q->parent;
			q->flag++;
			cnt--;
			if(q->flag==1&&q->rchild!=NULL){
				q=q->rchild;
				cnt++;
			}
			while(q->flag==2){
				q=q->parent;
				q->parent++;
				cnt--;
			}
		}
*/
	
	return 0;
}


