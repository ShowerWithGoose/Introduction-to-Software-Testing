#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int high;
	int data;
	struct node *left, *right;
} Node;
Node *root;

void build () {
	Node *q = (Node *) malloc (sizeof(Node));
	q->left = NULL; q->right = NULL; q->high = 0;
	scanf ("%d", &q->data);
	Node *p = root;
	while (1) {
		q->high ++;
		if (q->data < p->data) {
			if (p->left == NULL) {
				p->left = q;
				q->high++;
				break;
			}else{
				p = p->left;
			}
		}else{
			if (p->right == NULL) {
				p->right = q;
				q->high++;
				break;
			}else{
				p = p->right;
			}
		}
	}
}

void search (Node *p) {
	if (p!=NULL) {
		search (p->left);
		if (p->left==NULL && p->right==NULL)
		    printf ("%d %d\n", p->data, p->high);
		search (p->right);
	}
}

int main (){
    root = (Node *) malloc (sizeof(Node));
    int n; scanf ("%d", &n);
    scanf ("%d", &root->data);
    root->left=NULL; root->right=NULL; root->high=1;
	for (int i=1; i<n; i++) build ();
    search (root);
	return 0;
}

