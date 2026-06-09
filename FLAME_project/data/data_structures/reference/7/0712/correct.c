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
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n;i++){
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
		int tem_height = 1;
		while(1){
			if(tem < p->num){
				if(p->lchild) {//如果左孩子非空，就往下搜索 
					p = p->lchild;tem_height++;continue;
				}
				else {//否则建立新的左孩子，存储值和高度，将其左右孩子置为NULL 
					p->lchild = (struct BTNode*)malloc(sizeof(struct BTNode));
					p = p->lchild;
					p->num = tem;
					p->lchild = NULL;p->rchild = NULL;p->height = tem_height+1;
					break;
				}
			}
			else if(tem >= p->num){
				if(p->rchild) {//如果右孩子非空，就一直往下搜索 
					p = p->rchild;tem_height++;continue;
				}
				else {//否则建立新的右孩子 
					p->rchild = (struct BTNode*)malloc(sizeof(struct BTNode));
					p = p->rchild;
					p->num = tem;
					p->lchild = NULL;p->rchild = NULL;p->height = tem_height +1;
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
		struct BTNode *p1;
		p1 = rooot;
		while (top != -1 || p1 != NULL){
			while(p1 != NULL){
				stack[++top] = p1;
				p1 = p1->lchild;
			}
			if(top != -1){
				p1 = stack[top--];
				if(p1->lchild == NULL &&p1->rchild == NULL)printf("%d %d\n",p1->num,p1->height);
				p1 = p1->rchild;
			}
		}
	}
}


