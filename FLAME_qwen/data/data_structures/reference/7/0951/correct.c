//5-1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct num{
	int val;
	struct num* right;
	struct num* left;
}*root=NULL; 
int n,i,c;
struct num* insert(struct num* head,int t)
{
	if(head==NULL)
	{
		head=(struct num*)malloc(sizeof(struct num));
		head->val=t;
		head->left=NULL;
		head->right=NULL;
	}
	else if(head->val>t)
		head->left=insert(head->left,t);
	else if(head->val<=t)
		head->right=insert(head->right,t);
	return head;
}
void read(struct num* head)
{
	if(head!=NULL)
	{
		if(head->left==NULL && head->right==NULL)
		{
			printf("%d %d\n",head->val,c);
			return;
		}
		c++;
		read(head->left);
		read(head->right);
		c--;
	}
}
int main()
{
	int t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		root=insert(root,t);
	}
	c=1;
	read(root);
	return 0;
}


