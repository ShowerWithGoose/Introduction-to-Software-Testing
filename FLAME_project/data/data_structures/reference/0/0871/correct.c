#include<stdio.h>
#include<string.h>
char Str[10002];
int main()
{
	int n,m,i;
	int j;
	gets(Str);
	m=strlen(Str);
	for(i=0;i<m;i++)
   {
   		if(Str[i+1]=='-')
   		{
			if(Str[i]<='9'&&Str[i+2]<='9')
			{
				if(Str[i]<Str[i+2])
				{
				for(j=(Str[i]-'0');j<(Str[i+2]-'0');j++)
					printf("%d",j);
					i++; 
				}
				else
				printf("%c%c",Str[i],Str[i+1]); 
			
			}
			else if(Str[i]<='Z'&&Str[i+2]<='Z'&&Str[i]>='A'&&Str[i+2]>='A')
			{
				if(Str[i]<Str[i+2])	
				{
					for(j=(Str[i]-'0');j<(Str[i+2]-'0');j++)
					{
						printf("%c",Str[i]);
						Str[i]++;
					}
					i++;
				}	
				else
				printf("%c%c",Str[i],Str[i+1]); 			
			}
			else if(Str[i]<='z'&&Str[i+2]<='z'&&Str[i]>='a'&&Str[i+2]>='a')
			{
				if(Str[i]<Str[i+2])	
				{
					for(j=(Str[i]-'0');j<(Str[i+2]-'0');j++)
					{
						printf("%c",Str[i]);
						Str[i]++;
					}
					i++;
				}	
				else
				printf("%c%c",Str[i],Str[i+1]); 			
			}
			else
			printf("%c",Str[i]);
		}
   		else
   		printf("%c",Str[i]);
   }
	printf("\n");
	return 0;
} 



