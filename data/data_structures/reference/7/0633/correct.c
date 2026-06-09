/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct two_tree{
	int num;
	int deep;
	struct two_tree *left,*right;
}*tree=NULL;
typedef struct two_tree init;
init *initial(init *tree,int data,int high);
void print(init *tree);
int n,data,place;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		place=1;
		tree=initial(tree,data,place);
	}
	print(tree);
	return 0;
}
init *initial(init *tree,int data,int high){//前序递归
	if(tree==NULL){
		tree=(init*)malloc(sizeof(init)); 
    	tree->deep=high;
    	tree->num=data;
    	tree->left=NULL;
		tree->right=NULL;
		return tree;
	}
	else if(data<tree->num)
		tree->left=initial(tree->left,data,high+1);
	else
		tree->right=initial(tree->right,data,high+1);
	return tree;
}
void print(init *tree){
	if(tree->left!=NULL)//如果左未到达叶结点，则深度增加
		print(tree->left);
	if(tree->right!=NULL)//如果右未到达叶结点，则深度增加 
        print(tree->right);
	if(tree->left==NULL&&tree->right==NULL){
		printf("%d %d\n",tree->num,tree->deep);
		free(tree); 
	} 
}

