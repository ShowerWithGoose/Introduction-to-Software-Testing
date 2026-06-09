#include<stdio.h>
#include<string.h>
int up,down;
int *p1=&up,*p2=&down;

int before(char ch[],int n)
{
	int i,j,s=0,a=1;
	for(j=n-1;ch[j]==' ';j--);
	for(;ch[j]<='9'&&ch[j]>='0'&&j>=0;j--)
	{
		i=(ch[j]-'0')*a;
		a=a*10;
		s=s+i;
	}
	*p1=s;
	return j+1;
}

int after(char ch[],int n)
{
	int i,j,s=0,a=10;
	for(j=n+1;ch[j]==' ';j++);
	for(;ch[j]<='9'&&ch[j]>='0';j++)
	{
		i=ch[j]-'0';
		s=s*a+i;

	}
	*p2=s;
	return j-1;
}

int main()
{
	char ch[1005];
	gets(ch);
	int i,j,k,l,a,b,ans;
	for(j=0;ch[j]!='=';j++)
	{
		for(i=j;ch[i]!='*'&&ch[i]!='/'&&ch[i]!='=';i++);
		if(ch[i]=='=')
		{
			break;
		}
		else if(ch[i]=='*')
		{
			a=before(ch,i),b=after(ch,i);
			ans=up*down;
		}
		else if(ch[i]=='/')
		{
			a=before(ch,i),b=after(ch,i);
			ans=up/down;
		}
		for(k=a;k<=b;k++)
		{
			ch[k]=' ';
		}
		k--;
		for(;ans>0;k--)
		{
			ch[k]=(ans%10)+'0';
			ans=ans/10;
		}
		j=b;
	}
	
	
	
	int flag;
	for(i=0;i<l;i++)
	{
		for(;ch[i]==' ';i++);
		if((ch[i]>='0'&&ch[i]<='9')||ch[i]=='+')
		{
			flag=1;
			break;
		}
		if(ch[i]=='-')
		{
			flag==-1;
			break;
		}
	}
	
	i=after(ch,-1);//Î»ÖÃ 
	
	a=flag*down;
	
	for(;i<strlen(ch);)
	{
		for(;ch[i]!='+'&&ch[i]!='-'&&ch[i]!='=';i++);
		if(ch[i]=='+')
		{
			i=after(ch,i);
			a=a+down;
		}
		if(ch[i]=='-')
		{
			i=after(ch,i);
			a=a-down;
		}
		if(ch[i]=='=')
		{
			printf("%d",a);
			break;
		}
	}
	return 0;
}

