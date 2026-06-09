#include<stdio.h>
#include<string.h>
char a[103];
int main()
{
	int i=0,j;
	
	gets(a);
	if(a[0]!='0') {
	while(a[i]!='.') i++;
	printf("%c.",a[0]);
	if(i!=1)
	for(j=1;j<strlen(a);j++)
	{

		if(j!=i) printf("%c",a[j]);
		
	}
	else for(j=2;j<strlen(a);j++)
	{
		printf("%c",a[j]);
	}
	if(i==1) printf("e0");
	else printf("e%d",i-1);
	}
	else 
	{
		int flag=0;
		for(j=0;j<strlen(a);j++)
		{
			if(a[j]!='0'&&a[j]!='.')
				flag++;
		}
		while(a[i]=='.' || a[i]=='0') i++;
		if(flag>1)
		printf("%c.",a[i]);
		else printf("%c",a[i]);
		for(j=i+1;j<strlen(a);j++)
		{
			printf("%c",a[j]);
		}
		printf("e-%d",i-1);
	}
}

