#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s[100];
int i=0;

void read()
{
	char c;
	while(c!='\n')
	{
	 c=getchar();
	 while(c==' ')
	 c=getchar();
	 s[i]=c;
	 i++;
    }
}

int main()
{
	read();
	int k,len,a=0,b=0,c=0,d=0,j=1,t=0,r=0,p=1;
	len=strlen(s);
	for(k=0;k<len;k++)
	{
		if(s[k]=='+')
		a++;
		else if(s[k]=='-')
		b++;
		else if(s[k]=='*')
		c++;
		else if(s[k]=='/')
		d++;
	}
	char ch[100];
	int n[100]={0},e,m[100]={0},num[100]={0};
	for(k=0;k<len;k++)
	{
		if(s[k]>'9'||s[k]<'0')
		{
			n[j]=k;
			j++;
		}
	}
	j-=1;
	if(a==0&&b==0&&c==0&&d==0)
	{
		for(i=0;i<len-2;i++)
		printf("%c",s[i]);
		return 0;
	}
	for(r=0;r<n[1];r++)
	{
		m[p]=m[p-1]*10+s[r]-'0';
		p++;
	}
	num[1]=m[p-1];
	for(i=0;i<=p;i++)
		m[i]=0;
	p=1;
	for(t=2;t<j;t++)
		{
			for(r=n[t-1]+1;r<n[t];r++)
			{
				m[p]=m[p-1]*10+s[r]-'0';
				p++;
			}
			num[t]=m[p-1];
			for(i=0;i<=p;i++)
			m[i]=0;
			p=1;
		}
	for(e=1;e<j;e++)
	{
		k=n[e];
		if(s[k]=='*')
		{
			num[e]*=num[e+1];
			n[e]=n[e+1];
			for(i=e+1;i<j;i++)
			{
				num[i]=num[i+1];
				n[i]=n[i+1];
			}
			e--;
			j--;
		}
		else if(s[k]=='/')
		{
				num[e]/=num[e+1];
						n[e]=n[e+1];
						for(i=e+1;i<j;i++)
						{
							num[i]=num[i+1];
							n[i]=n[i+1];
						}
						e--;
						j--;
		}
	}
	for(i=1;i<j;i++)
	{
		k=n[i];
		if(s[k]=='+')
		{
			num[1]+=num[i+1];
			
		}
		else if(s[k]=='-')
		num[1]-=num[i+1]; 
	}
	printf("%d",num[1]);
	return 0;
}

