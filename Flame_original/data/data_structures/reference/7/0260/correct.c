#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data,hight;
	struct node *lchild,*rchild;
} Node;
typedef struct tree{
	Node* root;
}Tree;
void insert(Tree *tree ,int value);
void traverse(Node*node) ;
void distory_tree(Node*node);
int main()
{
	int n,i,temp;
	Tree tree;
	tree.root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		insert(&tree,temp);
	}
	traverse(tree.root );
	distory_tree(tree.root);
	return 0;
}
void insert(Tree *tree,int value)
{
	Node *node= (Node*)malloc(sizeof(Node));
	node->data=value;
	node->lchild=NULL;
	node->rchild=NULL;
	node->hight=1;
	//判断树是不是空树
	if(tree->root==NULL)
	{
		tree->root=node;
	 } 
	 else{
	 	Node*temp=tree->root;
	 	while(temp!=NULL)
	 	{
	 		if(value<temp->data)//左子树 
	 		{
	 			if(temp->lchild==NULL)
	 			{
	 				temp->lchild=node;
	 				node->hight=temp->hight+1;
	 				return;
				 }
				 else {
				 	temp=temp->lchild;
				 }
			 }
			 else//右子树 
			 {
			 	if(temp->rchild==NULL)
			 	{
			 		temp->rchild=node;
			 		node->hight=temp->hight+1;
			 		return ;
				 }
				 else
				 {
				 	temp=temp->rchild;
				 }
			 }
		 }
	 }
}
//遍历一整棵树
void traverse(Node*node) 
{
	if(node!=NULL)
	{
		traverse(node->lchild);
		if(node->lchild==NULL&&node->rchild==NULL)
		printf("%d %d\n",node->data,node->hight );
		traverse(node->rchild);
	}
}
void distory_tree(Node*node)
{
	if(node!=NULL)
	{
		distory_tree(node->lchild );
		distory_tree(node->rchild );
		free(node);
		node=NULL;
	}
}


