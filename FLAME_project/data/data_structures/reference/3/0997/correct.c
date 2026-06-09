#include <stdio.h>
#include <string.h>
int main()
{
	char a[10000];
	int i,n=0,t=1;
	gets(a);
	int l=strlen(a);
	if(l==1)
	{printf("%ce0",a[0]);return 0;}
	if(a[0]!='0')
		{
			printf("%c.",a[0]);
			for(i=1;i<l;i++)
			{
				
				if(a[i]!='.')
				printf("%c",a[i]);
				if(t&&a[i]!='.')
					n++;
				else
					 t=0;	
			}
		}
	else
	{
		for(i=2;i<l;i++)
			{	
				if(a[i]=='0')
					{n--;continue;}
				printf("%c",a[i]);break;
			}
		i=i+1;
		if(i!=l)
		printf(".");
		for(i=i;i<l;i++)
		printf("%c",a[i]);
		n--;
	} 
	printf("e%d",n);
}



