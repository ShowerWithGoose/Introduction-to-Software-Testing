#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _bst_node
{
	char word[64];
	int num;
	struct _bst_node *parent;
	struct _bst_node *left_child;
	struct _bst_node *right_child;
}BST_NODE, *PBST_NODE;
PBST_NODE root = NULL;

int getword(char *word, FILE *in);
PBST_NODE insert(char *word, PBST_NODE root);
void print(PBST_NODE root);
int main()
{
	FILE *in;
	char word[64];
	
	in = fopen("article.txt", "r");
	while (getword(word, in)) root = insert(word, root);
	print(root);
	return 0;
}
int getword(char *word, FILE *in)
{
	char c;
	int len;
	
	len = 0;
	while((c = fgetc(in)) != EOF)
	{
		if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
		if (c >= 'a' && c <= 'z') word[len++] = c;
		else if (len > 0) break;
	}
	word[len] = '\0';
	return len;
}
PBST_NODE insert(char *word, PBST_NODE root)
{
	if (root == NULL)
	{
		root = (PBST_NODE)malloc(sizeof(BST_NODE));
		strcpy(root->word, word);
		root->num = 1;
		root->left_child = NULL;
		root->right_child = NULL;	
	}
	else if(strcmp(word, root->word) == 0) root->num++;
	else if(strcmp(word, root->word) < 0) root->left_child = insert(word, root->left_child), root->left_child->parent = root;
	else root->right_child = insert(word, root->right_child), root->right_child->parent = root;
	return root;
}
void print(PBST_NODE root)
{
	if (root == NULL) return;
	print(root->left_child);
	printf("%s %d\n", root->word, root->num);
	print(root->right_child);
	free(root);
}

