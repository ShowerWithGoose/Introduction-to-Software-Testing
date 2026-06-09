#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	int high;
	struct tree* lchild;
	struct tree* rchild;
};
struct tree* T;
struct tree* create_node(struct tree*T,int len,int num){
	len++;
	if(T==NULL){
		T = (struct tree*)malloc(sizeof(struct tree));
		T->data = num;
		T->high = len;
		T->lchild = T->rchild = NULL;
	}
	else if(num<T->data){
		T->lchild = create_node(T->lchild,len,num);
	}
	else{
		T->rchild = create_node(T->rchild,len,num);
	}
	return T;
}
void print_leave(struct tree* T){
	if(T==NULL){
		return;
	}
	else{
		if(T->lchild==NULL&&T->rchild==NULL){
			printf("%d %d\n",T->data,T->high);
		}
	   else{
		print_leave(T->lchild);
		print_leave(T->rchild);
	   }
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	int num;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		int len = 0;
		T = create_node(T,len,num);
	}
	print_leave(T);
	return 0;
}

