#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct num{
	int x;
	int y;
}num; 
int cmp(const void *a, const void *b);
int main()
{
	struct num A[100];
	struct num B[100];
	struct num C[10000];
	int i=0,j=0;
	while(scanf("%d%d",&A[i].x,&A[i].y)==2)
	{
		if(getchar()=='\n')
		{
			break;
		}
		i++;
	}
	while(scanf("%d%d",&B[j].x,&B[j].y)==2)
	{	
		if(getchar()=='\n')
		{
			break;
		}
		j++;
	}
	int m=0,n=0,k=0;
	while(m<=i)
	{
		n=0;
		while(n<=j)
		{
			C[k].x=A[m].x*B[n].x;
			C[k].y=A[m].y+B[n].y;
			k++;
			n++;
		}
		m++;
	}
	qsort(C,k,sizeof(num),cmp);
	int l=0;
	while(l<k-1)
	{
		if(C[l].y!=C[l+1].y)
		{
			printf("%d %d ",C[l].x,C[l].y);
		}
		else 
		{
			C[l+1].x=C[l+1].x+C[l].x;
		}
		l++;
	}
	printf("%d %d",A[i].x*B[j].x,A[i].y+B[j].y);
	return 0;
}
int cmp(const void *a, const void *b)
{
	num *a1=(num *)a;
	num *b1=(num *)b;
	return(b1->y - a1->y);
}

