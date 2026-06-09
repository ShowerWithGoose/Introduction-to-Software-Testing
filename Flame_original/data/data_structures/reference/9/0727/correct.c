#include <stdio.h>
#include <string.h>
struct L
{
	int start1;
	int start2;
	int end1;
	int end2;
	int num;
};
int main()
{
	int i,j;
	int n,k;//n为线段个数 
	int mid=0;//中间点
	int max_len=0;
	int re=0;//返回re+1 
	int a[100][100];
	struct L arr[100];
	while(n<2||n>100)
	{
		scanf("%d",&n);
	}
	for(i=0;i<n;i++)
	{
		while(a[i][0]>=a[i][2])
		{
			scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			continue;
			if(a[i][0]==a[j][2]&&a[i][1]==a[j][3])
			{
				mid=1;
				break;
			}
		}
		if(mid==0)
		{
			arr[k].start1=a[i][0];
			arr[k].start2=a[i][1];
			arr[k].end1=a[i][2];
			arr[k].end2=a[i][3];
			k++;
		}
		mid=0;
	} 
	for(i=0;i<k;i++)
	{
		arr[i].num=1;
		for(j=0;j<n;j++)
		{
			if(arr[i].end1==a[j][0]&&arr[i].end2==a[j][1])
			{
				arr[i].end1=a[j][2];
				arr[i].end2=a[j][3];
				arr[i].num++;
				j=-1;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		if(max_len<arr[i].num)
		{
			max_len=arr[i].num;
			re=i;
		}
	}
	printf("%d %d %d\n",arr[re].num,arr[re].start1,arr[re].start2);
	return 0;
}



