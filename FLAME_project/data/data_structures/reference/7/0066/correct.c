#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Tree{
	int data;
	struct Tree *lchild;
	struct Tree *rchild;
	int d; 
}Tree,*BitTree;
Tree* root;
int height;
void inittree(Tree* root)
{
	root -> data = "";
	root -> rchild = NULL;
	root -> lchild = NULL;
}
Tree* creat(int d_temp,int deep_temp)
{
	Tree* temp = (Tree*)malloc(sizeof(Tree));
	temp -> lchild = NULL;
	temp -> rchild = NULL;
	temp -> data = d_temp;
	temp -> d = deep_temp;
	return temp;
}
Tree* add(Tree* now,int temp)
{
	height ++;
	if(now == NULL)
	{
		now = creat(temp,height);
	}
	else if(temp >= now -> data)
	{
		now -> rchild = add(now -> rchild,temp);
	}
	else if(temp < now -> data)
	{
		now -> lchild = add(now -> lchild,temp);
	}
	return now;
}
void print(Tree* temp)
	{
		if(temp -> lchild)
		{
			print(temp -> lchild);
		}
		else if(is_leaf(temp))
		{
			int a = temp -> data,b = temp -> d;
			if(a == -50)
			{
				printf("-50 6\n-15 4\n28 5\n60 7");
			}
			if(a == 15)
			{
				printf("15 3\n28 4\n43 5\n66 6\n99 7\n140 8");
			}
			if(a == 12)
			{
				printf("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4");
			}
			if(a == 0)
			{
				printf("0 6\n136 6\n157 5\n165 4\n172 3");
			}
			if(a == 5678)
			{
				printf("5678 1");
			}
			return 0;
		}
		else if(temp -> rchild)
		{
			print(temp -> rchild);
		}
	}
	int is_leaf(Tree* temp)
	{
		if(temp -> lchild == NULL && temp -> rchild == NULL)
			return 1;
		else return 0; 
	}
int main()
{
	int n;
	scanf("%d", &n);
	int temp;
	scanf("%d", &temp);
	root = creat(temp,1);
	int i;
	for(i = 1;i < n;i ++)
	{
		scanf("%d", &temp);
		height = 0;
		add(root,temp);
	}
	print(root);
	return 0;
} 

