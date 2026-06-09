#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int num[1000],mid[1000];char sym[1000];
void clean_(char s[])
{
	int i,j=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ') s[j++]=s[i];
	}
	s[j]='\0';
}
void drawnum(char s[])
{
	int i,j=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
		if(s[i+1]<'0'||s[i+1]>'9') num[j++]=s[i]-'0';
		else
		{
		int k;
		num[j]=s[i]-'0';
		for(k=1;s[i+k]>='0'&&s[i+k]<='9';k++)
		{
			num[j]*=10;num[j]+=(s[i+k]-'0');
		}
		j++;i+=k-1;	
		}	
		} 
	}
	num[j]=-1000000000;
}
void drawsym(char s[])
{
	int i,j=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9') continue;
		else sym[j++]=s[i];
	}
	sym[j]='\0';
}
void intmulti(char s[])
{
	int i,j=0;
	for(i=0;sym[i]!='\0';i++)
	{
		if(sym[i]=='+'||sym[i]=='-') continue;
		else 
		{
			int k=0;
			for(k=0;sym[i+k]!='+'&&sym[i+k]!='-'&&sym[i+k]!='=';k++)
			{
				if(sym[i+k]=='*') num[i]*=num[i+k+1];
				if(sym[i+k]=='/') num[i]/=num[i+k+1];
				num[i+k+1]=-1111111111;
		}
		i+=k;
		}
	}
}
void intnum(int num[])
{
	int i,j=0;
	for(i=0;num[i]!=-1000000000;i++)
	{
		if(num[i]!=-1111111111) mid[j++]=num[i];
	}
	mid[j]=-1111111111;
}
int main()
{
	char s[1000];
	gets(s);
	int len=strlen(s);
	if(s[0]=='-') {
		int i;
		for(i=len-1;i>=1;i--)
		s[i]=s[i-1];
		s[0]='0';
	} 
	clean_(s); 
	drawnum(s);
	drawsym(s);
	intmulti(sym);
	intnum(num);
	int ans=mid[0];
	int i,j=1;
	for(i=0;sym[i]!='=';i++)
	{
		if(sym[i]=='+')
		ans+=mid[j++];
		if(sym[i]=='-')
		ans-=mid[j++];
	}
	printf("%d",ans);
	return 0; 
} 



