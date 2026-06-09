#include<stdio.h>
#include<stdlib.h>
int arr[101][4]={0};
int cmp(const void*a,const void*b)
{
	return (int)(((int*)a)[0]-((int*)b)[0]);
}
int main()
{
	int n,i,max=1,tmp=1,headx,heady,tailx,taily,maxx,maxy,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3]);
	}
	qsort(arr,n,sizeof(arr[0]),cmp);
	headx=arr[0][0];heady=arr[0][1];tailx=arr[0][2];taily=arr[0][3];
	for(i=0;i<n-1;i++)
	{
		tmp=1;
		tailx=arr[i][2];
		taily=arr[i][3];
		for(j=i+1;j<n;j++)
		{
			if(arr[j][0]==tailx&&arr[j][1]==taily)
			{
				tailx=arr[j][2];
				taily=arr[j][3];
				tmp++;
			}
			else if(arr[j][0]>tailx)
			         break;
		}
		if(tmp>max)
		{max=tmp;
		maxx=arr[i][0];
		maxy=arr[i][1];
		}
	}
	printf("%d %d %d",max,maxx,maxy);
	return 0;
}

