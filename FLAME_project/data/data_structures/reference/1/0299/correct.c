#include <stdio.h>
void tiqian(int a[],int b,int c)
{
	int i;
	int x=a[c];
	for(i=c;i>b;i--)
	{
		a[i]=a[i-1];
	}
	a[b]=x;
}
void huiwei(int a[],int b,int c)
{
	int i;
	int x=a[b];
	for(i=b;i<c;i++)
	{
		a[i]=a[i+1];
	}
	a[c]=x;
}
dayin(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void pailie(int a[],int b,int c)
{
	if(b==c)
		dayin(a,c+1);
	else
	{
		int i;
		for(i=b;i<=c;i++)
		{
			tiqian(a,b,i);
			pailie(a,b+1,c);
			huiwei(a,b,i);
		}		
	}

 } 

int main()
{
	int n;
	scanf("%d",&n);
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	pailie(a,0,n-1);

	return 0;
}



