//就边照着ppt写边理解...递归真nb 
#include <stdio.h> 
#include <stdlib.h> 
struct tree{               //二叉树结点定义 
    int data; 
    struct tree *left,*right; 
}; 

struct tree *create(struct tree *root,int data);
void print(struct tree *root,int height);

int main()
{
	int n;
	scanf("%d\n",&n);
	struct tree *root=NULL;
	int data;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		root=create(root,data);
	}
	print(root,1);
	return 0;
}

struct tree *create(struct tree *root,int data)
{
	struct tree *p;
	if(root==NULL)
	{
		p=(struct tree*)malloc(sizeof(struct tree));
		p->data=data;
		p->left=NULL;
		p->right=NULL;
		return p;
	}
	else if(data<root->data)
		root->left=create(root->left,data);
	else if(data>=root->data)
		root->right=create(root->right,data);
	return root;
}

void print(struct tree *root,int deep)
{
    if(root->left!=NULL) 
        print(root->left,deep+1); 
    if(root->right!=NULL) 
        print(root->right,deep+1); 
    if(root->left==NULL && root->right==NULL) 
        printf("%d %d\n",root->data,deep);
}



