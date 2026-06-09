#include<stdio.h>
#include<string.h>
int main()
{
	char s[105],a[105];
	int k,m=-1,p=0,q=1,r=0,x,y=-1,i,n,b=0;
	gets(a);
	k=strlen(a);
	for(i=0;i<k;i++)
	{
		if(a[i]!=' ')
		{
			s[b]=a[i];
			b=b+1;
		}
		else
		continue;
	}
	s[b]='\0';
	k=strlen(s);
	for(i=0;i<k;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='=')
		{
			for(n=m+1;n<=i;n++)
			{
				if(s[n]=='*'||s[n]=='/'||n==i)
				{
					for(x=y+1;x<n;x++)
				    p=p*10+s[x]-48;
				    if(y==-1||s[y]=='+'||s[y]=='-'||s[y]=='*')
				    q=q*p;
				    if(s[y]=='/')
				    q=q/p;
				    y=n;
				    p=0;
				}
			}
			y=i;
			if(m==-1||s[m]=='+')
			r=r+q;
			if(s[m]=='-')
			r=r-q;
			m=i;
			q=1;
		}
	}
	printf("%d",r);
	return 0;
}

