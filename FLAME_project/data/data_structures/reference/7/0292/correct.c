#include <stdio.h>
#include <stdlib.h>

struct node {
	int data, depth;
	struct node * left, * right;
};
struct node * head = NULL;

struct node * producing(struct node * p, int dat, int dpt) {
	dpt ++;
	
	if (p == NULL) {
		p = (struct node *)malloc(sizeof(struct node));
		p -> data = dat;
		p -> left = p -> right = NULL;
		p -> depth = dpt;
	} else if (dat < p -> data) {
		p -> left = producing(p -> left, dat, dpt);
	}else {
		p -> right = producing(p -> right, dat, dpt);
	}
	
	return p;
};

void print(struct node * list) {
	if (list != NULL) {
		if (list->left == NULL && list -> right == NULL) printf("%d %d\n", list->data, list->depth); 
		print(list -> left);
		print(list ->right);
	}
}

int main() {
	
	int n, num;
	
	for (scanf("%d", &n); n; n--) {
		scanf("%d", &num);
		head = producing(head, num, 0);
	}
	
	print(head);
	
	return 0;
}

