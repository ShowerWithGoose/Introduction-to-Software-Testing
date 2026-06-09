#include<stdio.h>
#include<string.h>
int a[11],b[11],n;//a填入b手里有无 
void f(int);
int main()
{
	scanf("%d",&n);
	int i; 
	for(i=1;i<=n;i++)
	{
		b[i]=0;
		a[i]=i;
		printf("%d ",a[i]);
	}
	printf("\n");
	b[n]=1;
	a[n]=0;
	f(n-1);
}
void f(int i)
{
	int j,flag=0;
	if(i==n+1)
	{
		for(j=1;j<=n;j++)
		printf("%d ",a[j]);
        printf("\n");
        b[a[n]]=1;
        a[n]=0;
        f(n-1);
    }
    else
    {
	
	for(j=a[i]+1;j<=n;j++)
	{
		if(b[j]==1)
		{
			b[j]=0;
			b[a[i]]=1;
			a[i]=j;
			flag=1;
			
		}
		if(flag==1)
		break;
	}
	if(i==0)
	return;
	else if(flag==1)
	{
		f(i+1);
	}
	else
	{
		b[a[i]]=1;
		a[i]=0;
		f(i-1);
	}}
}

