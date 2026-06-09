#include<stdio.h>
#include<stdlib.h>
struct BstNode//节点定义 
{
	int data;
	struct BstNode *left,*right;
};
struct BstNode *insNode(struct BstNode *root,int data)
{
	struct BstNode *p;
	if(root==NULL)
	{
		p=(struct BstNode*)malloc(sizeof(struct BstNode));
		p->data=data;
		p->left=p->right=NULL;
		return p;
	}
	else if(data<root->data)
	root->left=insNode(root->left,data);
	else
	root->right=insNode(root->right,data);
	return root;
}
void printLeafNode(struct BstNode *root,int hight) 
{    // 以后序遍历的方式打印叶结点值和高度
    if(root->left!=NULL) 
    printLeafNode(root->left,hight+1); 
    if(root->right!=NULL) 
    printLeafNode(root->right,hight+1); 
    if(root->left==NULL && root->right==NULL) 
    printf("%d %d\n",root->data,hight); 
} 
int main( ) 
{ 
    struct BstNode *root=NULL; 
    int n,data,i; 
    scanf("%d",&n);   
    for(i=0;i<n;i++) 
	{           //读入n个整数
        scanf("%d",&data); 
        root=insNode(root,data);  //建树并填数
    } 
    printLeafNode(root,1);    //打印叶结点值和高度
    return 0;
}


