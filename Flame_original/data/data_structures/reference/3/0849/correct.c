#include<stdio.h>
#include<string.h>
int main()
{
//	bool isfushu=false,isSmall=false;
	char s[105];
	int i,j,k,length;
	scanf("%s",s);
	length=strlen(s);

	if(s[0]=='-')
	{
		printf("-");
		if(length==2)
		{
			printf("%ce0",s[1]);
			
		}//排除掉科学技术法纯整数 
        else if(s[1]=='0')
		{
		    for(i=1;s[i]=='0'||s[i]=='.';i++);
				j=i-2;
				if(i<length-1)
				{
					printf("%c.",s[i]);
				}
				else
				{
					printf("%c",s[i]);
				}
				for(i++;i<length;i++)
				printf("%c",s[i]);
				
				printf("e-%d",j);
		}//首位数字是0 
		
		else if(s[1]>'0'&&s[1]<='9')
		{
			printf("%c.",s[1]);
			for(i=1;s[i]!='.'&&i<length;i++);
			j=i-2;
			for(i=2;i<length;i++)
			{
				if(s[i]!='.')
				printf("%c",s[i]);
			}
			printf("e%d",j);
		}//首位数字非零 
		
	}
	else if(s[0]!='-')
	{
		if(length==1)
		{
			printf("%ce0",s[0]);
		}
		else if(s[0]=='0')
		{
			for(i=0;s[i]=='0'||s[i]=='.';i++);
			j=i-1;
			if(i<length-1)
			{
				printf("%c.",s[i]);
			}
			else
			{
				printf("%c",s[i]);
			}
			for(++i;i<length;i++)
			printf("%c",s[i]);
			
			printf("e-%d",j);
		}
		else if(s[0]>'0'&&s[0]<='9')
		{
			printf("%c.",s[0]);
			for(i=0;s[i]!='.'&&i<length;i++);
//			printf("%d\n",i);
			j=i-1;
			for(i=1;i<length;i++)
			{
				if(s[i]!='.')
				printf("%c",s[i]);
			}
			
			printf("e%d",j);
			
		}
	}
	return 0;
	
	
}

