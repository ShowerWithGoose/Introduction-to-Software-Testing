#include <stdio.h> 
//先reverse排序，再倒序连线 
int main()
{
	int a[1000],b[1000],max=0,i,j,num,flag[1000],c[1000],d[1000],count[1000],cc;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		flag[i]=i;
		count[i]=1;
	}
	for(i=num;i>0;i--)
	{
		for(j=0;j<i-1;j++)
		{
			if(a[flag[j]]>a[flag[j+1]])
			{
				cc=flag[j];
				flag[j]=flag[j+1];
				flag[j+1]=cc;
			}
		}
	}
//	for(i=0;i<num;i++)
//	printf("%d %d %d %d\n",a[flag[i]],b[flag[i]],c[flag[i]],d[flag[i]]);
	for(i=num-1;i>0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[flag[i]]==c[flag[j]]&&b[flag[i]]==d[flag[j]])
			{
				count[flag[j]]+=count[flag[i]];
				break;
			}
		}
		if(count[flag[j]]>max)
		max=count[flag[j]];
//		printf("%d\n",max);
	}
	printf("%d ",max);
	for(i=0;i<num;i++)
	{
		if(count[flag[i]]==max)
		{
			printf("%d %d",a[flag[i]],b[flag[i]]);
			break;
		}
	}
	return 0;
}

