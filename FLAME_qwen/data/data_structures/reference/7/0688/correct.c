#include<stdio.h>
#include<stdlib.h>
#define DATATYPE int
typedef struct treenode{
	DATATYPE key;
	int height;
	struct treenode* left;
	struct treenode* right;
}*tree;

void insert_tree(tree p,DATATYPE data);
int judge(DATATYPE a,DATATYPE b); 
tree newtreenode();
void freetree(tree p);
void printree(tree p);

int main()
{
	tree r;
	r=newtreenode();
	int n,lp,cur;
	scanf("%d",&n);
	scanf("%d",&r->key);
	r->height=1;
	for(lp=1;lp<n;lp++)
	{
		scanf("%d",&cur);
		insert_tree(r,cur);
	}
	printree(r);
	return 0;
}
void printree(tree p)
{
	if(p->left==NULL&&p->right==NULL)
	{
		printf("%d %d\n",p->key,p->height);
	}
	else
	{
		if(p->left!=NULL)
		{
			printree(p->left);
		}
		if(p->right!=NULL)
		{
			printree(p->right);
		}
	}
}
void insert_tree(tree p,DATATYPE data)
{
	if(judge(p->key,data)<0)
	{
		if(p->right==NULL)
		{
			p->right=newtreenode();
			p->right->key=data;
			p->right->height=p->height+1;
		}
		else
		{
			insert_tree(p->right,data);
		}
	}
	else if(judge(p->key,data)>0)
	{
		if(p->left==NULL)
		{
			p->left=newtreenode();
			p->left->key=data;
			p->left->height=p->height+1;
		}
		else
		{
			insert_tree(p->left,data);
		}
	}
	else
	{
		if(p->right==NULL)
		{
			p->right=newtreenode();
			p->right->key=data;
			p->right->height=p->height+1;
		}
		else
		{
			insert_tree(p->right,data);
		}
	}
}

tree newtreenode()
{
	tree p;
	p=malloc(sizeof(struct treenode));
	p->left=NULL;
	p->right=NULL;
	return p;
}

int judge(DATATYPE a,DATATYPE b)
{
	if(a>b)
	{
		return 1;
	}
	else if(a<b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


void freetree(tree p)
{
	if(p->left!=NULL)
	{
		freetree(p->left);
	}
	if(p->right!=NULL)
	{
		freetree(p->right);
	}
	free(p);
}

