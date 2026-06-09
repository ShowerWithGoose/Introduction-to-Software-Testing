#include <stdio.h>
#include <string.h>
int main()
{
	int p,n,q,t=0,g=0;
	char a[1000],b[2000];
	scanf("%s",a);
	n=strlen(a);
    for(int i=0;i<n;i++)
	{
		if(a[i]=='-')
		{
			p=a[i+1]-a[i-1];
			b[i-1+g]=a[i-1];
			if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i+1]>a[i-1])
			{
				for(int j=i+g;j<i+g+p;j++)
				{
					b[j]=b[j-1]+1;
				}
				g+=p-2;
			}
			else if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i+1]>a[i-1])
			{
				for(int j=i+g;j<i+g+p;j++)
				{
					b[j]=b[j-1]+1;
				}
				g+=p-2;
			}
			else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i+1]>a[i-1])
			{
				for(int j=i+g;j<i+p+g;j++)
				{
					b[j]=b[j-1]+1;
				}
				g+=p-2;
			}
			else
		{
			b[i+g]=a[i];
		}
		}
		else
		{
			b[i+g]=a[i];
		}
	}
	for(int i=0;i<n+g;i++)
		printf("%c",b[i]);
	return 0;
}



