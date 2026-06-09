#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//freopen("damn.txt","r",stdin);//
	
	char s[120];
	char *p;
	
	gets(s);
	
	if((strstr(s,".")-s)>1)
	{
		int len=strstr(s,".")-s-1;
		int flag=0,i=0;
		
		while(s[i]!='\0')
		{
			
			if(s[i]=='.')
			{
				i++;
				continue;
			}
			
			
			printf("%c",s[i]);
			i++;
			if(flag==0) flag=1;
			if(flag==1)
			{
				flag=-1;
				printf(".");
			}
		}
		printf("e%d",len);
	}
	else
	{
		if(s[0]!='0')
		{
			printf("%s",s);
			printf("e0");
		}
		else
		{
			int j=0;
			while(s[j+2]=='0')
			{
				j++;
			}
			
			//printf("%c",s[2+j]);
			if(s[3+j]>='1'&&s[3+j]<='9')
			{
				
				printf("%c.%se-%d",s[2+j],s+3+j,j+1);
			}
			else
			{
			    printf("%ce-%d",s[2+j],j+1);
			}
			//printf("e-%d",j+1);
		}
	}
	
	
	
	return 0;
}

