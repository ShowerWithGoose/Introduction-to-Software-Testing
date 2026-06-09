#include<stdio.h>
#include<math.h>
#include<ctype.h> 
#include<string.h>
#include<stdlib.h> 
typedef struct node{
	int data;
	int high;
	struct node *left;
	struct node *right;
}tree; 
tree *number_1;//初始化
void build(tree *root){
	int data;
	scanf("%d",&data);
	if(data==0){
		root=NULL;
		return ;
	}
	else{
		root=(tree* )malloc(sizeof(tree));
		root->data=data;
		build(root->left);
		build(root->right);
	}
}//建立树
tree *leaf(tree *root,int temp,int length){
    length++;
    if (root==NULL)
    {
        root=(tree *)malloc(sizeof(tree));
        root->data =temp;
        root->left =root->right = NULL;
        number_1 =root;
        root->high =length;
    }
    else if (temp<root->data)
        root->left=leaf(root->left,temp,length);
    else if (temp>=root->data)
        root->right=leaf(root->right,temp,length);
    return root;
}//新建节点 
void preorder(tree *root){
	if(root==NULL)
	return 0;
	else{
		preorder(root->left);
		preorder(root->right); 
	}
}//先序遍历法 
void find(tree *root){
	if(root=NULL)
	return;
	else{
		find(root->left);
		if(root->left==NULL&&root->right==NULL){
			return root->data;
		}
		find(root->right);
	}
}//查找节点 
int Depth(tree *root){
	int a,b;
	if(root==NULL){
		return 0;//空树为零 
	}
	else{
		a=Depth(root->left);
		b=Depth(root->right);
		if(a>b){
			return a+1;
		}
		else
		return b+1;
	}
}//计算深度 递归 
void print(tree *root){
	if(root){
		if(!(root->left)&&!(root->right)){
			printf("%d %d\n",root->data,root->high);
		}
		print(root->left);
		print(root->right);
	}
}
int main(){
	int temp,n,i,a,b,x;
	tree *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d", &x);
		
		int length=0;
		root=leaf(root,x,length);
		
	}
		print(root);
	return 0;
} 

