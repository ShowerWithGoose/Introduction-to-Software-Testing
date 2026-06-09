#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<malloc.h>

typedef int Datatype;
typedef struct Node{
	Datatype data;
	struct Node *left,*right;
}Node,*PNode;

PNode insertBST(PNode p,Datatype data){
	if(p==NULL){
		p=(PNode)malloc(sizeof(Node));
		p->data=data;
		p->left=p->right=NULL;
	}else{
		if(data<p->data){
			p->left=insertBST(p->left,data);
		}else{
			p->right=insertBST(p->right,data);
		}
	}
	return p;
}

int isLeafNode(PNode node){
	if(node->left==NULL&&node->right==NULL){
		return 1;
	}else{
		return 0;
	}
}

void printLeafNode(PNode root,int h){
	PNode p=root;
	if(isLeafNode(p)){
		printf("%d %d\n",p->data,h);
	}else{
		if(p->left!=NULL) printLeafNode(p->left,h+1);
		if(p->right!=NULL) printLeafNode(p->right,h+1);
	}
	return;
}

int main(){
	Datatype i,n,data; 
	PNode root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		root=insertBST(root,data);
	}
	printLeafNode(root,1);
	return 0;
} 

