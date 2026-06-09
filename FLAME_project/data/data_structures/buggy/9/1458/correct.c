#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct _line
{
	int x1;
	int y1;
	int x2;
	int y2;
} Line,*Lineptr;

Line L[110];
int arr[110][4];

int cmp(const void *p1,const void *p2) {
	int *d1=(int *)p1;
	int *d2=(int *)p2;
	if(*d1<*d2)
		return -1;
	else if(*d1>*d2)
		return 1;
	else
		return 0;
}
int main()
{
	int i,j,n,k=0,flag=0,max=0,cnt=1,max_k=-1,cnt_i=0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&arr[cnt_i][0],&arr[cnt_i][1],&arr[cnt_i][2],&arr[cnt_i][3]);
		if(arr[cnt_i][0]<arr[cnt_i][2])
		{
			cnt_i++;
		}
	}
	
	qsort(arr,n,sizeof(arr[0]),cmp);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(arr[i][0]==arr[j][2]&&arr[i][1]==arr[j][3])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			L[k].x1=arr[i][0];
			L[k].y1=arr[i][1];
			L[k].x2=arr[i][2];
			L[k].y2=arr[i][3];
			k++;
		}
		flag=0;
	}
	
	for(i=0;i<k;i++)
	{
		cnt=1;
		for(j=0;j<n;j++)
		{
			if(flag==1)
			{
				j=0;
				flag=0;
			}
			if(L[i].x2==arr[j][0]&&L[i].y2==arr[j][1])
			{
				L[i].x2=arr[j][2];
				L[i].y2=arr[j][3];
				flag=1;
				cnt++;
			}
		}
		if(cnt>max)
		{
			max=cnt;
			max_k=i;
		}
	}
	
	printf("%d ",max);
	printf("%d %d",L[max_k].x1,L[max_k].y1);
	return 0;
}



