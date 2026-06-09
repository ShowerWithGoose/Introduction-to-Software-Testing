#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp( const void *a , const void *b )
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n,i=0,*p,a[20],j,temp,flag=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
		printf("%d ",a[i]);
	}
	printf("\n");
	while(flag==1)
	{
		i=n;
		flag=0;
		while(i>1)
		{
			i--;
			if(a[i]-a[i-1]>0)//找到开始下降的位置 
			{
				p=&a[i]; 
				qsort(p,n-i,sizeof(int),cmp);//将后面的从小到大排序 
				for(j=i;j<=n-1;j++)
				{
					if(a[j]-a[i-1]>0)
					{
						flag=1;
						temp=a[i-1];
						a[i-1]=a[j];
						a[j]=temp;//交换前后 
						break;
					}
				 } 
				for(j=0;j<n;j++)
				printf("%d ",a[j]);
				printf("\n");
				break; 
			}
		}
	}
    return 0;
} 




