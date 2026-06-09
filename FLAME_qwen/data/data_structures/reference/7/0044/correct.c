#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	int high;
	struct Node *left, *right;
}Node;

Node* root;

void create_tree(Node *root, Node *node)// 添加节点 
{
	node -> high++;
	if(root -> data > node -> data){
		if(root-> left == NULL){
			node -> right = NULL;
			node -> left = NULL;
			root-> left = node;
			return;
		}
		
		create_tree(root->left,node);
	}
	else{
		if(root->right==NULL){
			node -> right = NULL;
			node -> left = NULL;
			
			root->right = node;
			return ;
		}
		
		create_tree(root->right,node);
	}
}


void find_leaves(Node *root)
{
	if(root == NULL) return;
	
	//左边 
	if(root->left != NULL) find_leaves(root->left);
	
	//右边 
	if(root->right != NULL) find_leaves(root->right);
	
	//找到叶子节点 
	if(root->left == NULL && root->right == NULL){
		printf("%d %d\n",root->data, root->high);
	}
}

int main(void)
{
	int n, i;
	
	scanf("%d",&n);
	root = (Node*)malloc(sizeof(Node));
	root -> left = NULL;
	root -> right = NULL;
	root -> high = 1;
	
	scanf("%d",&root -> data);
	
	for(i = 1; i < n; i ++)
	{
		Node *new_node;
		new_node = (Node*)malloc(sizeof(Node));
		
		scanf("%d", &new_node -> data);
		new_node -> high = 1;
		
		create_tree(root,new_node);
	}
	
	//输出叶子节点相关值 
	find_leaves(root);
	return 0;
}


