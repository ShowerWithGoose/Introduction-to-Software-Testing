#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	gets(s);
	int i,j;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='-'){
			printf("%c",s[i]);
		}
		else if(s[i]=='-')
		{if((s[i-1]<s[i+1])&&((s[i-1]>='0'&&s[i+1]<='9')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')))
		{
			for(j=1;(s[i-1]+j)<(s[i+1]);j++){
				printf("%c",s[i-1]+j);
			}
			
		}else printf("-");
		}
	}
		
	
	return 0;
}

