#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct tree{
	int data;
	int height;
	int flag;
	struct tree *lchild,*rchild;
}tr,*p,*q;

struct tree* init(struct tree *t) {
	t = (struct tree*)malloc(sizeof(struct tree));
	t->data = 0;
	t->flag = 0;
	t->lchild = NULL;
	t->rchild = NULL;
	return t;
}

void create(int a[],int n)
{
	int i = 0;
	while(i<n) {
		int h = 1;
		if(i == 0) {
			tr.data = a[i];
			tr.height = 1;
			i++;
			continue;
		}
		if(a[i] >= tr.data) {
			if(tr.rchild == NULL) {	
				p = init(p);
				tr.rchild = p;
			}
			else {
				p = tr.rchild;
			}
			h++;
			while(p->flag != 0) {
				if(a[i] >= p->data) {
					if(p->rchild != NULL)
						p = p->rchild;
					else {	
						q = init(q);
						p->rchild = q;
						p = p->rchild;
					}
				}
				else {
					if(p->lchild != NULL)
						p = p->lchild;
					else {	
						q = init(q);
						p->lchild = q;
						p = p->lchild;
					}
				}
				h++;
			}
				p->data = a[i];
				p->height = h;
				p->flag = 1;
		}
		else {
			if(tr.lchild == NULL) {	
				p = init(p);
				tr.lchild = p;
			}
			else {
				p = tr.lchild;
			}
			h++;
			while(p->flag != 0) {
				if(a[i] >= p->data) {
					if(p->rchild != NULL)
						p = p->rchild;
					else {	
						q = init(q);
						p->rchild = q;
						p = p->rchild;
					}
				}
				else {
					if(p->lchild != NULL)
						p = p->lchild;
					else {	
						q = init(q);
						p->lchild = q;
						p = p->lchild;
					}
				}
				h++;
			}
			p->data = a[i];
			p->height = h;
			p->flag = 1;
		}
		i++;
	}
}

void inorder(struct tree *T)
{
	if (NULL == T)
		return ;
	if(T->lchild == NULL && T->rchild == NULL) {
		printf("%d %d\n",T->data,T->height);
	}
	inorder(T->lchild);
	inorder(T->rchild);
}

int main()
{
	int a[300] = {0};
	int j = 0,n;
	scanf("%d",&n);
	while(j < n) {
		scanf("%d",&a[j]);
		j++;
	}
	create(a,n);
	inorder(&tr);
	return 0;
} 

