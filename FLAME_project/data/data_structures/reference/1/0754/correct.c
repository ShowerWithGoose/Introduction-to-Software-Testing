#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void exb(int arr[],int a,int b)
{
	int i,j;
	for(i=a,j=b;i<j;i++,j--)
	{
		int replace=arr[i];
		arr[i]=arr[j];
		arr[j]=replace;
	}
}
void exs(int arr[],int a,int b)
{
	int replace=arr[a];
	arr[a]=arr[b];
	arr[b]=replace;
}
int main()
{
	int n,i,j,k,a,s[100],t;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		s[i]=i+1;
		printf("%d",s[i]);
		if(n==1)
		return 0;
		if(i<n-1)
		printf(" ");
	}
	for(;;)
	{
		for(i=n-1;i>=1;i--)
		{
			if(s[i]>s[i-1])
			break;
			if(i==1&&s[i]<s[i-1])
			return 0;
		}
		k=i-1;
		t=k+1;
		for(i=t;i<=n-1;i++)
		{
			if(s[i]>s[k]&&(s[t]<s[k]||s[i]<s[t]))
			t=i;
		}
		exs(s,k,t);
		exb(s,k+1,n-1);
		for(i=0;i<=n-1;i++)
		{
			if(i==0)
			printf("\n");
			printf("%d",s[i]);
			if(i<n-1)
			printf(" ");
		}
	}
}

