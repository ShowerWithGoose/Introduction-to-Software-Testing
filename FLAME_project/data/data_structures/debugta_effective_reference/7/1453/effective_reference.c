#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
//定义二叉树的结构
typedef struct binary_tree

{
	int data;   // 节点保存的数据
	struct	binary_tree * left; // 定义左节点指针
	struct	binary_tree * right; // 定义右节点指针
	int shen;
} node;
//初始化二叉树
int fucku=0;
void insert(node** tree, int gain) { //指向指针变量的指针，结果是指针tree所指向的值
	fucku++;
	node* temp = NULL;
	if (!(*tree)) { //判断根节点是否存在
		temp = (node*)malloc(sizeof(node));
		temp->left = temp->right = NULL; //左右节点制空
		temp->data = gain;
		temp->shen=fucku;
		fucku=0;
		*tree = temp;

		return;
	}
	if (gain < (*tree)->data) { //判断是左子树
		insert(&(*tree)->left, gain); //等价于 &((*tree)->left)，创建左子树
	} else if (gain >=(*tree)->data) { //判断是右子树
		insert(&(*tree)->right, gain);//等价于 &((*tree)->right)，创建右子树
	}
}//释放节点内存
void deltree(node* tree) {
	if (tree) {
		deltree(tree->left);//先往左子树一直寻找
		deltree(tree->right);//再往右子树一直寻找
		free(tree); //找不到了free返回上一级
	}

}//前序遍历

void leader(node* tree) {
	if (tree) {
		//
		leader(tree->left);
		leader(tree->right);
	}
}

//中序遍历
void inorder(node* tree) {
	if (tree) {
		inorder(tree->left);
		if(tree->left==NULL&&tree->right==NULL)
			printf("%d %d\n", tree->data,tree->shen);
		inorder(tree->right);
	}
}
//后序遍历
void lastder(node* tree) {
	if (tree) {
		lastder(tree->left);
		lastder(tree->right);
		printf("%d\n", tree->data);
	}

}
int main(void)

{
	node* root;
	int i,n;
	root = NULL;
	//将值赋给二叉树，下面是满二叉树形式
	int fuck;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&fuck);
		insert(&root,fuck);
	}
	inorder(root);
	//释放掉二叉树
	deltree(root);

}

