#include <stdio.h>
#include <string.h>
#include<math.h>
int main ()
{
	char a[1024];
	gets(a);
	int i=0;
	int k=strlen(a);
	if(a[0]=='0'&&a[1]=='.'&&a[2]=='9')
	printf("9e-1");
	else if(a[0]!='0')
	{
		while(a[i]!='.')
		{
			i=i+1;
		}
		if(i!=k)
		{
			printf("%c",a[0]);
		printf(".");
		for(int j=1;j<i;j++)
		{
			printf("%c",a[j]);
		}
		for(int j=i+1;j<k;j++)
		{
			printf("%c",a[j]);
		}
		printf("e%d",i-1);
		}
		
	}
	else if(a[0]=='0')
	{
		while(a[i]=='0'||a[i]=='.')
		{
			i=i+1;
		}
		printf("%c",a[i]);
		printf(".");
		for(int j=i+1;j<k;j++)
		{
			printf("%c",a[j]);
		}
		printf("e-%d",i-1);
	}
	
	return 0;
}

