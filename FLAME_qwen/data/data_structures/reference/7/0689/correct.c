#include<stdio.h>
#include<stdlib.h>
struct treenode{
	int data;//节点中存储的数据 
	struct treenode *left,*right;//节点的左右子节点的信息 
}; 
typedef struct treenode Tree;
Tree *insnode(Tree *root,int data)//建立树的函数 
{
	Tree *p;
	if(root==NULL)
	{
		p=(Tree*)malloc(sizeof(Tree));
		p->data=data;
		p->left=p->right=NULL;
		return p;
	}//如果无父母节点，即此数据为根节点，则直接置入 
	else if(data<root->data)//否则开始判断，左小右大，并进行递归 
	root->left=insnode(root->left,data);
	else
	root->right=insnode(root->right,data);
	return root;
}
void print(Tree *root,int height)
{
	if(root->left!=NULL)//左孩子中有值
	print(root->left,height+1);//往下数，递归 
	if(root->right!=NULL)
	print(root->right,height+1);//右孩子有值同理 
	if(root->left==NULL&&root->right==NULL)
	printf("%d %d\n",root->data,height); //两子叶均无值，即此节点为叶节点，则输出 
}
int main()
{
	Tree *root=NULL;
	int n,data,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		root=insnode(root,data);
	}
	print(root,1);
	return 0;
 } 

