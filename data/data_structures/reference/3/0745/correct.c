#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
char s[105];
int main()
{
	gets(s);
	int a=0,b=0,flag=0,s1=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='.')
		{
			a=i-1;
			//if(s[0]=='0') a=len-2;
			
		}
		if((s[i]!='0')&&(s[i]!='.')&&(flag==0))
		{
			flag=1;
			s1=i;
		}
	}
		if(s[0]=='0') a=s1-1;;
	printf("%c",s[s1]);
	if((len-s1)!=1) printf("."); 
	for(int i=s1+1;i<len;i++)
	{
		if(s[i]!='.')
		printf("%c",s[i]);
	}
	printf("e");
	if(s1>1) printf("-");
	printf("%d",a) ;
	
	return 0;
}



