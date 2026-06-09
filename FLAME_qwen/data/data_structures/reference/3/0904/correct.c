#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]={0};
	int i=0;
	int k=0;
	int m=0;
	scanf("%s",s);
	if(s[0]!='0')
	{
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		{
			k=i;	
					printf("%c.",s[0]);
					for(i=1;i<k;i++)
					{
						printf("%c",s[i]);
					}
					for(i=k+1;i<strlen(s);i++)
					{
						printf("%c",s[i]);
					}
					printf("e%d",k-1);			
			}
		}
}
        if(s[0]=='0')
        {
        	for(i=0;i<strlen(s);i++)
        	{
        		if(s[i]=='.')
        		{
        			k=i;
				}}
			for(i=k+1;i<strlen(s);i++)
				
			{
					if(s[i]-'0'!=0)
				{
					m=i;
					if(i==strlen(s)-1)
					{
					printf("%c",s[m]);}
					if(i<strlen(s)-1)
					{
						printf("%c.",s[m]);
					}
					for(i=m+1;i<strlen(s);i++)
					{
						printf("%c",s[i]);
					}
					printf("e-%d",m-k);
				}
		}
			
		}
	
	return 0;
}

