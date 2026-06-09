#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int lx,ly,rx,ry;
} node;

node a[100005];

int cmp(const void*a1, const void*a2)
{
	node *a0 = (node*)a1;
	node *b0 = (node*)a2;
	return (a0->lx) - (b0->lx);
}

int main()
{
	int i,j,k;
	int n,num=0,X,Y;
	scanf("%d", &n);
	for(i = 1;  i <= n; i++)
		scanf("%d%d%d%d", &a[i].lx, &a[i].ly, &a[i].rx, &a[i].ry);
	
	qsort(a+1, n, sizeof(a[0]), cmp);
	
//	for(i = 0;  i <= n-1; i++)
//		printf("%d %d %d %d\n", a[i].lx, a[i].ly, a[i].rx, a[i].ry);
	
	
	for(i = 1; i <= n; i++)
	{
		int cur = i+1, cnt = 1;
		int x = a[i].rx;
		int y = a[i].ry;
		while(cur <= n)
		{
			while((a[cur].lx!=x||a[cur].ly!=y) && cur <= n)
				cur++;
			if(a[cur].lx==x && a[cur].ly==y)
				x = a[cur].rx, y = a[cur].ry, cnt++;
		}
		if(num < cnt)
			num = cnt, X = a[i].lx, Y = a[i].ly;
	}
	
	printf("%d %d %d", num, X, Y);
	
	
	
	
	return 0;
}

