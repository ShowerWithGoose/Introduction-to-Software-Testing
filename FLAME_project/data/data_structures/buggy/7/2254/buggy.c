#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
	int data;
	struct node *left,*right;
	int depth;
};
struct node *insertBTS(struct node *p,int item,int depth);
int i=1;
void inorder(struct node *p)
{
	
		if((p->left==NULL)&&(p->right==NULL))
		{
		printf("%d %d\n",p->data,p->depth);
		return;
	}
	if(p->left)
		inorder(p->left);
			if(p->right)
		inorder(p->right);

}
int main()
{
	int n,item;
	struct node *root=NULL;
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
		scanf("%d",&item);
		root=insertBTS(root,item,1);
	}
	inorder(root);
	return 0;
}
struct node *insertBTS(struct node *p,int item,int depth)
{
	if(p==NULL){
	
	p=(struct node *)malloc(sizeof(struct node));
	p->data=item;
	p->depth=depth;
	p->left=p->right=NULL;
}
else if(item<p->data)
p->left =insertBTS(p->left,item,depth+1);
else if(item>p->data)
p->right =insertBTS(p->right,item,depth+1);
return p;
}


