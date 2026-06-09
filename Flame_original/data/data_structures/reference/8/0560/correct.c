#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ph[100][100];
int p[100],q[100],m,n,j[100],k[100],top,tpo;
; void shendu(int z)
{
	int i;
	for (i = 0; i < m; i++)
	{
		if (p[i] == 0&&ph[z][i]==1)
		{
			p[i] = 1;
			j[top++] = i;
			shendu(i);
		}
	}

	return;
}
void guangdu()
{
	int front = 0,h,i;
	while (1)
	{
		h = k[front++];
		printf("%d ", h);
		q[h] = 1;
		for (i = 0; i < m; i++)
		{
			if (q[i] == 0 && ph[h][i] == 1)
			{
				k[tpo++] = i;
				q[i] = 1;
			}
		}
		if (front == tpo)
			break;
	}
	printf("\n");
	return 0;
}
int main()
{
	int a, b, c, d, i;
	p[0] = 1;
	q[0] = 1;
	j[top++] = 0;
	k[tpo++] = 0;
	scanf("%d%d", &m, &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		ph[a][b] = 1;
		ph[b][a] = 1;
	}
	scanf("%d", &c);//É¾³ý
	shendu(0);
	for (i = 0; i < m; i++)
	{
		printf("%d ", j[i]);
	}
	printf("\n");
	guangdu();
	for (i = 0; i < a; i++)
	{
		ph[i][c] = 0;
		ph[c][i] = 0;
	}
	memset(p, 0, sizeof(p));
	memset(q, 0, sizeof(q));
	memset(j, 0, sizeof(j));
	memset(k, 0, sizeof(k));
	top = 0;
	tpo = 0;
	p[c] = 1;
	q[c] = 1;
	p[0] = 1;
	q[0] = 1;
	j[top++] = 0;
	k[tpo++] = 0;
	shendu(0);
	for (i = 0; i < m-1; i++)
	{
		printf("%d ", j[i]);
	}
	printf("\n");
	guangdu();
	return 0;
}


