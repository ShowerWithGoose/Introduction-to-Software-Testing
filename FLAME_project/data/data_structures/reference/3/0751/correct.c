#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[150],c[150];
int main()
{
	char *p;
	int l;
	scanf("%s",a);
	p=strchr(a,'.');
	if(p==a+1)
	{
		if(a[0]=='0')
		{
			for(int j=2;j<=strlen(a)-1;j++)
			{
				if(a[j]!='0')
				{
					 l=j;
					break;
				}
			}	
				if(l==strlen(a)-1)
				{
					printf("%c",a[l]);
					printf("e-%d",l-1);
				}
			    else {
					printf("%c",a[l]);
					printf(".");
					for(int j=l+1;j<=strlen(a)-1;j++)
					  printf("%c",a[j]);
					printf("e-%d",l-1);			    
				}
		}
		else 
		{
			printf("%s",a);
			printf("e0");
		}
	}
	else 
	{
		printf("%c",a[0]);
		printf(".");
		for(int j=1;(j<strlen(a));j++)
			{
				if(a[j]!='.')
				printf("%c",a[j]);
			}
		printf("e%d",p-a-1);
	}
	return 0;
}

