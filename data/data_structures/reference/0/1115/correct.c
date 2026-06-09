#include<stdio.h>
#include<string.h>
int i,j;
char a[1000000],b[1000000];
int main()
{
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!='-') 
		{
			printf("%c",a[i]);
		} else
		{
			if( (a[i-1]>='0'&&a[i+1]>a[i-1]&&a[i+1]<='9') || (a[i-1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1]) || (a[i-1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1]))
			{
				int t=a[i+1]-a[i-1]-1;
				int m=1;
				for(;t>0;t--)
				{
					printf("%c",a[i-1]+m);
					m++;
					
				} continue;
				
			} else 
			{
				printf("%c",a[i]);
			}	
		}
	}
	
}

