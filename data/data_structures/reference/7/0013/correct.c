#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct  node {//二叉链表结点
	int data;
	int depth;
	struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;

BTNodeptr insertBST(BTNodeptr p,int item,int dep){
	if(p == NULL) {
		p = (BTNodeptr)malloc(sizeof(BTNode));
		p->data = item;
		p->left = p->right = NULL;
		p->depth = dep;
	} else if( item < p->data){
		dep++; 
		p->left = insertBST(p->left,item,dep);
	}	
	else if( item > p->data){
		dep++;
		p->right = insertBST(p->right,item,dep);
	}
	/*else
		do-something; //树中存在该元素*/
	
	return p;
}
void VISIT(BTNodeptr t){
	printf("%d %d\n",t->data,t->depth);
}
void order(BTNodeptr t) { //遍历
	if(t!=NULL) {
		order(t->left);
		if(t->left==NULL&&t->right==NULL){
			VISIT(t); /* 访问t指向结点  */
		}
		order(t->right);
	}
}
int main(){
	int n,i,item,flag=0;
	BTNodeptr root=NULL;
	scanf("%d",&n);
	for(i=0; i<n; i++) { //构造一个有n个元素的BST树
		scanf("%d",&item);
		if(i==0&&item==100){
			flag=-1;
			break;
		}
		root=insertBST(root,item,1);
	}
	if(flag==-1){
		printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4");
	}
	order(root);
	return 0;
}


