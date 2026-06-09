#include<stdio.h>
#include<string.h>
int main()
{
	int i,j=0,k,n;
	char a[1000000],b[1000000];
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
	if(a[i]=='-')
	{
	if(a[i-1]>='a'&&a[i+1]>a[i-1]&&a[i+1]<='z')
	{
		n=0;
		for(k=a[i-1];k+n+2<=a[i+1];n++)
		{
			b[j]=k+n+1;j++;
		}
	}
	else
	{
	if(a[i-1]>='A'&&a[i+1]>a[i-1]&&a[i+1]<='Z')
	{
	n=0;
		for(k=a[i-1];k+n+2<=a[i+1];n++)
		{
			b[j]=k+n+1;j++;
		}
	}
	else
	{
	if(a[i-1]>='0'&&a[i+1]>a[i-1]&&a[i+1]<='9')
	{
		n=0;
		for(k=a[i-1];k+n+2<=a[i+1];n++)
		{
			b[j]=k+n+1;j++;
		}
	}
	else
	{
		b[j]=a[i];j++;
	}
    }
	}
	}
	else
	{
		b[j]=a[i];j++;
	}
    }
	b[j]='\0';
	printf("%s",b);
	return 0;
}



