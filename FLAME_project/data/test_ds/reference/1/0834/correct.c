#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	scanf("%s",a);
	int i,j;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>='a'&&a[i+1]=='-'&&a[i+2]<='z')
		{
		
			for(j=a[i];j<a[i+2];j++)
		printf("%c",j);
			i++;
		}
		else if(a[i]>='A'&&a[i+1]=='-'&&a[i+2]<='Z')
		{
		
			for(j=a[i];j<a[i+2];j++)
		printf("%c",j);
			i++;
		}
		else if(a[i]>='0'&&a[i+1]=='-'&&a[i+2]<='9')
		{
		
			for(j=a[i];j<a[i+2];j++)
		printf("%c",j);
			i++;
		}
		else
		printf("%c",a[i]);
	}
	return 0;
}



