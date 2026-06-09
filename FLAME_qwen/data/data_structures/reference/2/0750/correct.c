#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
char s[10010],ch[10010],ss[10010];
struct oprt
{
	int val;//12+-  
	int num;//在总数组中的位置 
}node[10010];//记录+- 
int b[10010],h[10010],flag[10010];
int j,i,k,p,q,t,g;

int cal(int a,int c)
{
	q=0;
	t=0;
	g=0;
	for(p=a;p<c;p++)
	{ 
		if(ch[p]!='*'&&ch[p]!='/') ss[q++]=ch[p];
		else 
		{
			h[g++]=atoi(ss);
			q=0;
			memset(ss,'\0',sizeof(s)-1);
			if(ch[p]=='*') flag[t++]=1;
			else flag[t++]=2;
		}
	}
	h[g++]=atoi(ss);
	q=0;
	memset(ss,'\0',sizeof(ss)-1);
	int ans=h[0];
	for(p=0;p<t;p++)
	{
		if(flag[p]==1) ans*=h[p+1];
		else ans/=h[p+1];
	}
	memset(flag,0,sizeof(flag));
	memset(h,0,sizeof(h));
	return ans;
}

int main()
{
	gets(s);
	j=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!=' '&&s[i]!='=') ch[j++]=s[i];
		else if(s[i]=='=') break; 
	}//j为ch的长度 
	k=0;
	for(i=0;i<j;i++)
	{
		if(ch[i]=='+'||ch[i]=='-')
		{
			node[k].num=i;
			if(ch[i]=='+') node[k].val=1;
			else  node[k].val=2;
			k++; 
		}
	}//k为加减号的个数 
	//int p,q,t,g;    q为ss中的位数   t为运算符的个数    g为数字的个数 
	for(i=0;i<=k;i++)
	{
		if(k==0) b[i]=cal(0,j);
		else
		{
			if(i==0) b[i]=cal(0,node[0].num);
			else if(i>0&&i<k) b[i]=cal(node[i-1].num+1,node[i].num);
			else b[i]=cal(node[k-1].num+1,j);
		}
	}
	int result=b[0];
	for(i=0;i<k;i++)
	{
		if(node[i].val==1) result+=b[i+1];
		else result-=b[i+1];
	}
	printf("%d",result);
	return 0;	
}

