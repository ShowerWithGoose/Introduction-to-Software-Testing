#include<stdio.h>
#include<string.h>
#include<string.h>
struct node
{
	int data;
	struct node *lchild, *rchild;
	int floor;
};
typedef struct node BTNode;
typedef struct node* BTNodeptr;
BTNodeptr Root = NULL;
void insert_Tree(int a)
{
	int floor = 1;
	BTNodeptr p, q = Root;
	p = (BTNodeptr)malloc(sizeof(BTNode));
	p->data = a;
	p->lchild = p->rchild = NULL;
	if(Root == NULL)
		Root = p, p->floor = floor;
	else
	{
		q = Root;
		while(1)
		{
			if(a < q->data)
			{
				if(q->lchild != NULL)
					q = q->lchild, floor++;
				else
				{
					q->lchild = p;
					p->floor = ++floor;	
					break;
				}
			}
			else 
			{
				if(q->rchild != NULL)
					q = q->rchild, floor++;
				else
				{
					q->rchild = p;
					p->floor = ++floor;	
					break;
				}
			}
		}
	}
}
BTNodeptr Stack[100];
int top = -1;
int main()
{
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		insert_Tree(x);
	}
	BTNodeptr p = Root;
	do
	{
		while(p != NULL)
		{
			Stack[++top] = p;
			p = p->lchild;
		}
		p = Stack[top--];
		if(p->lchild == NULL && p->rchild == NULL)
		{
			printf("%d %d\n", p->data, p->floor);
		}
		p = p->rchild;
	}while(!(p == NULL && top == -1));
	return 0;
	
}  

