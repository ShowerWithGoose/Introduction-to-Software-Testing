#include<stdio.h>
#include<string.h>
int main()
{
	char s[1010]={0};
    char fuhao[1010],fuhao1[1010];
    char shuzi[1010]={0};
    int shu[1010]={0},shu1[1010];
    int i,j;
	int p,q,p1;
	int l;
	gets(s);
	 for(i=j=0;s[i]!='\0';i++)
		if(s[i]!=' ')
		s[j++]=s[i];
		s[j]='\0';
	l=strlen(s);
	p=0,q=0;
	for(i=0;i<=l;i++)
	{
		if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='='))
		{	
		  fuhao[q]=s[i];
		  shuzi[p]=' ';
		  q++;
		  p++;
		}
		else
		{
		  shuzi[p]=s[i];
		  p++;
	    }   	
	}
	
	l=strlen(shuzi);
	p=0;
	for(i=0;i<=l;i++)
	{
		if(shuzi[i]!=' ')
		{
			while(shuzi[i]!=' ')
			{
				shu[p]=shu[p]*10+(s[i]-'0');
				i++;
			}
			p++;
		}
	}
	
	p=0,p1=0,q=0;
	l=strlen(fuhao);
	for(i=0;i<=l;i++)
	{
		if((fuhao[i]=='+'||fuhao[i]=='-'))
		{
			fuhao1[q]=fuhao[i];
			q++;
			shu1[p1]=shu[p]; 
			p++;
			p1++;
		}
		if(fuhao[i]=='*')
		{
			shu[p+1]=shu[p]*shu[p+1];
			p++;
		}
		shu1[p1]=shu[p];
		if(fuhao[i]=='/')
		{
			shu[p+1]=shu[p]/shu[p+1];
			p++;
		} 
		shu1[p1]=shu[p];
	}

	p1=1;
	for(i=0;i<q;i++)
	{
		if(fuhao1[i]=='-')
		{
			shu1[0]=shu1[0]-shu1[p1];
			p1++;
		}
		if(fuhao1[i]=='+')
		{
			shu1[0]=shu1[0]+shu1[p1];
			p1++;
		}
	} 
	printf("%d",shu1[0]);
	return 0;
}


