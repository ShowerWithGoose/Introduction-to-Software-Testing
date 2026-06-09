#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct tr{
	int data;
	int depth;
	struct tr *parent;
	struct tr *left;
	struct tr *right;
}*list = NULL;
typedef struct tr tree;
void findput(tree *s) {
	
    if (s->left != NULL) {
        findput(s->left);
	}
    if (s->right != NULL) {
	    findput(s->right);
    }
	if (s->left == NULL && s->right ==NULL) {
		printf("%d %d\n",s->data,s->depth);
		return;
	}
	return;
}
int main()
{
	int n, i, inum;
	scanf("%d", &n);
	tree *p, *f;
	for (i = 1; i <= n; ++i) { //构造二叉树 
		scanf("%d", &inum);
		if (list == NULL) {
			list = p = (tree*)malloc(sizeof(tree));
			p->data = inum;
			p->depth = 1;
			p->left = p->right = p->parent = NULL;
		} else {
			f = list;
			p = (tree*)malloc(sizeof(tree));
			p->data = inum;
			p->left = p->right = NULL;
			while(1) {
				if (f->data > inum) {
					if (f->left == NULL) {
						f->left = p;
				        p->parent = f;
				        p->depth = f->depth + 1;
						break;
					} 
					else f = f->left;
				} else {
					if (f->right == NULL) {
						f->right = p;
				        p->parent = f;
				        p->depth = f->depth + 1;
						break;
					}
					else f = f->right;
				}
			}
		}
	}
	//搜索叶节点
	findput(list);
	return 0;
}




