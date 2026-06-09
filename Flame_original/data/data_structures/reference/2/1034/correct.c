#include <stdio.h>
#include <string.h>
#include <signal.h>
char t[100];
int plus[100]={0},mul[100][100]={0};
int dig[100]={0};
char sig[100];
void deleteblank(char s[])
{
	int i,j,k;
	k=0;
	for (i=0; s[i]!='\0'; i++)
	{
		for (j=i;s[j]!=' '&&s[j]!='\0'; j++,k++)
			t[k]=s[j];
		i=j;
	}
}
void exchange(char s[])
{
	deleteblank(s);
	int i,j;
	int k=0;
	for (i=0; t[i]!='\0'; i++)
	{
		for (j=i; t[j]>='0'&&t[j]<='9'; j++)
			dig[k]=dig[k]*10+(t[j]-'0');
		sig[k]=t[j];
		k++;
		i=j;
	}
}
void calculate(char s[])
{
	exchange(s);
	if(sig[0]=='+'||sig[0]=='-'||sig[0]=='=')
		plus[0]=dig[0];
	int l=1;
	for (int p=0; sig[p]!='='; p++)
	{
		if((sig[p]=='+'||sig[p]=='-')&&(sig[p+1]=='+'||sig[p+1]=='-'||sig[p+1]=='='))
		{
			if(sig[p]=='+')
				plus[l]=dig[p+1];
			if(sig[p]=='-')
				plus[l]=-dig[p+1];
			l++;
		}
	}
	int m,n;
	for (m=0;sig[m]!='='&&sig[m]!='\0' ; m++)
		{
			int pro=dig[m];
			if(m>0&&sig[m-1]=='-')
				pro=-pro;
			if(sig[m]=='*'||sig[m]=='/')
			{
				for (n=m; (sig[n]=='*'||sig[n]=='/')&&sig[n]!='='; n++)
					{
						if(sig[n]=='*')
							pro*=dig[n+1];
						if(sig[n]=='/')
							pro=(int)pro/dig[n+1];
					}
				plus[l++]=pro;
				m=n;
			}
		}
	int ans=0;
	for (int r=0; r<l; r++)
	{
		ans+=plus[r];
	}
	printf("%d",ans);
	return;
}
int main(int argc, char *argv[]) {
	char s[100];
	gets(s);
	calculate(s);
	return 0;
}


