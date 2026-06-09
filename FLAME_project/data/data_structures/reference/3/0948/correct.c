#include<stdio.h>
#include<string.h>
int main()
{
	char s1[105];
	int i,index;
	scanf("%s",s1);
	if(s1[0]!='0')
	{
		while(s1[i]!='.')i++;
		index=i-1;
		for(i=0;s1[i]!='\0';i++)
		{
			if(s1[i]=='.')continue;
			printf("%c",s1[i]);
			if(i==0)printf(".");
			
		}
		printf("e%d",index);
		
		
	}
	else 
	{
		while(s1[i]=='0'||s1[i]=='.')i++;
		index=(i-1)*(-1);
		for(;s1[i]!='\0';i++)
		{
			printf("%c",s1[i]);
			if(-1*index==i-1&&s1[i+1]!='\0')printf(".");
		}
		printf("e%d",index);
	}
	return 0;
}

