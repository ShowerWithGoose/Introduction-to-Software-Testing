#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char s[10000];
int i,j;
int main()
{
	scanf("%s",s);
	for(i=0; s[i]!='\0'; i++)
	{
		if(s[i]=='-')
		{
			
			if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A')
				for(j=1; (s[i-1]+j)<s[i+1]; j++)
					printf("%c",s[i-1]+j);
			else if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a')
				for(j=1; (s[i-1]+j)<s[i+1]; j++)
					printf("%c",s[i-1]+j);
			else if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0')
				for(j=1; (s[i-1]+j)<s[i+1]; j++)
					printf("%c",s[i-1]+j);
            else
                printf("%c",s[i]);
		}
		else
			printf("%c",s[i]);
	}
	return 0;
}


