#include <stdio.h>
int main()
{
	char s[10000];
	scanf("%s",&s);
	int i=1,j;
	printf("%c",s[0]);
	while(s[i]!='\0')
	{
		if(s[i]=='-')
		{
			if((s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])||(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])||(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])) 
			{
				for(j=1;j<s[i+1]-s[i-1];j++)
				{
					printf("%c",s[i-1]+j);
				}
			}
			else
			{
				printf("-");	
			}	
		}
		else
			printf("%c",s[i]);
		i++;
	}
	return 0;
}



