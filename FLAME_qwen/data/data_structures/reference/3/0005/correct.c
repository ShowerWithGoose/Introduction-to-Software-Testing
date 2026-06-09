#include<stdio.h>
#include<string.h>
int main(){
	char s[1024];
	gets(s);
	int i=0,j=strlen(s),x=0,k=0,y=0;
	for(i=0;s[i]!='.';i++)
	{	
	}
	for(j=strlen(s);s[j-1]!='.';j--)
	{
		x++;
	}
		if(i==1&&s[0]!='0')
		{
			printf("%c.",s[0]);
			for(k=1;k!=strlen(s);k++)
			{
				if(s[k]!='.')
				{
					printf("%c",s[k]);
				}
			}
			
			printf("e0");
		}
		
		if(i==1&&s[0]=='0')
		{
			for(k=2;s[k]=='0';k++)
			{
				
			}
			if(s[k+1]>'0'&&s[k+1]<='9')
			printf("%c.",s[k]);
			else
			printf("%c",s[k]);
			for(y=k+1;y!=strlen(s);y++)
			{
				printf("%c",s[y]);
			}
			printf("e-%d",k-1);
		}	
		if(i!=1)
		{
			printf("%c.",s[0]);
			for(k=1;k!=strlen(s);k++)
			{
				if(s[k]!='.')
				{
					printf("%c",s[k]);
				}
			}
			printf("e%d",i-1);
		}
	

	
	return 0;
}

