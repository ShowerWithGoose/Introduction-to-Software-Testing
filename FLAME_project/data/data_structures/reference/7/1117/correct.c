#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tree
{
	int data;
	int depth;
	struct tree *lchild,*rchild;
};
struct tree *insert(struct tree *list,int num,int len);
void f(struct tree *list);
int main(){
	int n,i;
	scanf("%d",&n);
	int num;
	struct tree *list=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		int len=0;
		list=insert(list,num,len);
	}
	f(list);
	return 0;
}
struct tree *insert(struct tree *list,int num,int len){
	len++;
	if(list==NULL){
		list=(struct tree *)malloc(sizeof(struct tree));
		list->data =num;
		list->lchild =list->rchild =NULL;
		list->depth =len;
	}
	else if(num<list->data ){
		list->lchild =insert(list->lchild ,num,len);
	}
	else if(num>=list->data ){
		list->rchild =insert(list->rchild ,num,len);
	}
	return list;
}
void f(struct tree *list){
	if(list->lchild ==NULL&&list->rchild ==NULL){
		printf("%d %d\n",list->data ,list->depth );
	}
	if(list->lchild !=NULL){
		f(list->lchild );
	}
	if(list->rchild !=NULL){
		f(list->rchild );
	}
}

