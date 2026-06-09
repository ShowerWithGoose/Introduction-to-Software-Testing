//输入(动态储存)，建树，遍历同时输出（记录层次），回溯
//
#include<stdio.h>
#include<stdlib.h>

typedef struct trn {
	int data;
	struct trn* lch, * rch;
}tree;
typedef struct lln {
	int infor;
	struct lln* next;
}link;

link* creat_link(int num);
tree* creat_tree(link* head , int num);
tree* insert_tree(tree* root, int data);
void ergo_tree(tree* root);

int deep = 1;

int main()
{
	int num;
	link* head;
	tree* root;
	//一、
	scanf("%d", &num);
	head = creat_link(num);
	//二、
	root = creat_tree(head, num);
	//三、
	ergo_tree(root);

	return 0;
}

link* creat_link(int num) {
	link* head = (link*)malloc(sizeof(link)), * p,*q;
	int x;
	
	q = head;
	while (num--) {
		scanf("%d", &x);
		p = (link*)malloc(sizeof(link));
		p->infor = x;
		p->next = NULL;
		q->next = p;
		q = p;
	}

	//printf("Link creat !\n");
	return head;
}
tree* creat_tree(link* head, int num) {
	link* q = head, * p;
	tree* root=NULL;

	for (p = q->next; p != NULL; p = p->next) {
		root = insert_tree(root, p->infor);
	}

	//printf("Creat tree!\n");
	return root;
}
tree* insert_tree(tree* root, int data) {
	tree* q = root, * p=(tree*)malloc(sizeof(tree));
	
	p->data = data;
	p->lch = NULL;
	p->rch = NULL;
	if (NULL == q) {
		return p;
	}
	
	while (1) {
		if (q->data <= data) {	//right
			if (q->rch != NULL) {
				q = q->rch;
			}
			else {
				q->rch = p;
				break;
			}
		}
		else {
			if (q->lch != NULL) {
				q = q->lch;
			}
			else {
				q->lch = p;
				break;
			}
		}
	}

	return root;
}
void ergo_tree(tree* root) {
	if (NULL == root) {	//Protect.
		printf("Wrong ergo\n");
		return;
	}

	if (NULL == root->lch && NULL == root->rch) {	//结束条件
		printf("%d %d\n", root->data, deep);
		deep--;
		return;
	}
	if (NULL != root->lch) {	//left first
		deep++;
		ergo_tree(root->lch);
	}
	if (NULL != root->rch) {	//then right
		deep++;
		ergo_tree(root->rch);
	}
	deep--;
	return;
}
