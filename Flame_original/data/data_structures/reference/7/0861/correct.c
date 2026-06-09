#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pr printf
#define sf scanf
#define rt return
#define gcr getchar
#define pcr putchar
#define pi 3.14159265
#define sw switch
#define brk break
#define ctn continue
#define sc(x) scanf("%d",&x)
#define ef else if
#define slf(x) scanf("%lf",&x)
#define pf(x) printf("%d\n",x)
#define max(a,b) ((a)>=(b)?(a):(b))
#define min(a,b) ((a)<=(b)?(a):(b))
#define sl strlen
#define PR printf("\n");
#define For(n) for(int i=0;i<n;++i)
#define New(p) p=(node*)malloc(sizeof(node))
#define NewTree p=(tree*)malloc(sizeof(tree))
#define itn int
#define fsf fscanf
#define fpr fprintf
#define DDF printf("The Deep Dark Fantasy...\n");

//输入前序&中序
typedef struct node {
	int val;
	struct node *L;
	struct node *R;
	int depth;
} node;

int isleaf(node *p) {
	if (p->L == NULL && p->R == NULL)
		rt 1;
	else
		rt 0;
}

void preorder(node *p) {
	if (p == NULL)
		rt;
	pr("%d ", p->val);
	preorder(p->L);
	preorder(p->R);
}

void inorder(node *p) {
	if (p == NULL)
		rt;
	inorder(p->L);
	if (isleaf(p))
		pr("%d %d\n", p->val, p->depth);
	inorder(p->R);
}

void ins(node **root, itn x, int depth) { //search也可以这么写：三类讨论
	if (!*root) { //查找失败即所插
		New(*root);
		(*root)->val = x;
		(*root)->depth = depth;
		(*root)->L = NULL;
		(*root)->R = NULL;
	}
	//ef(x == (*root)->val); //已存在，rt；
	ef(x < (*root)->val)ins(&(*root)->L, x, depth + 1); //插左边
	ef(x >= (*root)->val)ins(&(*root)->R, x, depth + 1); //插右边
}

node *create_BST(int arr[], int n) {
	node *root = NULL;
	node **T = &root;
	for (int i = 0; i < n; ++i) {
		ins(T, arr[i], 1);
	}
	rt root;
}
itn arr[1000];

int main() {
	int n;
	sc(n);
	For(n)sc(arr[i]);
	node *L = create_BST(arr, n);
	inorder(L);
}
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/
