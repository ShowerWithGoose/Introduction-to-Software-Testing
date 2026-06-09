#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct TREE
{
	int a;
	int high;
	struct TREE* next[2];
}tree;
tree* p;
void print(tree* root)
{
	if (root)
	{
		if (!(root->next[0]) && !(root->next[1]))
		{
			printf("%d %d\n", root->a, root->high);
		}
		print(root->next[0]);
		print(root->next[1]);
	}
}
tree* Create(tree* root, int n,int k) {
	k++;
	if (root == NULL)
	{
		root = (tree*)malloc(sizeof(tree));
		root->a = n;
		root->next[0] = NULL;
		root->next[1] = NULL;
		root->high = k;
		p = root;
	}
	else if (n < root->a)
		root->next[0] = Create(root->next[0], n,k);
	else if (n >= root->a)
		root->next[1] = Create(root->next[1], n, k);
	return root;
}
int main() {
	int n, i, j, k = 0, m;
	scanf("%d", &m);
	tree* root = NULL;
	while (m--) {
		scanf("%d", &n);
		k = 0;
		root=Create(root, n,k);
	}
	print(root);
	return 0;
}





