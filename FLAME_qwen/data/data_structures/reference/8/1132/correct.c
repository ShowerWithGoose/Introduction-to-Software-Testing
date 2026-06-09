#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>


#define MAX 100

int edge[MAX][MAX];

int deldata;  //删除的节点
int ver_num, edge_num;  //节点数和边数
int visited[MAX];

void read_data()
{
	scanf("%d %d", &ver_num, &edge_num);

	for (int i = 0; i < edge_num; i++)
	{
		int tmp1 = 0;
		int tmp2 = 0;
		scanf("%d%d", &tmp1, &tmp2);
		edge[tmp1][tmp2] = 1;
		edge[tmp2][tmp1] = 1;
	}

	scanf("%d", &deldata);
}


void del_data()
{
	for (int i = 0; i < ver_num; i++)
	{
		edge[deldata][i] = 0;
		edge[i][deldata] = 0;
	}
	visited[deldata] = 1;
}

void clean()
{
	for (int i = 0; i < ver_num; i++)
	{
		visited[i] = 0;
	}
}


void searchDFS(int n)
{
	printf("%d ", n);
	visited[n] = 1;
	for (int i = 0; i < ver_num; i++)
	{
		if ((!visited[i]) && edge[n][i])
		{
			searchDFS(i);
		}
	}
}



int queue[MAX];
int top;
int end;

void searchBFS(int v)
{
	queue[end] = v;
	end++;
	while (top <= end)
	{
		v = queue[top];  //取出队头元素
		top++;
		if (!visited[v])
		{
			printf("%d ", v);
			visited[v] = 1; //标识某顶点入队
			for (int i = 0; i < ver_num; i++) //访问该顶点的每个邻接顶点
			{
				if (!visited[i] && edge[v][i])
				{
					queue[end] = i;
					end++;
				}
			}
		}
		
	}
}






int main()
{
	read_data();
	searchDFS(0);
	printf("\n");
	clean();


	searchBFS(0);
	printf("\n");
	clean();


	del_data();


	searchDFS(0);
	printf("\n");
	clean();


	for (int i = 0; i < MAX; i++)
	{
		queue[i] = 0;
	}
	top = 0;
	searchBFS(0);
	printf("\n");
	clean();



	del_data();

	return 0;
}
