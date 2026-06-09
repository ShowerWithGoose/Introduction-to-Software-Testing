#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define eps 1e-15
char s[100000];

int main()
{
	gets(s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='-' && i!=0 && i!=strlen(s)-1)
		{
			if((s[i-1]>='0' && s[i+1]<='9') + (s[i-1]>='a'&&s[i+1]<='z') + (s[i-1]>='A'&&s[i+1]<='Z') ==1)
			{
				if(s[i-1]!=s[i+1])
					for(int j=1;j<s[i+1]-s[i-1];j++)
						printf("%c",s[i-1]+j);
				else
					printf("-");
			}
			else
				printf("-");
		}
		else
			printf("%c",s[i]);
	}
	
}

