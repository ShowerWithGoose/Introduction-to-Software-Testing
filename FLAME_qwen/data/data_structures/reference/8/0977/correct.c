/*【问题描述】

给定一个无向图和一个图顶点，编程输出该图删除给定顶点前后按深度优先遍历及广度优先遍历方式遍历的图顶点序列。

给定的无向图和图顶点满足以下要求：

1、无向图的顶点个数n大于等于3，小于等于100，输入时顶点编号用整数0～n-1表示；

2、无向图在删除给定顶点前后都是连通的；

3、无论何种遍历，都是从编号为0的顶点开始遍历，访问相邻顶点时按照编号从小到大的顺序访问；

4、删除的顶点编号不为0。

【输入形式】

先从标准输入中输入图的顶点个数和边的个数，两整数之间以一个空格分隔，然后从下一行开始分行输入每条边的信息（用边两端的顶点编号表示一条边，以一个空格分隔顶点编号，边的输入次序和每条边两端顶点编号的输入次序可以是任意的，但边不会重复输入），最后在新的一行上输入要删除的顶点编号。

【输出形式】

分行输出各遍历顶点序列，顶点编号之间以一个空格分隔。先输出删除给定顶点前的深度优先遍历顶点序列和广度优先遍历顶点序列，再输出删除给定顶点后的深度优先遍历顶点序列和广度优先遍历顶点序列。*/

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




