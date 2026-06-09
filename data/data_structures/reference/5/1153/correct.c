#include<stdio.h>
int f,i,j=1,k=1;
char s[1005];
typedef struct node
{
	int a;
	int x;
	int contact;
}node;
node m[105],n[105],res[1005];
int main()
{
	gets(s);
	while(s[i]!='\0')
	{
		if(s[i]!=' '&&f==0)
			m[j].a=m[j].a*10+s[i]-'0';
		else if(s[i]!=' '&&f==1)
			m[j].x=m[j].x*10+s[i]-'0';
		else if(s[i]==' '&&f==0)
			f++;
		else if(s[i]==' '&&f==1)
		{
			f=0;
			j++;
		}
		i++;
	}
	
	gets(s);
	j=1;i=0;f=0;
	while(s[i]!='\0')
	{
		if(s[i]!=' '&&f==0)
			n[j].a=n[j].a*10+s[i]-'0';
		else if(s[i]!=' '&&f==1)
			n[j].x=n[j].x*10+s[i]-'0';
		else if(s[i]==' '&&f==0)
			f++;
		else if(s[i]==' '&&f==1)
		{
			f=0;
			j++;
		}
		i++;
	}
	for(i=1;m[i].a!=0;i++)
	{
		for(j=1;n[j].a!=0;j++)
		{
			res[k].a=m[i].a*n[j].a;
			res[k].x=m[i].x+n[j].x;
			k++;
		}
	}
	for(i=1;res[i].a!=0;i++)
	{
		for(j=1;res[j].a!=0;j++)
		{
			if(res[j].x>res[j-1].x||res[j].x==res[j-1].x&&res[j].a>res[j-1].a)
			{	
				node tep=res[j-1];
				res[j-1]=res[j];
				res[j]=tep;
			}
		}
	}
	for(i=1;res[i].a!=0;i++)
	{
		for(j=i+1;res[j].a!=0;j++)
		{
			if(res[i].contact==1)
				continue;
			else if(res[i].x==res[j].x)
			{
				res[i].a=res[i].a+res[j].a;
				res[j].contact=1;
			}
		}
	}
	for(i=0;res[i].a!=0||res[i].x!=0;i++)
	{
		if(res[i].a!=0&&!res[i].contact)
			printf("%d %d ",res[i].a,res[i].x);
	}
}
	

