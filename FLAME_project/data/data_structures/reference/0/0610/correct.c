#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 
#define pi 3.14159265
#define eps 1e-10

int main()
{
	char a[100];
	int i;
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1]&&a[i]=='-')
		{
			for(int j=1;j<(a[i+1]-a[i-1]);j++)
			printf("%c",a[i-1]+j);	
		}
		else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1]&&a[i]=='-')
		{
			for(int j=1;j<(a[i+1]-a[i-1]);j++)
			printf("%c",a[i-1]+j);	
		}
		else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1]&&a[i]=='-')
		{
			for(int j=1;j<(a[i+1]-a[i-1]);j++)
			printf("%c",a[i-1]+j);	
		}
		else
		printf("%c",a[i]);
	}
//	printf("%c",a[z]);
	return 0;
	
 }

 


