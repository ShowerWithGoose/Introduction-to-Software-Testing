#include<stdio.h>
#include<string.h>
void f(char *);
int flag[1000];

int main()
{
	char a[10000];
	char c[1000];
	int b[1000];
	gets(a);
	f(a);
	int len=(int)strlen(a);
	int i,j;
	int t=0,m=0;
	for(i=0;i<len-1;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			b[t]=b[t]*10+a[i]-'0';
		else 
		{
			t++;
			if(a[i]=='*' || a[i]=='/') flag[m]++;
			c[m++]=a[i];	
		}
		
	} t++;
	if(t==1)
	{
		printf("%d",b[0]);
		return 0;
	}
	for(i=0;i<m;i++)
	{
		if(c[i]=='*'||c[i]=='/')
		{
			
			if(c[i]=='*')
			{
				b[i]=b[i]*b[i+1];
			} 
			if(c[i]=='/')
			{
				b[i]=b[i]/b[i+1];
			}
			for(j=i+1;j<t;j++)
			{
				b[j]=b[j+1];
			}
			t--;
			for(j=i;j<m;j++)
			{
				c[j]=c[j+1];
			}
			m--;
			i--;
		}
	}
	for(i=0;i<m;i++)
	{
		if(c[i]=='+'||c[i]=='-')
		{
			if(c[i]=='+')
			{
				b[i]=b[i]+b[i+1];
			} 
			else 
				b[i]=b[i]-b[i+1];
			for(j=i+1;j<t;j++)
			{
				b[j]=b[j+1];
			}
			t--;
			for(j=i;j<m;j++)
			{
				c[j]=c[j+1];
			}
			m--;
			i--;	
		}	
	}
	printf("%d",b[0]);
	
	
	
	
	
	
}
void f(char*p)
{
	int i,j;
	for(i=j=0;p[i]!='\0';i++)
	{
		
		if(p[i]!=' ') p[j++]=p[i];
		
	}p[j]=0;
	
}






