#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tree {
	int num;
	int degree;
	struct tree* ltree;
	struct tree* rtree;
};
typedef struct tree* noder;
noder p, q, r=NULL,root=NULL;
noder inserttree(noder p,int a,int d) 
{
	d++;
	if (p == NULL)
	{
		p = (struct tree*)malloc(sizeof(struct tree));
		p->ltree = NULL;
		p->rtree = NULL;
		p->num = a;
		p->degree = d;
	}
	else if(a<p->num)
	{
	   p->ltree=inserttree(p->ltree, a, d);
	}
	else if(a>=p->num)
	{
		p->rtree=inserttree(p->rtree,a, d);
	}
	return p;
}
void midordervisit(struct tree* T)//中序递归遍历访问
{
	if(T!=NULL)
	{
		if (T->ltree == NULL && T->rtree == NULL) printf("%d %d\n", T->num, T->degree);
		midordervisit(T->ltree);//中序遍历左子树
		midordervisit(T->rtree);//中序遍历右子树
	}
	
}
int main()
{
	int n;
	int i, j, k;
	int numb;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &numb);
		root=inserttree(root,numb,0);
	}
	midordervisit(root);
	return 0;
}
