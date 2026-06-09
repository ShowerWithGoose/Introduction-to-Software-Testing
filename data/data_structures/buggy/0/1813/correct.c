#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	gets(s);
	if(strlen(s)<=2)
	printf("%s",s);
	else
	{
		for(int i=1;i<=strlen(s)-2;)
		{if(s[i]!='-')
		{printf("%c",s[i-1]);
		i++;
		}
		else
		{
		int flag=0;
		if(s[i-1]<='z'&&s[i-1]>='a')
		{if(s[i+1]<='z'&&s[i+1]>='a'&&s[i+1]>s[i-1])
		flag=1;
		}
		else if(s[i-1]<='Z'&&s[i-1]>='A')
		{if(s[i+1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1])
		flag=1;
		}
		else if(s[i-1]<='9'&&s[i-1]>='0')
		{if(s[i+1]<='9'&&s[i+1]>='0'&&s[i+1]>s[i-1])
		flag=1;
		}
		if(flag==1)
		{for(int j=0;j<s[i+1]-s[i-1];j++)
		printf("%c",s[i-1]+j);
		}
		else
		printf("%c%c",s[i-1],s[i]);
		i+=2;}
	}
	printf("%c",s[strlen(s)-1]);
	
}
return 0;
}
