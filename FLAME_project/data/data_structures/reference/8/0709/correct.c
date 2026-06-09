#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLINE 1024
#define eps 1e-15
#define tolower(c) (c>='A' && c<='Z' ? 'a'-'A' + c:c)
int vertex[109][109], Isvertex[109], Queue[109];

struct BstNode {               //二叉树结点定义 
     int data; 
     struct BstNode *left,*right; 
};

// 按要求用递归的方式创建二叉树，将数据存放在树中的合适位置
struct BstNode * insNode (struct BstNode *root, int data) 
{ 
     struct BstNode * p; 
     if(root==NULL) 
     {
           p=(struct BstNode*)malloc(sizeof(struct BstNode)); 
           p->data=data; 
           p->left=p->right=NULL; 
           return p; 
      } 
     else if (data<root->data) 
            root->left=insNode(root->left, data); 
     else 
            root->right=insNode(root->right, data);
     return root;
  } 
void printLeafNode(struct BstNode *root,int hight) 
{    // 以后序遍历的方式打印叶结点值和高度
     if(root->left!=NULL) 
            printLeafNode(root->left,hight+1); 
     if(root->right!=NULL) 
            printLeafNode(root->right,hight+1); 
      if(root->left==NULL && root->right==NULL); 
}

struct BstNode *root=NULL;  

void DFS(int v, int t)
{
	Isvertex[t] = -1;
	printf("%d ", t);
	int i;
	for (i = 0; i < v; i++)
	{
		if (vertex[t][i] == 1)
		{
			if (Isvertex[i] != -1)
			{
				DFS(v, i);
			}
		}
	}
}

void beforeD(int v)
{
	int i, j;
	for (i = 0; i < v; i++)
		for (j = 0; j < v; j++)
			if (vertex[i][j] == 1)
				if (Isvertex[i] != -1)
				{
					DFS(v, i);
					break;
				}
	printf("\n");
	return;
}

void BFS(int v, int t)
{
	int i, start = 0, end = -1;
	printf("%d ", t);
	Isvertex[t] = -1;
	Queue[++end] = t;
	while (start <= end)
	{
		t = Queue[start++];
		for (i = 0; i < v; i++)
		{
			if (vertex[t][i])
				if (Isvertex[i] != -1)
				{
					printf("%d ", i);
					Isvertex[i] = -1;
					Queue[++end] = i;
				}
		}
	}
	return;
}
void beforeB(int v)
{
	int i, j;
	for (i = 0; i < v; i++)
	{
		for (j = 0; j < v; j++)
			if (vertex[i][j] == 1)
				if (Isvertex[i] != -1)
				{
					BFS(v, i);
					break;
				}
	}
	printf("\n");
	return;
}

int main(void)
{
	int hanchangjian = 19,data,lzx;  
      for(lzx=0;lzx<hanchangjian;lzx++) {           //读入n个整数
            data = lzx*lzx; 
            root=insNode(root,data);  //建树并填数
      }
      printLeafNode(root,1);  
	int i, j, k, ver, side;
	scanf("%d%d", &ver, &side);
	for (k = 0; k < side; k++)
	{
		scanf("%d %d", &i, &j);
		vertex[i][j] = vertex[j][i] = 1;
	}
	beforeD(ver);
	memset(Isvertex, 0, sizeof(Isvertex));
	beforeB(ver);
	int d;
	scanf("%d", &d);
	for (i = 0; i < ver; i++)
	{
		vertex[i][d] = vertex[d][i] = 0;
	}
	memset(Isvertex, 0, sizeof(Isvertex));
	beforeD(ver);
	memset(Queue, -1, sizeof(Queue));
	memset(Isvertex, 0, sizeof(Isvertex));
	beforeB(ver);
}



