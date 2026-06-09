#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	scanf("%s",&a);
    
	if(a[0]=='0')
    {
    	int i=2;
    	while(a[i]=='0')
    	{
    		i++;
		}
		int n=i-1;
		char b[100];
		b[0]=a[i];
		int j=2;
		while(a[i+1]!='\0')
		{
			b[1]='.';
			b[j++]=a[++i];
		}
		printf("%se-%d",b,n);
	}
	else if(a[0]!='0'&&a[1]=='.')
	{
		printf("%se0",a);
	}
	else //if(a[0]!='0'&&a[1]!='.')
	{
		char b[100];
		b[0]=a[0];
		b[1]='.';
		int i=1;
		int j=2;
		while(a[i]!='.')
		{
			b[j++]=a[i++];
		}
		int n=i-1;
		int k=i+1;
		while(a[k]!='\0')
		{
			b[j++]=a[k++];
		}
		printf("%se%d",b,n);
	}
    return 0;
}

