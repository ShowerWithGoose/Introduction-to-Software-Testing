#include<stdio.h>
#include<string.h>
int main()
{
	char a[1005];
	scanf("%s",a);
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		if(a[i]=='-')
		{
			if(a[i-1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])
			{
				for(char j=a[i-1]+1;j<=a[i+1]-1;j++)
				printf("%c",j);
		    }
		    else if(a[i-1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
		    {
		    	for(char j=a[i-1]+1;j<=a[i+1]-1;j++)
				printf("%c",j);
			}
			else if(a[i-1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])
			{
				for(char j=a[i-1]+1;j<=a[i+1]-1;j++)
				printf("%c",j);
			}
			else printf("%c",a[i]);
		}
		else 
		{
			printf("%c",a[i]);
		}
	}
	return 0; 
 } 

