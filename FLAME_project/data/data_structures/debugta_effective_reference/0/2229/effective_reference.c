#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(a=b;a<c;a++)
#define ll long long
#define ull unsigned long long
int main()
{
	char a[100]={'\0'},b[100]={'\0'};
	int k=0;
	scanf("%s",a);
	for(int i=0;i<100;k++,i++)
	{
		b[k]=a[i];
		if(a[i]=='-')
		{
			if(a[i-1]<a[i+1]&&a[i-1]>='A'&&a[i+1]<='Z')
			{
				int m=k-1,p=1;
				for(;k<m+a[i+1]-a[i-1];k++)
				{
					b[k]=a[i-1]+p;
					p++;
				}
				k=k-1;
			}
			else if(a[i-1]<a[i+1]&&a[i-1]>='a'&&a[i+1]<='z')
			{
				int n=k-1,w=1;
				for(;k<n+a[i+1]-a[i-1];k++)
				{
					b[k]=a[i-1]+w;
					w++;
				}
				k=k-1;
			}
			else if(a[i-1]<a[i+1]&&a[i-1]>='0'&&a[i+1]<='9')
			{
				int j=k-1,v=1;;
				for(;k<j+a[i+1]-a[i-1];k++)
				{
					b[k]=a[i-1]+v;
					v++;
				}
				k=k-1;
			}
		}
	}
	for(int x=0;x<100;x++)
	{
		printf("%c",b[x]);
	}
	return 0;
}



