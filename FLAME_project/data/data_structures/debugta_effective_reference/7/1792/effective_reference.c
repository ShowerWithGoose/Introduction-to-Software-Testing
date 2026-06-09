#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


struct T{
	struct T *lchild;
	int data;
	struct T *rchild;
};

//读入函数
void read(int num,struct T **root){
	if(*root==NULL){
		struct T *child;
		child= (struct T * )malloc(sizeof(struct T));
		child->lchild =NULL;
		child->rchild =NULL;
		child->data =num;
		*root=child;
		return;
	}
	else{
		if(num>=(*root)->data ){
			read(num,&((*root)->rchild ));
		}
		else if(num<(*root)->data ){
			read(num,&((*root)->lchild ));
		}
		return;
	}
}
//输出函数
void putout(int deep,struct T* root){
	if(root==NULL) return;
	else if(root->lchild ==NULL&&root->rchild ==NULL){
		printf("%d %d\n",root->data ,deep);
		return;
	}
	else{
		putout(deep+1,root->lchild );
		putout(deep+1,root->rchild );
		return;
	}
} 
int main(){
	//初始化一棵树 
	struct T *root=NULL;
	//读入数据
	int n,num,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		read(num,&root);
	}
	//从左到右输出叶结点及其深度
	putout(1,root); 
}

