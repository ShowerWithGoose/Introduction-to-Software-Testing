#include<stdio.h>
#include<string.h>
#define inf 1000
char s0[inf],s[inf],s1[inf];
void deletespace();
int gets_Fnum();
int gets_Bnum();
void putsnum(int a,char *q);
int main()
{
	int i,len,j,k,l,a,b,ans=0;
	char *p,c[1000],d;
	gets(s0);
	deletespace();
	len=strlen(s);
	for(i=0,j=0;i<len;i++)
	{
		if(s[i]!='*'&&s[i]!='/')
		{
			s1[j]=s[i];
			j++;
		}
		else{
			a=gets_Fnum(j);
			b=gets_Bnum(i);
			if(s[i]=='*')
			{
				putsnum(a*b,s1);
			}
			else{
				putsnum(a/b,s1);
			}
			j=strlen(s1);
			for(i=i+1;s[i]>='0'&&s[i]<='9';i++);
			i--;
		}
	}
	j=0;
	memset(c,0,sizeof(c));
	for(i=0;s1[i]>='0'&&s1[i]<='9';i++)
	{
		c[j]=s1[i];
		j++;
	}
	sscanf(c,"%d",&ans);
	while(s1[i]!='=')
	{
		memset(c,0,sizeof(c));
		d=s1[i];
		j=0;
		i++;
		for(;s1[i]>='0'&&s1[i]<='9';i++)
		{
			c[j]=s1[i];
			j++;
		}
		sscanf(c,"%d",&a);
		if(d=='+')
		{
			ans+=a;
		}
		else if(d=='-'){
			ans-=a;
		}
	}
	printf("%d",ans);
	return 0;
}
void putsnum(int a,char *q)
{
	char c[1000];
	sprintf(c,"%d",a);
	strcat(q,c);
}
int gets_Bnum(int i)
{
	int k,j=0,num;
	char c[1000];
	for(k=i+1;s[k]>='0'&&s[k]<='9';k++)
	{
		c[j]=s[k];
		j++;
	}
	sscanf(c,"%d",&num);
	return num;
}
int gets_Fnum(int j)//得到s1末尾的数
{
	int l=j-1,num,len,i;
	char *p;
	while(s1[l]>='0'&&s1[l]<='9')
	{
		l--;
	}
	l++;
	p=s1+l;
	sscanf(p,"%d",&num);
	len=strlen(s1);
	for(int i=l;i<len;i++)
	{
		s1[i]='\0';
	}
	return num;
}
void deletespace()
{
	int i,len,j;
	len=strlen(s0);
	for(i=0,j=0;i<len;i++)
	{
		if(s0[i]!=' ')
		{
			s[j]=s0[i];
			j++;
		}
	}
	return;
}
/*1+5/3+4*10-   7/3=*/

