#include<stdio.h>
#include<string.h>
char s[1000005];
int main()
{
	int i,fl=0;char j;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
	if(s[i]=='-')
	{
		fl=0;
		if(s[i-1]>='0'&&s[i+1]<='9') 
		{
			j=s[i-1]+1; 
			while(j<s[i+1])
			{
				putchar(j);
				j++;
				fl=1;
			}
		}
		else if(s[i-1]>='a'&&s[i+1]<='z')
		{
			j=s[i-1]+1; 
			while(j<s[i+1])
			{
				putchar(j);
				j++;
				fl=1;
			}
		}
		else if(s[i-1]>='A'&&s[i+1]<='Z')
		{
			j=s[i-1]+1; 
			while(j<s[i+1])
			{
				putchar(j);
				j++;
				fl=1;
			}
		}
		if(!fl) putchar(s[i]);
	}
	else putchar(s[i]);
	return 0;
 } 



