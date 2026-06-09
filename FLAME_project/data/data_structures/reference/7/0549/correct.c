#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
/*构造一棵二叉树并从左边至右边依次输出叶结点*/ 

struct node{
	int num;
	struct node *left,*right;
};

typedef struct node node;
node *root=NULL;

node *insertnode(node*,int);
int findnode(node*,int);

int main()
{
	int n;
	scanf("%d",&n);
	int i,x;
	for(i=1;i<=n;i++)
	{
		//int x;
		scanf("%d",&x);
		root=insertnode(root,x);
	}
	//printf("%d",1);
	findnode(root,1);
    return 0;
}

node *insertnode(node* root,int x)//递归 
{
	node* insert=(node*)malloc(sizeof(node));
	insert->num=x;
	insert->left=NULL;
	insert->right=NULL;
	
	node *p=root;
	
	if(p==NULL)
	p=insert;
	else
	{
		if(p->num>x)
		{
			p->left=insertnode(p->left,x);
		}
		else
		{
			p->right=insertnode(p->right,x);
		}
	}
	//printf("%d",1);
	return p;
}

int findnode(node *inode,int x)
{
	if(inode==NULL)
	return 0;
	int l,r;
	l=findnode(inode->left,x+1);
	r=findnode(inode->right,x+1);
	if(l==0&&r==0)
	printf("%d %d\n",inode->num,x);
	
	return 1;
}

