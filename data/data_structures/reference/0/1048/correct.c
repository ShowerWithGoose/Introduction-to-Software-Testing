#include<stdio.h>
#include<string.h>
int main()
{
	char ch[100000];
	int i,j,len;
	scanf("%s",ch);
	len=strlen(ch)-1;
	for(i=0;i<=len;i=i+1)
	{
		if(ch[i]!='-'&&ch[i+1]!='-') 
		{
			printf("%c",ch[i]);
			continue;
		}
		else if(ch[i]!='-'&&ch[i+1]=='-')
		{
			i=i+1;
			if(('a'<=ch[i-1]&&ch[i-1]<='z'&&'a'<=ch[i+1]&&ch[i+1]<='z'&&ch[i-1]<ch[i+1])||('A'<=ch[i-1]&&ch[i-1]<='Z'&&'A'<=ch[i+1]&&ch[i+1]<='Z'&&ch[i-1]<ch[i+1])||('0'<=ch[i-1]&&ch[i-1]<='9'&&'0'<=ch[i+1]&&ch[i+1]<='9'&&ch[i-1]<ch[i+1]))
			{
				printf("%c",ch[i-1]);
				for(j=1;j<=ch[i+1]-ch[i-1]-1;j=j+1)
				{
					printf("%c",ch[i-1]+j);					
				}
			}
			else
			{
				printf("%c",ch[i-1]);
				printf("%c",ch[i]);
			}	
		} 
	}
	return 0;
}



