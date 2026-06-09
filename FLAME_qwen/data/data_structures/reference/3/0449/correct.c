#include <stdio.h>
#include <string.h>
char a[120]={0};
char b[120]={0};
int main()
{
	scanf("%s",a);
	int i=0,j=0,flag=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>='1'&&a[i]<='9')
		{
			flag=i;
			b[j]=a[i];
			while(a[++i]!='\0')
			{
				b[++j]=a[i];
			}
			b[j+1]='\0';
			break;
		}
	}
	int cnt=0;
	if(flag==0)
	{
		printf("%c.",a[0]);
		for(i=1;b[i]!='\0';i++)
		{
			if(b[i]!='.')
			{
				printf("%c",b[i]);
			}
			else cnt=i-1;
		}
	 	printf("e%d",cnt);
	}
	else 
	{
		i=1;
		if(strlen(b)==1)
		{
			printf("%ce-%d",b[0],flag-1);
		}
		else 
		{
			printf("%c.",b[0]);
			while(b[i]!='\0')
			{
				printf("%c",b[i]);
				i++;
			}
			printf("e-%d",flag-1);
		}
	}
	return 0;
}

