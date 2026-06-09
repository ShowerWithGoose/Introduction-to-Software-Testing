#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	char s[10000],b,c; int j=0,i=0;
	gets(s); 
	while(s[i]!='\0')
	{
		if(s[i]=='-' && ((s[i-1]>=97 && s[i+1]>=97 && s[i-1]<=122 && s[i+1]<=122 && s[i+1]>s[i-1]) || (s[i-1]>=65 && s[i-1]<=90 && s[i+1]>=65 && s[i+1]<=90 && s[i+1]>s[i-1]) || (s[i-1]>='0' && s[i-1]<='9' && s[i+1]>='0' && s[i+1]<='9' && s[i+1]>s[i-1])))
		{
			b=s[i-1]; c=s[i+1];
			while(j<c-b-1)
			{
				printf("%c",b+j+1); j++;
			 } 
			 j=0;
		}
		else printf("%c",s[i]);
		i++;
	}
	return 0;
 } 

