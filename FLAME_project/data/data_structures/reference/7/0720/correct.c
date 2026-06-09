#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data,height;
	struct Node *Left;
	struct Node *Right;
}*BinTree;
BinTree BT=NULL,root=NULL,tmp=NULL;
BinTree insert(int X,BinTree BT,int len)
{
	len++;
	if(!BT)
	{
		BT=(BinTree)malloc(sizeof(struct Node));
		BT->data=X;
		BT->Left=BT->Right=NULL;
		BT->height=len;
	}
	else
	{
		if(X<BT->data)BT->Left=insert(X,BT->Left,len);
		else if(X>=BT->data)BT->Right=insert(X,BT->Right,len);
	}
	return BT;
}
void print(BinTree BT)
{
	if(BT!=NULL)
	{
		if(BT->Left==NULL&&BT->Right==NULL)printf("%d %d\n",BT->data,BT->height);
		print(BT->Left);
		print(BT->Right);
	}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		int len=0;
		if(BT==NULL)
		{
			BT=insert(m,BT,len);root=BT;
		}
		else BT=insert(m,BT,len);
	}
	//t=root->data;
	//printf("%d\n",root->data);
	print(root);
	return 0;
}

