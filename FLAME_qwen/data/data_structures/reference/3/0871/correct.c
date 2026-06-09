#include<stdio.h>
#include<string.h>
char Str[102];
int main()
{
	int i=1,m,n;
	int j;
	int flag=0;
	int sign=0;
	gets(Str);
	m=strlen(Str);
	
		if(Str[i]=='.')
		{
			if(Str[i-1]=='0')
			{
				flag++;	
		
			for(j=i+1;j<m;j++)
			{
				if(Str[j]=='0')
				{
				 flag++;
				}
				else
				 break;
			}
			if(j==m-1)
			printf("%c",Str[j]); 	
			else
			{
			printf("%c",Str[j]); 
			printf(".");
			for(;j<m-1;j++)
			{	
				printf("%c",Str[j+1]); 	
			}
			}
			printf("e-%d\n",flag);
			
			}
			else
			{
				for(j=0;j<m;j++)	
				{
					printf("%c",Str[j]);
				}
				printf("e0\n");
			}
		}
		else
		{
		printf("%c.",Str[i-1]); 
		 for(j=i;j<m;j++)
		 {
		 	if(Str[j]!='.')
		 	{
			 printf("%c",Str[j]);
			 if(sign==0)
			 flag++;
			}
			else
			{
			sign=1;
			continue;			
			}
		 }
		printf("e%d\n",flag);
		}
	
	
	return 0;
}

