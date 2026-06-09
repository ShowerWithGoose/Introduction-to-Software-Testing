#include<stdio.h>
int main()
{	
		int j;
	int p,q;
	int h,l;
	int min;
	int temp;
	int m;
	int i,k;
	scanf("%d",&m);
	int s[11];
	for(i=0;i<m;i++)
	{
	s[i]=i+1;
	printf("%d ",s[i]);
	}printf("\n");
	int sum=1;
	int cnt;
	for(i=1;i<=m;i++)sum*=i;
for(cnt=0;cnt<sum-1;cnt++)
{
		
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
	return 0;
}
