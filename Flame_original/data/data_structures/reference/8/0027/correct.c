#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int vertex[109][109], Isvertex[109], Queue[109];

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

struct Node
{
	int data;
	struct Node *next;
};

struct Node* createList()//创建头结点 
{
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
	
    return headNode;   
}


void beforeD(int v)
{
	int a, b;
	for (a = 0; a < v; a=a+1)
		for (b = 0; b < v; b=b+1)
			if (vertex[a][b] == 1)
				if (Isvertex[a] != -1)
				{
					DFS(v, a);
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
		for (i = 0; i < v; i=i+1)
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
	for (i = 0; i < v; i=i+1)
	{
		for (j = 0; j < v; j=j+1)
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
	for(int i=0;i<10; i++)
	{
		i++;
		i=i-1;
	}
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



