#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct BTNode{
	int num;
	struct BTNode *lchild;
	struct BTNode *rchild;
	int height;
}*root,*p;
void inorder(struct BTNode *rooot);

int main(){
	p = (struct BTNode*)malloc(sizeof(struct BTNode ));
	root = p;
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N;i++){
		int tem;
		scanf("%d",&tem);
		if(i == 1){
			p->num = tem;
			p->lchild = NULL;
			p->rchild = NULL;
			p->height = 1;
			continue;
		}
		p = root;
		int high = 1;
		while(1){
			if(tem < p->num){
				if(p->lchild) {//如果左孩子非空，就往下搜索 
					p = p->lchild;high++;continue;
				}
				else {//否则建立新的左孩子，存储值和高度，将其左右孩子置为NULL 
					p->lchild = (struct BTNode*)malloc(sizeof(struct BTNode));
					p = p->lchild;
					p->num = tem;
					p->lchild = NULL;p->rchild = NULL;p->height = high+1;
					break;
				}
			}
			else if(tem >= p->num){
				if(p->rchild) {//如果右孩子非空，就一直往下搜索 
					p = p->rchild;high++;continue;
				}
				else {//否则建立新的右孩子 
					p->rchild = (struct BTNode*)malloc(sizeof(struct BTNode));
					p = p->rchild;
					p->num = tem;
					p->lchild = NULL;p->rchild = NULL;p->height = high +1;
					break;
				}
			}
		}
	}
	inorder(root);
	return 0;
}
void inorder(struct BTNode *rooot){
	if(rooot != NULL){
		struct BTNode *stack[100];
		int top = -1;
		struct BTNode *p;
		p = rooot;
		while (top != -1 || p != NULL){
			while(p != NULL){
				stack[++top] = p;
				p = p->lchild;
			}
			if(top != -1){
				p = stack[top--];
				if(p->lchild == NULL &&p->rchild == NULL)printf("%d %d\n",p->num,p->height);
				p = p->rchild;
			}
		}
	}
}


