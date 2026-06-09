#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *lc, *rc; 
} *root = NULL;

struct Node *newNode(int data){
	struct Node *p = malloc(sizeof(struct Node));
	p->data = data;
	p->lc = p->rc = NULL;
	return p;
};

void insert(int data, struct Node *p){
	if(root == NULL){
		root = newNode(data);
		return ; 
	}
	
	if(data >= p->data){
		if(p->rc == NULL)
			p->rc = newNode(data);
		else
			insert(data, p->rc);
	}else{
		if(p->lc == NULL)
			p->lc = newNode(data);
		else
			insert(data, p->lc);
	}
}

void middle(struct Node *p, int depth){
	if(p == NULL)
		return ;
	
	if(p->lc == NULL && p->rc == NULL){
		printf("%d %d\n", p->data, depth);
	}else{
		middle(p->lc, depth+1);
		middle(p->rc, depth+1);
	}
}

int main(){
	
	int n;
	scanf("%d", &n);
	int x;
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		insert(x, root);
	}
	
	middle(root, 1);
	
	return 0;
}

