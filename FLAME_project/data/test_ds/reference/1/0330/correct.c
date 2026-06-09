#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[100000];
int main()
{
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++)
	{
			if(a[i]=='-')
			{
				if(islower(a[i-1])&&islower(a[i+1])&&a[i+1]>a[i-1])
				{
					for(int j=1;j<a[i+1]-a[i-1];j++)
					printf("%c",a[i-1]+j);
				}
				else if(isdigit(a[i-1])&&isdigit(a[i+1])&&a[i+1]>a[i-1])
				{
					for(int j=1;j<a[i+1]-a[i-1];j++)
					printf("%c",a[i-1]+j);
				}
				else if(isupper(a[i-1])&&isupper(a[i+1])&&a[i+1]>a[i-1])
				{
					for(int j=1;j<a[i+1]-a[i-1];j++)
					printf("%c",a[i-1]+j);
				}		
				else
				printf("-");	
			}
			else
			printf("%c",a[i]);
	} 
	return 0;
}
 

