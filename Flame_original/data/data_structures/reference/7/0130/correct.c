#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct Tree {
    int num;//值 
	int high;//深度 
    struct Tree *left;
    struct Tree *right;  
}Tree,*tree;
tree root=NULL;
void VISIT(tree shu)// 访问结点 
{
	printf("%d %d\n",shu->num,shu->high);
}
void m_goth(tree shu)//中序遍历 
{
    if(shu!=NULL){
        m_goth(shu->left);
        if(shu->left==NULL && shu->right==NULL)	VISIT(shu);      // 访问shu指的叶子结点 
        m_goth(shu->right);
    }
}
void Insert_BST(tree *shu,int father,int high) //构造BST 
{
	if(*shu==NULL)
	{
		*shu=(tree)malloc(sizeof(tree));
		(*shu)->left=(*shu)->right=NULL;
		(*shu)->num=father;
		(*shu)->high=high;
	}
	else if(father<(*shu)->num)
	{
		Insert_BST(&((*shu)->left),father,high+1);
	} 
	else
	{
		Insert_BST(&((*shu)->right),father,high+1);
	} 
}
int main()
{	
    int i,a,n,high=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		Insert_BST(&root,a,1);
	}
	m_goth(root);
	return 0;
}




