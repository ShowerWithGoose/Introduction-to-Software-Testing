#include<stdio.h>
#include<string.h>
#include<ctype.h>
char str[105];
int main()
{
	int i,j=0,flag=0;
	gets(str);
	for(i=0;str[i]!='.';i++)
	flag++;
	if(flag>=2)
	{
		printf("%c%c",str[0],'.');
		for(i=1;str[i]!='\0';i++)
		{
			if(str[i]!='.')
			printf("%c",str[i]);
		}
		printf("%c%d",'e',flag-1);
	}
	if(flag==1&&str[0]!='0')
	{
		for(i=0;str[i]!='\0';i++)
		printf("%c",str[i]);
		printf("%c%d",'e',flag-1);
	}
	
	else if(flag==1&&str[0]=='0')
	{
		for(i=2;str[i]=='0';i++)
		j++;
		printf("%c",str[i]);
		if(str[i+1]!='\0')
		printf("%c",'.');
		for(i++;str[i]!='\0';i++)
		printf("%c",str[i]);
		printf("%c%c%d",'e','-',++j);
	}
	
	return 0;
}



