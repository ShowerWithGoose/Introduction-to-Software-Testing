#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int main()
{	
	char str[100];
	char *p=NULL;
	int i,l;
	scanf("%s",str);
	p=strchr(str,'.');
	if(p==NULL)
	{
		puts(str);
	}
	else if(p-str==1) 
	{
		if(str[0]=='0')
		{
			for(i=2;i<strlen(str);i++)
			{
				if(str[i]!='0')
				{
					l=i;
					break;
				}
			}
			if(l==strlen(str)-1)
			{
				printf("%c",str[l]);
				for(i=l+1;str[i]!='\0';i++)
				{
					printf("%c",str[i]);
				}
				printf("e-%d",l-1);
			}
			else
			{
				printf("%c",str[l]);
				printf(".");
				for(i=l+1;str[i]!='\0';i++)
				{
					printf("%c",str[i]);
				}
				printf("e-%d",l-1);
			}
			
		}
		else
		{
			for(i=0;i<strlen(str);i++)
			{
				printf("%c",str[i]);
			}
			printf("e0");
		} 
	}
	else
	{
		l=p-str;
		printf("%c",str[0]);
		printf(".");
		for(i=0;i<=p-str-2;i++)
		{
			printf("%c",str[i+1]);
		}
		for(i=p-str+1;i<=strlen(str)-1;i++)
		{
			printf("%c",str[i]);
		}
		printf("e%d",l-1);
	}
    return 0;
}


