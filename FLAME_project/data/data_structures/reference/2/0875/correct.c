#include <stdio.h>
#include<string.h>
char s[10005];//原式 
char a[10005];//后缀 
char ch[10005];//符号栈 
void change();
void del();
int cal();
int i=0,j=0,m=0,flag=0;
int main()
{
	gets(s);
	del();
	change();
	printf("%d",cal());
	return 0;	
}
void change()
{
	for(i=0,j=0,m=0;i<=strlen(s)-1;i++)
	{
		flag=0;
		if(s[i]>='0'&&s[i]<='9')a[j++]=s[i];
		else
		{	
			a[j++]=' ';
			if(m==0)ch[m]=s[i];
			else
			{
				ch[m]=s[i];	
				while(((ch[m]=='+'||ch[m]=='-')&&(ch[m-1]=='+'||ch[m-1]=='-'||ch[m-1]=='*'||ch[m-1]=='/'))||((ch[m]=='*'||ch[m]=='/')&&(ch[m-1]=='*'||ch[m-1]=='/')))
				{
					flag=1;
					a[j++]=ch[m-1];
					ch[m-1]=ch[m];
					m--;
					if(m<0)break;
				}
			}
			m++;
			if(flag=0)m--;
		}
		
	}
	m--;
	while(m>=0)a[j++]=ch[m--];
	a[j]='\0';
	return;
}
void del()
{
	for(i=0,j=0;i<=strlen(s)-1;i++)
	{
		if(s[i]=='=')break;
		if(s[i]!=' ')s[j++]=s[i];//去空格和等号 
		
	}
	s[j]='\0';
	return;
}
int cal()
{
	int x=0,y=0;
	int num[10005];
	for(i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			while(a[i]>='0'&&a[i]<='9')
			{
				num[x]=num[x]*10+a[i]-'0';
				i++;
			}
			i--;
			x++;
		}
		else if(a[i]==' ');
		else if(a[i]=='+')
		{
			num[x-2]+=num[x-1];
			num[--x]=0;
		}
		else if(a[i]=='-')
		{
			num[x-2]-=num[x-1];
			num[--x]=0;
		}
		else if(a[i]=='*')
		{
			num[x-2]*=num[x-1];
			num[--x]=0;
		}
		else if(a[i]=='/')
		{
			num[x-2]/=num[x-1];
			num[--x]=0;
		}
	}
	return num[0];
}



