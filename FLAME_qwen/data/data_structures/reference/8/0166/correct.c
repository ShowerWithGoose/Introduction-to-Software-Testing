#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int zong[300][300], guo[300] = { 0 }, queue[300];
int n, m;	
int push(int m)
{
	return queue[m++];
}
void DFS(int m)
{
	int i;
	printf("%d ", m);	
	guo[m] = 1;		
	for (i = 0; i < n; i++)
		if (zong[m][i] && !guo[i])	
		{
			DFS(i);		
		}
}
void BFS(int m)
{
	int i, head = 0, top = 1, tmp;	
	queue[head] = m;	
	while (head <= top)	
	{
		tmp = queue[head++];
		if (guo[tmp])	continue;	
		else
		{
			printf("%d ", tmp);		
			guo[tmp] = 1;			
			for (i = 0; i < n; i++)
				if (zong[tmp][i] && !guo[i])	
					queue[top++] = i;		
		}
	}

}
void init(int* p)
{
	memset(p, 0, sizeof(p));
}
void write(int i)
{
	if (i == 1)
	{
		DFS(0);
	}
	else
	{
		BFS(0);
	}
	puts("");
}
void delobj(int ob)
{
	guo[ob] = 1;
}
void intinit()
{
	memset(guo, 0, sizeof(guo));
}
int main()
{
	int a, b, i, del;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b); 
		zong[a][b] = 1;
		zong[b][a] = 1;
	}
	write(1);
	intinit();
	write(0);
	scanf("%d", &del);
	intinit();
	delobj(del);
	write(1);
	intinit();
	init(queue);
	delobj(del);
	write(0);
	return 0;
}
