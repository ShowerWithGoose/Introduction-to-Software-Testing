#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct list{
	int a[100];
	int x[100];
}list[4];
int main()
{
	int mid;
	int p=0;
	int i=0,j=0;
	int n=0,m=0;
	char k;
	do
	{
		scanf("%d%d",&list[1].a[i],&list[1].x[i]);
		i++;
		n++;
		k=getchar();
	}while(k!='\n');
	i=0;
		while(scanf("%d%d",&list[2].a[i],&list[2].x[i])!=EOF)
	{
		i++;
		m++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			list[3].a[p]=list[1].a[i]*list[2].a[j];
			p++;
		}
	}
	p=0;
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			list[3].x[p]=list[1].x[i]+list[2].x[j];
			p++;
		}
	}
	for(int i=0;i<p;i++)
	{
		for(int j=i+1;j<p;j++)
		{
			if(list[3].a[i]!=0&&list[3].a[j]!=0)
			{
				if(list[3].x[i]==list[3].x[j])
				{
					list[3].a[i]+=list[3].a[j];
					list[3].a[j]=0;
				}
			}
		}
	}
	for (int i = 0; i < p; i++) {
        for (int j = 0; j + 1 < p - i; j++) {
            if (list[3].x[j] < list[3].x[j+1]) {
                mid=list[3].x[j];
                list[3].x[j]=list[3].x[j+1];
                list[3].x[j+1]=mid;
                mid=list[3].a[j];
                list[3].a[j]=list[3].a[j+1];
                list[3].a[j+1]=mid;
            }
        }
    }
    for(int i=0;i<p;i++)
    {
    	if(list[3].a[i]!=0)
    	{
    		printf("%d %d ",list[3].a[i],list[3].x[i]);
		}
	}
	return 0;
}
