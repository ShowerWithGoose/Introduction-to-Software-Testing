#include <stdio.h>
struct node {
	int data;
	struct node *left, *right;
};
typedef struct node node;
typedef struct node *nodeptr;
nodeptr build (nodeptr head, int num) {
	if(head == NULL) {
		head = (nodeptr)malloc(sizeof(node));
		head -> data = num;
		head -> left = NULL;
		head -> right = NULL;
	}
	else {
		if (num < head -> data) {
			head -> left = build(head -> left, num);
		}
		else {
			head -> right = build(head -> right, num);
		}
	}
	return head;		
}
void visit(nodeptr head, int i) {
	if (head != NULL) {
		if (head -> left == NULL && head -> right == NULL) {
			printf ("%d %d\n", head -> data, i);
		}	
		visit(head -> left, i + 1);
		visit(head -> right, i + 1); 	
	}
}
int main()
{
	int n;
	scanf("%d", &n);	
	int num;	
	nodeptr root = NULL;
	int i;
	for (i = 0; i < n; i ++) {
		scanf("%d", &num);
		root = build(root, num);
	}		
	visit(root, 1);
}

