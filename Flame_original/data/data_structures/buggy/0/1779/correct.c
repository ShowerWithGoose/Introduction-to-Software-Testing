#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	char s[100];
	gets(s);
	
	for(int i=0;s[i]!='\0';i++)
	{
	
			if(((isupper(s[i-1])&&isupper(s[i+1]))||
			(islower(s[i-1])&&islower(s[i+1]))||
			(isdigit(s[i-1])&&isdigit(s[i+1])))&&(s[i+1]-s[i-1]>=0)&&s[i]=='-')
			{
				for(int q=1;q<s[i+1]-s[i-1];q++)
				{
					printf("%c",(char)(s[i-1]+q));
				}
				
			}
		
		else
		printf("%c",s[i]);
	}

	return 0;
}
