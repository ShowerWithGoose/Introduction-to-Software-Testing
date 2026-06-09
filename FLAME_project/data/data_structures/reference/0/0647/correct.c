#include<stdio.h>
#include<string.h>
char s[100];
char c[100];

int main()
{
	int k=0;
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++)
	{
		c[k++] = s[i];
		if(s[i]=='-')
		{
			if(s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z')
		    {
		    	if(s[i-1]<=s[i+1])
		    	{
		    		int j=0;
		    		for(k=k-2;j<s[i+1]-s[i-1];j++)
		    		c[k++] = s[i-1]+j;
				}
			}
			else if(s[i-1]>='A' && s[i-1]<='Z' && s[i+1]>='A' && s[i+1]<='Z')
		    {
		    	if(s[i-1]<=s[i+1])
		    	{
		    		int j=0;
		    		for(k=k-2;j<s[i+1]-s[i-1];j++)
		    		c[k++] = s[i-1]+j;
				}
			}
			else if(s[i-1]>='0' && s[i-1]<='9' && s[i+1]>='0' && s[i+1]<='9')
		    {
		    	if(s[i-1]<=s[i+1])
		    	{
		    		int j=0;
		    		for(k=k-2;j<s[i+1]-s[i-1];j++)
		    		c[k++] = s[i-1]+j;
				}
			}
		 } 
	}
	printf("%s",c);
} 

