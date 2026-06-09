#include<stdio.h>
#include<string.h>


int main()
{
    char s[500];
    int i,j;
    scanf("%s",&s);
    for(i=0;i<=strlen(s)-1;i++)
    {
    	if(s[i]=='-'&&s[i-1]<s[i+1]&&s[i-1]>='0'&&s[i+1]<='9')
    	{
    		for(j=s[i-1]+1;j<s[i+1];j++)
    		printf("%c",j);
		}
		else if(s[i]=='-'&&s[i-1]<s[i+1]&&s[i-1]>='a'&&s[i+1]<='z')
		{
    		for(j=s[i-1]+1;j<s[i+1];j++)
    		printf("%c",j);
		}
		else if(s[i]=='-'&&s[i-1]<s[i+1]&&s[i-1]>='A'&&s[i+1]<='Z')
		{
    		for(j=s[i-1]+1;j<s[i+1];j++)
    		printf("%c",j);
		}
		else
		{
			printf("%c",s[i]);
		}
	}
	
    return 0;
}

