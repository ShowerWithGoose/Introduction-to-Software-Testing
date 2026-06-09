#include<stdio.h>
#include<string.h>
char s[10000];
char a[10000];
int n[10000];
char m[10000];
int main()
{
	gets(s);
	int i,j=0,L=strlen(s);
	for(i=0;i<L;i++)
	{
		if(s[i]!=' ')
		{
			a[j]=s[i];
			j++;
		}
	}
	int p=0,q=0,t;
	for(i=0;i<j-1;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			n[p]=a[i]-'0';
			i++;
			while(a[i]>='0'&&a[i]<='9')
			{
				t=a[i]-'0';
				t=n[p]*10+t;
				n[p]=t;
				i++;
			}
			i--;
			p++;
		}
		else
		{
			m[q]=a[i];
			q++;
		}
	}
	for(i=0;i<q;i++)
	{
		if(m[i]=='-')
		n[i+1]=-n[i+1];
	}
	for(i=0;i<q;i++)
	{
		if(m[i]=='*')
		{
			n[i+1]=n[i+1]*n[i];
			n[i]=0;
		}
		else if(m[i]=='/')
		{
			n[i+1]=n[i]/n[i+1];
			n[i]=0;
		}
	}
	int s=0;
	for(i=0;i<p;i++)
	{
		s+=n[i];
	}
	printf("%d",s);
	return 0;
}



