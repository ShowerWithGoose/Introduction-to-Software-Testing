#include<stdio.h>
void qd(int a[],int b[],int m,int n);
int b[20] = {0};
int main()
{
	int a[20];
	int n;
	int i; 
	scanf("%d", &n);
	qd(a,b,0,n);
	return 0;
}
void qd(int a[], int b[], int m,int n)
{
	int i = 0;
	if(m >= n)
	{
		for(i = 0;i < n-1;i ++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[i]);
	}
	else if(m < n)
	{
		for(i = 0;i < n;i ++)
		{
			if(b[i] == 0)
			{
				b[i] = 1;
				a[m] = i + 1;
				qd(a,b,m+1,n);
				b[i] = 0;
			}
		}
	}
}



