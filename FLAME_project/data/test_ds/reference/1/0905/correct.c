#include<stdio.h>
#include<string.h>

int main()
{
	char s[100];
	char c[100];
	gets(s);
	int i,j;
	int count;
	int len = strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]=='-')
		{	
			count = s[i+1]-s[i-1];
			if(count>0)
			{
			
			//printf("%d",count);
			if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a')
			{
				
					c[0]=s[i-1]+1;
					for(j=0;j<count-1;j++)
					{
						printf("%c",c[j]);
						c[j+1]=c[j]+1;
					}
				
			
			}
			else if(s[i-1]<'=9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0')
			{
				c[0]=s[i-1]+1;
					for(j=0;j<count-1;j++)
					{
						printf("%c",c[j]);
						c[j+1]=c[j]+1;
					}
				
			}
			else if(s[i-1]<'Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A')
			{
				c[0]=s[i-1]+1;
					for(j=0;j<count-1;j++)
					{
						printf("%c",c[j]);
						c[j+1]=c[j]+1;
					}
				
			}else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	return 0;
}



