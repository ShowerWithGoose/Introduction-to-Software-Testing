#include<stdio.h>

int n, groupnum=0;
typedef struct _linegroup
{

	int x1;
	int x2;
	int y1;
	int y2;
	int count;
} linegroup, *pgroup;
typedef struct _line
{
	int xa;
	int xb;
	int ya;
	int yb;
} line, *pline;
linegroup g[100];
line l[105];
int cmp(const void*p1, const void*p2)
{
	int ans;
	pline a=(pline)p1;
	pline b=(pline)p2;
	ans=(a->xa)-(b->xa);
	if(ans!=0) return ans;
	else return (a->xb)-(b->xb);
}

void judge(int X, int Y, int X1, int Y1)
{
	int i, flag=0;
	for(i=0;i<groupnum;i++)
	{
		if(X==g[i].x1 && Y==g[i].y1)
		{
			g[i].count++;
			g[i].x1=X1;
			g[i].y1=Y1;
			flag=1; break;
		}
		else if(X==g[i].x2 && Y==g[i].y2)
		{
			g[i].count++;
			g[i].x2=X1;
			g[i].y2=Y1;
			flag=1; break;
		}
		else if(X1==g[i].x2 && Y1==g[i].y2)
		{
			g[i].count++;
			g[i].x2=X;
			g[i].y2=Y;
			flag=1; break;
		}
	}
	if(flag==0)
	{
		g[groupnum].x1=X;
		g[groupnum].y1=Y;
		g[groupnum].x2=X1;
		g[groupnum].y2=Y1;
		groupnum++;
		g[i].count++;
	}
}

int main()
{

	scanf("%d", &n);
	int i, j;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d", &l[i].xa, &l[i].ya, &l[i].xb, &l[i].yb);
	}
	qsort(l, n, sizeof(line), cmp);
	for(i=0;i<n;i++)
	judge(l[i].xa, l[i].ya, l[i].xb, l[i].yb);
	for(i=50;i>1;i--)
	{
		for(j=0;j<groupnum;j++)
		{
			if(g[j].count==i)
			{
				if(g[j].x1<g[j].x2)
				{
					printf("%d %d %d", g[j].count, g[j].x1, g[j].y1); 
					return 0;
				}
				else 
				{
					printf("%d %d %d", g[j].count, g[j].x2, g[j].y2); 
					return 0;
				}
			}
		}
	}
}

