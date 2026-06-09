#include<stdio.h>
int a[11],b[11],s[11];
int all(int ,int );
int main()
{
	int n,i;
	int k=0;
	scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	a[i]=i+1;
	}
	all(k,n);
	return 0;
}

int all(int k,int n)
{
	int o,p;
	if(k==n)
	{
		for(o=0;o<n;o++)
		{
			
			printf("%d ",b[o]);
			
		}
		printf("\n");
		return;
	}
	for(p=0;p<n;p++)
	{
		if(s[p]==0)
		{
			b[k]=a[p];
			s[p]=1;
			all(k+1,n);
			s[p]=0;
		
		}
	}
}

