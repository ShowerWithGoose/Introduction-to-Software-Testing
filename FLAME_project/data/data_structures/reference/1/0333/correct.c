#include <stdio.h>
void array(int m,int s[]);
long fac(int b);
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
		printf("%d ",a[i]);
	}
	printf("\b");
	printf("\n");
	long f=fac(n);
	for(i=0;i<f-1;i++)
	{
		array(n,a);
	}
	return 0;
}
void array(int m,int s[])
{
	int j;
	int p,q;
	int h,l;
	int min;
	int temp;
	for(j=m-2;j>=0;j--)
	{
		if(s[j]<s[j+1])
		{
			p=j;
			break;
		}
	}
	min=m;
	for(j=p+1;j<m;j++)
	{
		if(s[j]>s[p]&&s[j]<=min)
		{
			min=s[j];
			q=j;
		}
	}
	temp=s[p];
	s[p]=s[q];
	s[q]=temp;
	h=m;l=p+1;
	for(h--;h>l;l++,h--) 
	{
 		temp=s[l];
 		s[l]=s[h];
 		s[h]=temp;
 	}
	for(j=0;j<m;j++)
	{
		printf("%d ",s[j]);
	}
	printf("\b");
	printf("\n"); 
}
long fac(int b)
{
	if(b==1)
	return 1;
	else
	return b*fac(b-1);
}
