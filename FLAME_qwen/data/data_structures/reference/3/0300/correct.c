#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char c[1000];
	scanf("%s",&c);
	int i=0,j=0,k=0;
	j=strlen (c);
	if(c[0]=='0')
	{
		if(c[1]=='\0')
		{
			printf("0e0");
		}
		else
		{
			while(i<=j)
		{
			if(c[i]!='0'&&c[i]!='.')
			{
				break;
			}
			else 
				i++;
		}
		k=i;
		if(c[k+1]=='\0')
		{
			printf("%ce-%d",c[k],i-1);
		}
		else
		{
			printf("%c.",c[k]);
			k=k+1;
			while(k<j)
			{
				printf("%c",c[k]);
				k++;
			}
			printf("e-%d",i-1);
		}
		}
		
	}
	else
	{
		printf("%c",c[0]);
		if(c[1]!='.'&&c[1]!='\0')
		{
			printf(".");
			i=1;
			while(c[i]!='.'&&i<j)
			{
				printf("%c",c[i]);
				i++;
			}
			k=i;
			if(c[i]=='.')
			{
				i=i+1;
				while(i<j)
				{
					printf("%c",c[i]);
					i++;
				} 
				printf("e%d",k-1);
			}
			else if(i=j-1)
			{
				printf("e%d",k-1);
			}
			
		}
		else if(c[1]=='.'&&c[1]!='\0')
		{
			printf(".");
			i=2;
			while(i<j)
			{
				printf("%c",c[i]);
				i++;
			}
			printf("e0");
		}
		else if(c[1]=='\0')
		{
			printf("e0");
		}
	}
	
	return 0;
	
}

