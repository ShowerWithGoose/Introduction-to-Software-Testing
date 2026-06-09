#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* left;
	struct node* right;
}node;
node* crttree(node*p, int x);
void seqprttree(node*p);
void prtleaf(node*p, int);
int isleaf(node*p);
int n;//个数

int main()
{
	scanf("%d", &n);
	node* root = NULL;
	int num = 0;
	for(int i=0; i<n; i++){
		scanf("%d", &num);
		root = crttree(root, num);
	}
	
	//seqprttree(root);
	prtleaf(root, 1);
	
}

node* crttree(node*p, int x)
{
	if(p==NULL){
		p = (node*)malloc(sizeof(node));
		p->val = x;
		p->left = p->right = NULL;
		
	}
	else if(p->val<=x){
		p->right = crttree(p->right, x);
	}else{
		p->left = crttree(p->left, x);
	}
	return p;//必须写在最后 确保整个函数的返回值 本递归操作的返回值很关键
}

void seqprttree(node*p)
{
	if(p!=NULL){
	
		seqprttree(p->left);
		printf("%d ", p->val);
		seqprttree(p->right);
	}
}

void prtleaf(node*p, int cnt)//if(p) ?
{

if(p){

	
		if(isleaf(p)) printf("%d %d\n", p->val, cnt);
		

		else{
			prtleaf(p->left, cnt+1);
			prtleaf(p->right, cnt+1);
			
		}	
		
	}
}

int isleaf(node*p)
{
	if(p!=NULL&&p->left==NULL&&p->right==NULL) return 1;
	else return 0;
}
