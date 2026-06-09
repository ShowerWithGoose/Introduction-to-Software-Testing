#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[203][4];
int n;
int cnt;
int ans;
int x;
int stt;
int cmp(const void *p1,const void *p2)
{
	return *(int *)p1-*(int *)p2;
}
void fun(int a[][4],int n,int k)
{
	int i,j;

	for (i=k+1;i<n;i++)
	{
		if (a[k][2]==a[i][0]&&a[k][3]==a[i][1])
		{
			cnt++;
			if (cnt==1)
				stt=k;
			fun(a,n,i);
		}
	}
}

int main()
{
	scanf("%d",&n); 
	int i;
	for (i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	qsort(a,n,sizeof(a[0]),cmp);



	int temp=0;
	int j,k;

	for (k=0;k<n-1;k++)
	{
		fun(a,n,k);
		if (ans<cnt)
		{
			ans=cnt;
			x=stt;
			
		}
		cnt=0;
	}

	printf("\n%d %d %d",ans+1,a[x][0],a[x][1]);
	return 0;
 } 

