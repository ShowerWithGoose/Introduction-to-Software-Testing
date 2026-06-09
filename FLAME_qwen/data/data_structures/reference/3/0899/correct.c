#include <stdio.h>
#include <string.h>
int main()
{
	char s[101];
	gets(s);
	int flag=0,a=-1,c=0,flag1=0,a1=-1;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[0]!='0'&&i==0)
		{
			printf("%c",s[0]);
			if(i!=strlen(s)-1)
		{
			printf(".");
		}
		} 
		if(s[0]!='0') 
		{
		if(s[i]=='.') 
		{
		c=a;
		flag++;
		}
			a++;
		if(i==strlen(s)-1&&flag==0){
			c=a;
		}
		if(s[i]>='0'&&s[i]<='9'&&i!=0) 
		printf("%c",s[i]);
		}
	    if(s[0]=='0')
	    {
	    	if(s[i]=='0'&&flag1==0) a1++;
	    	if(s[i]=='0'&&flag1!=0)
			{ 
				printf("0");
			}
			if(s[i]!='0'&&flag1!=0&&s[i]!='.')
			{
				printf("%c",s[i]);
			 } 
	    	if(s[i]!='0'&&flag1==0&&s[i]!='.')
			{
				a1++;
				flag1++;
				printf("%c",s[i]);
				if(i!=strlen(s)-1) printf(".");
			 } 
			 
			if(i==strlen(s)-1)
			{
				c=-a1;
			}
		}
	}
	printf("e%d",c);
	return 0;
}

