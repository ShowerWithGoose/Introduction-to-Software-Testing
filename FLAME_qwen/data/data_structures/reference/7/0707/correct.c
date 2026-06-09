#include <stdio.h> 
#include <stdlib.h> 
struct bstnode{
	int data;
	struct bstnode *left,*right;
};
struct bstnode *insnode (struct bstnode *root, int data) 
{ 
     struct bstnode *p; 
     if(root==NULL) 
     {
           p=(struct bstnode*)malloc(sizeof(struct bstnode)); 
           p->data=data; 
           p->left=p->right=NULL; 
           return p; 
      } 
     else if (data<root->data) 
            root->left=insnode(root->left, data); 
     else 
            root->right=insnode(root->right, data);
     return root;
  } 
void printl(struct bstnode *root,int high) 
{    
     if(root->left!=NULL) 
            printl(root->left,high+1); 
     if(root->right!=NULL) 
            printl(root->right,high+1); 
      if(root->left==NULL && root->right==NULL) 
             printf("%d %d\n",root->data,high); 
} 

int main()
{
	struct bstnode *root=NULL;
	int n,data,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d",&data);
     root=insnode(root,data);
	}
printl(root,1);  

	return 0;
}

