#include <stdio.h>
#include <string.h>
char s[100001],t[100001];
int x[10001];
int op1[10001];
long long ans=0;
void calc(int n,int m)
{
	int i,tmp=0,res=1,tag=0,sign=1;
	for(i=0;i<n;++i)
	{
		if(t[i]!='*'&&t[i]!='/')
			tmp = tmp*10+(t[i]-'0');
		else
		{
			tag = 1;
			if(sign) res*=tmp;
			else res/=tmp;
			tmp = 0;
			if(t[i]=='*') sign=1;
			else sign=0;
		}
	}
	if(sign) res*=tmp;
	else res/=tmp;
	if(tag) x[m] = res;
	else x[m] = tmp;
}
int main()
{
	gets(s);
	int i,j,k,sign;
	for(i=j=k=0;s[i]!='\0';++i) //去空格，统计加减运算符个数 
	{
		if(s[i]=='+'||s[i]=='-') op1[++k]=s[i]-'+'; // + < -
		if(s[i]!=' ')
			s[j++]=s[i];
	}
	s[j]='\0';
	for(i=0,j=0,k=0;s[i]!='\0';++i)
	{
		if(s[i]!='+' && s[i]!='-' && s[i]!='='){
			t[j++]=s[i];
		}
		else{
			k++; calc(j,k); j=0; memset(t,0,sizeof(t));
		}
	}
	ans = x[1];
	for(i=2;i<=k;++i)
	{
		if(op1[i-1]) sign=0; // - 
		else sign=1; // +
		if(sign) ans+=x[i];
		else ans-=x[i];
	}
	printf("%lld\n",ans);
	return 0;
}



