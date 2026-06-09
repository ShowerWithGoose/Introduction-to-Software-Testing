#include <stdio.h>
#include <string.h>
#include <signal.h>
char ques[100];
int plus[100]={0},mul[100][100]={0};
int ans[100]={0};
char sig[100];
void deleteblank(char ques0[])
{
	int i,j,k;
	k=0;
	for (i=0; ques0[i]!='\0'; i++)
	{
		for (j=i;ques0[j]!=' '&&ques0[j]!='\0'; j++,k++)
			ques[k]=ques0[j];
		i=j;
	}
}
void exchange(char ques0[])
{
	deleteblank(ques0);
	int i,j;
	int k=0;
	for (i=0; ques[i]!='\0'; i++)
	{
		for (j=i; ques[j]>='0'&&ques[j]<='9'; j++)
			ans[k]=ans[k]*10+(ques[j]-'0');
		sig[k]=ques[j];
		k++;
		i=j;
	}
}
void calculate(char ques0[])
{
	exchange(ques0);
	if(sig[0]=='+'||sig[0]=='-'||sig[0]=='=')
		plus[0]=ans[0];
	int q=1;
	for (int p=0; sig[p]!='='; p++)
	{
		if((sig[p]=='+'||sig[p]=='-')&&(sig[p+1]=='+'||sig[p+1]=='-'||sig[p+1]=='='))
		{
			if(sig[p]=='+')
				plus[q]=ans[p+1];
			if(sig[p]=='-')
				plus[q]=-ans[p+1];
			q++;
		}
	}
	int m,n;
	for (m=0;sig[m]!='='&&sig[m]!='\0' ; m++)
		{
			int pro=ans[m];
			if(m>0&&sig[m-1]=='-')
				pro=-pro;
			if(sig[m]=='*'||sig[m]=='/')
			{
				for (n=m; (sig[n]=='*'||sig[n]=='/')&&sig[n]!='='; n++)
					{
						if(sig[n]=='*')
							pro*=ans[n+1];
						if(sig[n]=='/')
							pro=(int)pro/ans[n+1];
					}
				plus[q++]=pro;
				m=n;
			}
		}
	int ans0=0;
	for (int i=0; i<q; i++)
	{
		ans0+=plus[i];
	}
	printf("%d",ans0);
	return;
}
int main(int argc, char *argv[]) {
	char ques0[100];
	gets(ques0);
	calculate(ques0);
	return 0;
}


