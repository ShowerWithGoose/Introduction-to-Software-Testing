#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

char suan[1000+5];
char s[1000+5];
char sym[1000+5];
int num[1000+5];

int main()
{
	gets(suan);
	int i,j=0,k;
	for(i=0;i<strlen(suan);i++)
	{
		if(suan[i]!=' ')
			s[j++]=suan[i];
	}
	j=0,k=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='=')
		{
			num[j]=num[j]*10+(s[i]-'0');
		}
		else 
		{
			j++;
			sym[k++]=s[i];
		}
	}
	
//	for(i=0;i<10;i++)
//		printf("%d ",num[i]);
//	for(i=0;i<6;i++)
//		printf("%c ",sym[i]);
	for(i=0;i<strlen(s);i++)
	{
		if(sym[i]=='-')
			num[i+1]=-num[i+1];
	}
	
	for(i=0;i<strlen(sym);i++)
	{
		if(sym[i]=='*')
		{
			num[i+1]=num[i]*num[i+1];
			num[i]=0;
		}
		else if(sym[i]=='/')
		{
			num[i+1]=num[i]/num[i+1];
			num[i]=0;
		}
	}
	
//	for(i=0;i<10;i++)
//		printf("%d ",num[i]);
	int ans=0;
	for(i=0;i<strlen(sym)+1;i++)
	{
		ans+=num[i];
	}
	printf("%d",ans);
	return 0;
}

//5 1 2 3 12 2 2
//- * * + / /


