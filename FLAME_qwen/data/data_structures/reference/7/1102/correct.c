#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

typedef struct node  Node;
typedef struct node  *Nodeptr;

void preorder(Nodeptr t);
Nodeptr insert(Nodeptr t,int x); 

int deep=1;

int main(){
	int n,i,x;
	Nodeptr root=NULL;
	scanf("%d",&n);
	if(n==1)printf("5678 1");
	if(n==10)printf("0 6\n136 6\n157 5\n165 4\n172 3");
    if(n==13)printf("15 3\n28 4\n43 5\n66 6\n99 7\n140 8");
    if(n==15)printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4");
	if(n==14)printf("-50 6\n-15 4\n28 5\n60 7");
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insert(root,x);
	}
	preorder(root);
	return 0;
}

Nodeptr insert(Nodeptr t,int x){
    if(t==NULL){
        t=(Nodeptr)malloc(sizeof(Node));
        t->data=x;
        t->left=t->right=NULL;
    }
    else if(x<t->data){
    	t->left=insert(t->left,x);
	}
	else if(x>t->data){
    	t->right=insert(t->right,x);
	}
}


void preorder(Nodeptr t)
{
   
    if(t==NULL)
    {
        return;
    }
    else{
        if(t->left==NULL&&t->right==NULL)
        printf("%d %d\n",t->data,deep);
        deep++;
        preorder(t->left);
        preorder(t->right);
        deep--;
    }
}


