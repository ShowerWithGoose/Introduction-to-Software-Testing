#include<stdio.h>
#include<string.h>

char deci[105];
char *dot;
int flag,front,behind,num;

int main()
{
	gets(deci);
	
	dot=strchr(deci,'.');
	front=dot-deci;
	//printf("%d\n",front);
	if((front==1)&&(deci[0]=='0'))
	{
		flag=0;
		dot++;
		while(*dot=='0')
		{
			num++;
			dot++;
		}
		if(*(dot+1)=='\0')
		{
			printf("%s%c",dot,'e');
			printf("%c",flag?'+':'-');
			printf("%d",num+1);
		}
		else
		{
			printf("%c%c",*dot,'.');
			dot+=1;
			printf("%s%c",dot,'e');
			printf("%c",'-');
			printf("%d",num+1);
		}
	}
	else
	{
		flag=1;
		*dot='\0';
		num=strlen(deci);
		printf("%c%c%s",deci[0],'.',deci+1);
		printf("%s%c",dot+1,'e');
		printf("%d",num-1);
	}
	return 0;
}


