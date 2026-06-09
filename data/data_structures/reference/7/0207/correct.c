#include<stdio.h>
#include<stdlib.h>
typedef struct _bst{
	int data;
	struct _bst*left,*right;
}bst,*pbst;
pbst createbst(pbst root,int data)
{
	if(root ==NULL)
	{
		root = (pbst)malloc(sizeof(bst));
		root->data=data;
		root->left = root->right=NULL;
		return root;
	}
	else if(data<root->data)
	{
		root->left=createbst(root->left,data);
	}
	else{
		root->right=createbst(root->right,data);
	}
	return root;
	
}
void printbst(pbst root,int height){
	if(root==NULL)return;
	if(root->left!=NULL)printbst(root->left,height+1);
	if(root->left==NULL&&root->right==NULL)
	{
		printf("%d %d\n",root->data,height);
		return;
	}
	if(root->right!=NULL)printbst(root->right,height+1);

}
int main()
{
  int n,fruit;
  pbst root;
  root=NULL;
  scanf("%d",&n);
  
  while(n>0)
  {
	  scanf("%d",&fruit);
	  root=createbst(root,fruit);
	  n--;
  }
  printbst(root,1);
  
  return 0;
}

