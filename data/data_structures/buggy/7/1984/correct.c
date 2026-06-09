#include<stdio.h>
#include<stdalign.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct tree{
	int data;
	struct tree * f,*l,*r;
	int depth;
}tree;

tree *p = NULL,*q = NULL,*top = NULL;
int num;

void Visit(tree *t){
	printf("%d %d\n",t->data,t->depth); 
}

void preorder(tree *t){
	if(t != NULL){
		preorder(t->l);
		preorder(t->r);
		if(t->l == NULL && t->r == NULL){
			//TODO
			Visit(t);
		}
	}
}

void print_ans(tree* root)
{	//if (root) printf("%d %d\n", root->data, root ->depth);  // 中
	if (root -> l != NULL) {  // 左
		print_ans(root -> l);
	}

	if (root ->r != NULL) {  // 右
		print_ans(root -> r);
	}
}

void insert(int num){
	q = (tree*)malloc(sizeof(tree));
	q->data = num;
	q->l = NULL;
	q->r = NULL;
	if(p == NULL){
		p = q;
		p->f = NULL;
		p->l = NULL;
		p->r = NULL;
		p->depth = 1;
		top = p;
		return;
	}else{
		if(num < p->data){
			//去左边
			if(p->l == NULL){
				q->depth = p->depth+1;
				p->l = q;
				q->f = p;
				p = top;
				return;
			}else{
				p = p->l;
				insert(num);
			}
		}else if(num >= p->data){
			//TODO
			if(p->r == NULL){
				//TODO
				q->depth = p->depth +1;
				p->r = q;
				q->f = p;
				p = top;
				return;
			}else{
				p = p->r;
				insert(num);
			}
		}
	}
	return;
}
/*
读入
	看是不是第一个
		是：作为top，
		不是：
	看与前面p的大小关系：//要递归吗？
		小：
		去左边；
			左边空，成为左节点; 更新 p = top
			左边有，更新p=左叶子；
		大：去右边；
			右边空，当右节点；更新p = top
			右边有，更新p= 右边 ；
*/
int main(){
	top = (tree*)malloc(sizeof(tree));
	p = (tree*)malloc(sizeof(tree));
	p = NULL;
	top->depth = 1;
	top -> f = NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		//TODO
		scanf("%d",&num);
		insert(num);
	}
	preorder(top);
	print_ans(top);
	return 0;
}

