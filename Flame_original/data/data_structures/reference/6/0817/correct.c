#include<stdio.h>
int main()
{
	int a[1005];
	int i;
	for(i=1;;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1)
		    break;
	}
	int n=i;
	int b[105];
	int h=0;
	for(i=1;i<n;i++)
	{
		if(a[i]==1)
		{
			h+=1;
			b[h]=a[i+1];
			i+=1;
		}
		else if(a[i]==0&&h!=0)
		{
			printf("%d ",b[h]);
			h-=1;
		}
		else if(a[i]==0&&h==0)
		{
			printf("error ");
		}
	}
	return 0;
	
}

