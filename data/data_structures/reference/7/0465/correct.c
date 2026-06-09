#include<stdio.h>
#include<stdlib.h>//申请内存malloc(例如 ：int*a；a=（int*）malloc（number*sizeof（int））；接下来就拿a当数组来用就可以了,最后要还内存free（a）a指的是最开始的原地址)
#include<math.h> // 开方sqrt(x)  x的y次方pow(x,y)
#include<stdbool.h> //C99 bool : true or false 布尔量本质还是整数,故输出还是1或0
#include<string.h>
#include<time.h>

typedef struct BiNode
{
	struct BiNode *lchild,*rchild;
	int data;
}BiNode;


//void insertBST (BiNode *bt,int key);
//BiNode* CreatBST (int *arrey,int length);
void midOrder(BiNode *T,BiNode *root);
void visit(BiNode *T,BiNode *root );
BiNode* InitTree(int x,BiNode* T);
int depth(BiNode *T,BiNode* root);

int main()
{
	int n;
	scanf ("%d",&n);
	int i;
	int *arrey=(int*)malloc(sizeof(int)*n);
	BiNode *p= NULL;
	for (i=0;i<n;i++)
	{
		int a;
		scanf ("%d",&a);
		arrey[i]=a;
		p=InitTree(a,p);
	}
	//BiNode *root=CreatBST (arrey,n);
//	printf ("%d\n",p->data );
	midOrder(p,p);
	return 0;
 } 
/* 
void insertBST (BiNode *bt,int key)//插入 
{
	if (bt==NULL)
	{
		bt=(BiNode*)malloc(sizeof(BiNode));
		bt->data = key;
		bt->lchild = NULL;
		bt->rchild = NULL;
	}
	else 
	{
		if (key < bt->data )
		{
			insertBST(bt->lchild ,key);
		}
		else 
		{
			insertBST(bt->rchild , key);
		}
	}
}

BiNode* CreatBST (int *arrey,int length)//创建二叉查找树 
{
	BiNode *root=NULL;
	int i;
	for (i=0;i<length;i++)
	{
		insertBST(root,arrey[i]);
	}
	return root;
}
*/ 
void midOrder(BiNode *T,BiNode *root)//中序遍历 
{
	//BiNode *root=T;
	if (T != NULL)
	{
		midOrder(T->lchild,root );
		visit(T,root);
		midOrder(T->rchild ,root);
	}
}

void visit(BiNode *T,BiNode *root)//访问操作，进行输出 
{
	if (T->lchild == NULL && T->rchild == NULL)
	{
		printf ("%d %d\n",T->data,depth(T,root));
		
	}
}

BiNode* InitTree(int x,BiNode* T)
{
	int i=0;
	if (T==NULL)
	{
		T=(BiNode*)malloc(sizeof(BiNode));
		if (T==NULL)
		{
			return 0;
		}
		else 
		{
			T->data = x;
			T->lchild = NULL;
			T->rchild = NULL;
		}
	}
	else
	{
		if (x < T->data )
		{
			T->lchild = InitTree(x,T->lchild );
		}
		else 
		{
			T->rchild = InitTree(x,T->rchild );
		}
	}
	return T;
 } 

int depth(BiNode *T,BiNode* root)
{
	int d=1;
	BiNode *r=root;
	//printf ("root=%d ",root->data );
	while (r->lchild != NULL || r->rchild != NULL)
	{
		if (r->data > T->data)
		{
			r=r->lchild ;
			d++;
		}
		else if (r->data <= T->data )
		{
			r=r->rchild ;
			d++;
		}
	}
	return d;
}



