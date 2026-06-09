#include<stdio.h>
#include<string.h>
#include<ctype.h>
int yes(char x,char y)
{
	if(isupper(x)&&isupper(y)&&x<y)return 1;
	if(islower(x)&&islower(y)&&x<y)return 1;
	if(isdigit(x)&&isdigit(y)&&x<y)return 1;
	else return 0;
}
int main()
{
	char s[1000]={0},s2[1000]={0};
	gets(s);int hh=0;int i;
	for( i=0;s[i]!='\0';i++)
	{
		
		if(s[i+1]=='-'&&yes(s[i],s[i+2]))
		{	int k=0;	
			for(;k==0||s2[hh-1]+1<s[i+2];hh++)
			{
			    s2[hh]=s[i]+k;
				k++;
			}i++;
		}
		else s2[hh++]=s[i];
	}s2[hh]='\0';
	puts(s2);
}

