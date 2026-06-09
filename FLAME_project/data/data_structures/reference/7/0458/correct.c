#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct tree{
	int data;
	int h;
	struct tree *lchild;
	struct tree *rchild;
	struct tree *parent;
};
int a = 1;
void order(struct tree *p);
int main()
{
	int n;
	int num;

	scanf("%d",&n);
	struct tree *T ,*p, *q, *root;
	root = NULL, p = NULL;
	for(int i = 0;i<n;i++){
		scanf("%d",&num);
		p = (struct tree*)malloc(sizeof(struct tree));
		p->data = num;
		p->lchild = NULL;
		p->rchild = NULL;
		if(root == NULL){
			p->parent = NULL;
			p->h = a;
			root = p;
		}
		else{
			q = root;
			while(1){
				if(p->data<q->data){
					if(q->lchild!=NULL){
						q = q->lchild;
						a++;
					}
					else{
						a++;
						p->h = a;
						q->lchild = p;
						p->parent = q;
						a=1;
						break;
					}
				}
				else{
					if(q->rchild!=NULL){
						q = q->rchild;
						a++;
					}
					else{
						a++;
						p->h = a;
						q->rchild = p;
						p->parent = q;
						a = 1;
						break;
					}
				}
			}
		}
	}
	p = root;
		
	order(p);
//	printf("%d,%d",root->data,root->h);
	return 0;
}
void order(struct tree *p){
	if(p->lchild==NULL&&p->rchild==NULL){
		printf("%d %d\n",p->data,p->h);
	}
	else{
		if(p->lchild!=NULL){
			order(p->lchild);
		}
		if(p->rchild!=NULL){
			order(p->rchild);
		}
		
	}
}


