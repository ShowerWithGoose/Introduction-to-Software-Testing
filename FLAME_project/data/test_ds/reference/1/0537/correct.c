#include<stdio.h>
int main()
{
	char s[10000];
	int i,j;
	gets(s);
	for(i=j=0;s[i]!='\0';i++)
    {
    	if(s[i]!='-')
    	printf("%c",s[i]);
    	if(s[i]=='-')
		{
			if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')
		{
		   for(j=s[i-1]+1;j<s[i+1];j++)
		   {
		   	printf("%c",j);
		   }	
		}
		else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')
		{
		   for(j=s[i-1]+1;j<s[i+1];j++)
		   {
		   	printf("%c",j);
		   }	
		}
		else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')
		{
		   for(j=s[i-1]+1;j<s[i+1];j++)
		   {
		   	printf("%c",j);
		   }	
		}
		else
		printf("-");
		}
	}	
	return 0;
}

