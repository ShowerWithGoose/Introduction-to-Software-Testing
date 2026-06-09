#include<stdio.h>
#include<stdlib.h>
void fullpermutation(int [], int, int);
void swap(int*, int*);
int cmp(const void*, const void*);
int a[15];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i]=i+1;
	fullpermutation(a,n,0);
	return 0;
}
void fullpermutation(int b[], int m, int n)
{
	int i;
	if(n==m)
	{
		for(i=0;i<m;i++)
			printf("%d ",b[i]);
		printf("\n");
	}			
	else for(i = n; i < m; i++)
	{
		qsort(b+n,m-n,sizeof(int),cmp);
		swap(&b[i],&b[n]);
		fullpermutation(b,m,n+1);
		swap(&b[i],&b[n]);
	}
}
int cmp(const void *p, const void *q)
{
	if(*(int*)p - *(int*)q > 0)
		return 1;
	else
		return -1;
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

