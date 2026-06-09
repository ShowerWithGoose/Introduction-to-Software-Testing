#include<stdio.h>
#include<string.h>
#include<math.h>
int shu[1000],eachshu[1000];
int main()
{
	char s[1000],s1[1000],s2[1000]; int len,i=0,j=0,ci=0,re=0,shu1,k=0,n=0,xian=0,flag=0;
	gets(s); len=strlen(s);
	while(i<len)
	{
		if(s[i]!=' ')
		{
			s1[j]=s[i];
			j++;
		}
		if(s[i]=='*' || s[i]=='/')
		{
			s2[k]=s[i]; k++; xian++;
		}
		if(s[i]=='+' || s[i]=='-')
		{
			s2[k]=s[i]; k++; ci++;
		}
		i++;
	}
	s2[k]='=';
	len=strlen(s1); i=0; j=0; k=0;
	while(i<len)
		{
			if(s1[i]>='0' && s1[i]<='9')
			{
				eachshu[n]=s1[i]-'0';
				n++;
			}
			if(s1[i]=='+' || s1[i]=='=' || s1[i]=='-' || s1[i]=='*' || s1[i]=='/')
			{
				n--;
				while(n>=0)
				{
					shu[k]=eachshu[n]*(int)pow(10,j)+shu[k];
					n--; j++;
				}
				n=0; j=0; k++; memset(eachshu,0,1000); 
			}
			i++;
		}
		i=0;
		len=strlen(s2); k=0;
	if(ci+xian>0)
	{
		while(i<len)
		{
			if(s2[i]=='*' || s2[i]=='/')
			{
				if(s2[i]=='*') shu[i+1]=shu[i]*shu[i+1];
				if(s2[i]=='/') shu[i+1]=shu[i]/shu[i+1];
				flag++;
			}
			if(s2[i]!='*' && s2[i]!='/' && flag!=0)
			{
				while(flag>0)
				{
					shu[i-flag]=shu[i];
					flag--;
				}
				flag=0;
			}
			i++;//还剩ci个加减 ci+1个数 
		}
		i=0;
		if(ci!=0)
		{
			re=shu[0]; 
			while(i<len)
			{
				if(s2[i]=='+')
				{
					re=re+shu[i+1];
				}
				if(s2[i]=='-')
				{
					re=re-shu[i+1];
				}
				i++;
			}
			printf("%d ",re);
		}
		else if(ci==0) printf("%d",shu[0]); 
	}
	else printf("%d",shu[0]);
	return 0;
}


