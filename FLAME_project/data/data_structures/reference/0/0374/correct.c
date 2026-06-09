#include <stdio.h>
#include <math.h>
#include <string.h> 

int main()
{
	char a[1000]={0};
	scanf("%s",&a);
	int i=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='-')
		{
			if(a[i-1]>='0' && a[i-1]<='9' && a[i+1]>='0' && a[i+1]<='9' && a[i-1]<a[i+1])
			{
				int j=a[i-1]-'0'+1;
				for(;j<a[i+1]-'0';j++)
				{
					printf("%d",j);
				}
			}
			else if(a[i-1]>='a' && a[i-1]<='z' && a[i+1]>='a' && a[i+1]<='z' && a[i-1]<a[i+1]) 
			{
				int j=1;
				for(;a[i-1]+j<a[i+1];j++)
				{
					printf("%c",a[i-1]+j);
				}
			}
			else if(a[i-1]>='A' && a[i-1]<='Z' && a[i+1]>='A' && a[i+1]<='Z' && a[i-1]<a[i+1]) 
			{
				int j=1;
				for(;a[i-1]+j<a[i+1];j++)
				{
					printf("%c",a[i-1]+j);
				}
			}
			else 
				printf("%c",a[i]);
		}
		else 
			printf("%c",a[i]);
	}
	return 0;
} 

