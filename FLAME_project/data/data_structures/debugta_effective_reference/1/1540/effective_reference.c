#include<stdio.h>
void exchange1(int *n,int p,int q)
{
	int hold;
	int i;
	hold=n[q];
	for(i=q;i>p;i--)
		n[i]=n[i-1];
	n[p]=hold;
}
void exchange2(int *n,int p,int q)
{
	int hold;
	int i;
	hold=n[p];
	for(i=p;i<q;i++)
		n[i]=n[i+1];
	n[q]=hold;
}
void f(int a[],int n,int m)
{
	int i;
	int hold,judge=0;
	if(n!=m)
	{
		for(i=n;i<=m;i++)
		{
			exchange1(a,n,i);
			f(a,n+1,m);
			exchange2(a,n,i);
		}
	}
	else if(m==n)
	{
		for(i=1;i<=m;i++)
		{
			printf("%d%c",a[i],i==m?'\n':' ');
		}
	}
}
int main()
{
	int m;
	int b[10];
	int hold,k,j=1;
	scanf("%d",&m);
	for(k=1;k<=m;k++)
		b[k]=k;
	f(b,1,m);
	return 0;
}






