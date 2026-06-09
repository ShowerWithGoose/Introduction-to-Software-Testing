#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define ll long long //9223372036854775807£¨>10^18£©   int -2^31=-21 4748 3648  2^31-1=21 4748 3647
#define ull unsigned ll
#define db double
char s[1000];
int check(char a,char b);
int main()
{
	int i,m;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='-')
		{
			if(check(s[i-1],s[i+1]))
			{
				m=s[i+1]-s[i-1];
				for(int j=strlen(s)-1;j>=i+1;j--)
				{
					s[j+m-2]=s[j];
				}
				for(int j=i;j<i+m-1;j++)
				{
					s[j]=s[i-1]+j-i+1;
				}
				i+=m-1;
			}
		}
	}
	printf("%s",s);
};

int check(char a,char b)
{
	if(a<b)
	{
		if((a>='a'&&a<='z')&&(b>='a'&&b<='z')) 
	    return 1;
	else if((a>='A'&&a<='Z')&&(b>='A'&&b<='Z')) 
	    return 1;
	else if((a>='0'&&a<='9')&&(b>='0'&&b<='9')) 
	    return 1;
	else return 0;
	}
	else return 0;
	
}



