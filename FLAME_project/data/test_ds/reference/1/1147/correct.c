#include<stdio.h>
#include<string.h>
char str[1000000];
int main()
{
	scanf("%s",str);
	int i=0,j=0;
    for(i=0;str[i]!='\0';i+=2)
    {
        for(j=0;i<strlen(str)&&str[i+1]!='-';i++)
	{
		printf("%c",str[i]);
	}
	if(str[i+2]<='Z'&&str[i]>='A')
	{
		for(j=0;j<(str[i+2]-str[i]);j++)
		{
			printf("%c",str[i]+j);
		}
	 } 
	 else if(str[i+2]<='9'&&str[i]>='0')
	{
		for(j=0;j<(str[i+2]-str[i]);j++)
		{
			printf("%c",str[i]+j);
		}
	 } 
	else if(str[i+2]<='z'&&str[i]>='a')
	{
		for(j=0;j<(str[i+2]-str[i]);j++)
		{
			printf("%c",str[i]+j);
		}
	 } 
     else
     {
          printf("%c%c",str[i],str[i+1]);
     }
    }	
	return 0;
 } 
