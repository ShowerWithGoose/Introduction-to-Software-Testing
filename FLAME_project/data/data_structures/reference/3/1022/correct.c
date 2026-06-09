#include<stdio.h>
int main()
{
	char s[105];
	gets(s);
	int i,mark,k;
	for(i=0;i<=strlen(s);i++)
	{
		if(s[i]=='.')
		mark=i;
		else
		continue;
	}
	if(mark>=2)
	{
		printf("%c.",s[0]);
		for(i=1;i<mark;i++)
		printf("%c",s[i]);
		for(i=mark+1;i<strlen(s);i++)
		printf("%c",s[i]);
		printf("e%d",mark-1);
		return 0;
	}
	else if(mark==1)
	{
		if(s[0]+0>='1')
		{
		printf("%s",s);
		printf("e0");
		}
		else
		{
			for(i=2;i<strlen(s);i++)
		{
			if(s[i]+0!='0')
			{
			k=i;
			break;
			}
			
		}
		if(k==strlen(s)-1)
		printf("%ce-%d",s[k],k-1);
		else 
		{
		printf("%c.",s[k]);
		for(i=k+1;i<strlen(s);i++)
		printf("%c",s[i]);
		printf("e-%d",k-1);
		}
		
	}
	
		
}
}

