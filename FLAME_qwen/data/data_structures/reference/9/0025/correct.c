#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, i, m, j, k, l=0, o;

int cmp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

typedef struct zuobiao
{
	int x1;
	int y1;
	int x2;
	int y2;
	
}d1;

int main()
{
	d1 c[200];
	
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d", &c[i].x1, &c[i].y1, &c[i].x2, &c[i].y2);
	}
	
	qsort(c, n, sizeof(c[0]), cmp);
	
	for(m=n-1;m>=0;m--)
	{
		j=m;
		k=1;
		for(i=m;i>=0;i--)
		{
			if((c[j].x1 == c[i].x2) && (c[j].y1 == c[i].y2))
			{
				j=i;
				k++;
			}
		if(l < k)
		{
			l=k;
			o=i;
			
		}
		}
	}
	
	printf("%d %d %d", l, c[o].x1, c[o].y1);
	
	return 0;
}




