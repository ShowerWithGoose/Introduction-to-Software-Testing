#include<stdio.h>
#include<string.h> 
void quanpailie(int *x,int *y,int n,int a);
int main()
{
	int i,n;
	int x[105]={0};
	int y[105]={0};
	scanf("%d",&n);
	quanpailie(x,y,n,1);
	return 0;
}
void quanpailie(int *x,int *y,int n,int a)
{
	int i;
	if(a==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",x[i]);
		}
		printf("\n");
		return;
    }
		for(i=1;i<=n;i++)
		{
			if(y[i]==0)
			{
				y[i]=1;
				x[a]=i;
				quanpailie(x,y,n,a+1);
				y[i]=0; 
			}
		}
}




