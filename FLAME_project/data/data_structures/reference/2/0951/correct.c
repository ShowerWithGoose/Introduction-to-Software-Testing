//1-2 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
char *p;
int getnum()
{
	char t[10000]={0},pp[10000]={0},temp[10000]={0},*q,c;
	int l,ll,ans,i,j,k,num;
	sscanf(p,"%[+--]%[^+--]",&c,t);
	l=strlen(t);
	if(strchr(t,'*')<=0&&strchr(t,'/')<=0)
	{
		ans=0;
		for(i=l-1,j=1;i>=0;i--,j*=10)
			ans+=(t[i]-'0')*j;
		p+=l+1;
		return ans;
	}
	else
	{
		pp[0]='*';
		strcat(pp,t);
		q=pp;
		ans=1;
 		while((*q)!='\0')
		{
			num=0;
			sscanf(q,"%[*-/]%[0-9]",&c,temp);
			ll=strlen(temp);
			for(i=ll-1,j=1;i>=0;i--,j*=10)
				num+=(temp[i]-'0')*j;
			if(c=='*')
				ans*=num;
			else if(c=='/')
				ans/=num;
			q+=ll+1;
		}
		p+=l+1;
		return ans;
	}
}
int main()
{
	int i,j,ans=0,temp;
	char str[10000],t[10000]={0};
	gets(str);
	t[0]='+';
	for(i=0,j=1;str[i]!='=';i++)
	{
		if(str[i]==' ')
			continue;
		t[j++]=str[i];
	}
	p=t;
	while((*p)!='\0')
	{
		if((*p)=='+')
			ans+=getnum();
		else if((*p)=='-')
			ans-=getnum();
	}
	printf("%d",ans);
	return 0;
}


