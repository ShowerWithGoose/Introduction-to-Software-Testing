#include<stdio.h>
#include<string.h>

int main()
{
	char s[100];
	scanf("%s",s);
	getchar();
	if(s[0]=='0')
	{
		int i;
		for(i=2;s[i]=='0';i++);

		int j;
		for(j=strlen(s)-1;s[j]=='0';j--);
	
		if(i==j)
		printf("%c",s[i]);
		else{
			printf("%c.",s[i]);
			int t;
			for(t=i+1;t<=j;t++)
			{
				printf("%c",s[t]);
			}
		}
		printf("e-%d",i-1);
	}
	else
	{
		if(strchr(s,'.')!=NULL)
		{
			int j;
			for(j=strlen(s)-1;s[j]=='0'||s[j]=='.';j--);
			
			char *p=strchr(s,'.');
			int m=p-s;
			if(j==0)
			{
				printf("%c",s[0]);
			}
			else{
				int i;
				printf("%c.",s[0]);
				if(m==1)
				{
					for(i=2;i<=j;i++)
					{
						printf("%c",s[i]);
					}
				}
				else
				{
					for(i=1;i<=j;i++)
					{
						if(s[i]=='.')
							continue;
						printf("%c",s[i]);
					}	
					
				}
			}
			printf("e%d",m-1);
		}
		else
		{
			int j;
			for(j=strlen(s)-1;s[j]=='0';j--);
			
			if(j==0)
				printf("%c",s[0]);
			else
			{
				int i;
				printf("%c.",s[0]);
				for(i=1;i<=j;i++)
					printf("%c",s[i]);
			}
			printf("e%d",strlen(s)-1);	
		}
		
	}
	return 0;
}

