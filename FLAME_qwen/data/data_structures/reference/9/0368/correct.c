#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct ab{
	int a[2];
	int b[2];
};
struct ab num[105];
int cmp(const void *a,const void *b)
{
	if(((struct ab *)a)->a[0]>((struct ab *)b)->a[0])
		return 1;
	else
		return -1;
}
int main()
{
	int n,i,j,lenmax=1,len,fir,temp,now;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&num[i].a[0],&num[i].a[1],&num[i].b[0],&num[i].b[1]);
	}
	qsort(num,n,sizeof(struct ab),cmp);
	fir=0;
	for(i=0;i<n-1;i++)
	{
		len=1;
		temp=i;
		now=i;
		for(j=i+1;j<n;j++)
		{
			if(num[j].a[0]==num[now].b[0] && num[j].a[1]==num[now].b[1])
			{
				len++;
				now=j;
			}
		}
		if(len>lenmax)
		{
			lenmax=len;
			fir=temp;
		}
	}
	printf("%d %d %d",lenmax,num[fir].a[0],num[fir].a[1]);
	return 0;
}

