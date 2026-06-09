#include<stdio.h>
void exchange1(int *m,int p,int q)
{
	int hold;
	int i;
	hold=m[q];
	for(i=q;i>p;i--)
		m[i]=m[i-1];
	m[p]=hold;
}
void exchange2(int *m,int p,int q)
{
	int hold;
	int i;
	hold=m[p];
	for(i=p;i<q;i++)
		m[i]=m[i+1];
	m[q]=hold;
}
void f(int a[],int m,int n)
{
	int i;
	int hold,judge=0;
	if(m!=n)
	{
		for(i=m;i<=n;i++)
		{
			exchange1(a,m,i);
			f(a,m+1,n);
			exchange2(a,m,i);
		}
	}
	else if(n==m)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d%c",a[i],i==n?'\n':' ');
		}
	}
}
int main()
{
	int n;
	int b[10];
	int hold,k,j=1;
	scanf("%d",&n);
	for(k=1;k<=n;k++)
		b[k]=k;
	f(b,1,n);
	return 0;
}






