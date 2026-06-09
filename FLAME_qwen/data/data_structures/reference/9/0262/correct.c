#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct point{
	int x1;
	int y1;
	int x2;
	int y2;
}Point, *line;
Point w[105];

int cmp_line(const void *p1, const void *p2)
{
	int ans;
	line po1 = (line) p1;
	line po2 = (line) p2;
	ans = po1->x1 - po2->x1;
	if(ans == 0)
	{
		ans = po1->y1 - po2->y1;
		if(ans == 0)
		{
			ans = po1->x2 - po2->x2;
			if(ans == 0)
			{
				ans = po1->y2 - po2->y2;
			}
		}
	}
	return ans;
}

int line_line(Point w[], int start, int n)
{
	int i, j, o;
	int sum;
	sum = 1;
	for(i = start; i < n - 1; i++)
	{
		o = 0;
		for(j = i + 1; j < n; j++)
		{
			if(w[j].x1 != -1 && w[j].x1 == w[i].x2 && w[j].y1 == w[i].y2) 
			{
				w[j].x1 = -1;
				sum++;
				i = j - 1;
				o++;
				break;
			} 
		}
		if(o == 0)return sum;
	}
	return sum;
}
int main()
{
	int n, i, j;
	int linee[105]={0};
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	scanf("%d%d%d%d",&w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
	qsort(w, n, sizeof(Point), cmp_line);
	for(i = 0; i < n; i++)
	{
		if(w[i].x1 != -1)
		linee[i] = line_line(w, i, n);
	}
	int max=0;
	for(i = 0; i < n; i++)
	{
		if(linee[i] > linee[max] && w[i].x1 != -1) max = i;
	}
	printf("%d %d %d", linee[max], w[max].x1, w[max].y1);
	return 0;
 } 

