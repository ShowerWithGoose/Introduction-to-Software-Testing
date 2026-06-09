#include<stdio.h>
#include<string.h>

int pow(int n)
{
	int i,p=1;
	for(i=1;i<=n;i++)
	{
		p*=10;
	}
	return p;
}

int main()
{
	char s[105];
	int i,j,l,k,e,sum=0,m=0;
	int a[105];
    int b[105]={'0'};
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]==' ')
		{
			for(j=i;j<l-1;j++)
			{
				s[j]=s[j+1];
			}
			l--;
			i--;
		}
	}
	s[l]='\0';
	for(i=0;i<l;i++)
	{
		if(s[i]<'0'||s[i]>'9')
		{
			m++;
			a[m]=i;
		}
		
	}
	for(i=0;i<a[1];i++)
	{
		k=a[1]-1-i;
		b[1]+=(s[i]-'0')*pow(k);
	}
	for(j=2;j<=m;j++)
	{
		
		for(i=a[j-1]+1;i<=a[j]-1;i++)
  	    {
  	       	k=a[j]-1-i;
 	       	b[j]+=(s[i]-'0')*pow(k);
		}
	}
	
	for(i=1;i<m;i++)
	{
		k=a[i];
		if(s[k]=='*')
		{
			b[i]*=b[i+1];
			a[i]=a[i+1];
			e=i+1;
			for(;e<m;e++)
			{
				b[e]=b[e+1];
				a[e]=a[e+1];
			}
			i--;
			m--;
		}
		else if(s[k]=='/')
		{
			b[i]/=b[i+1];
			a[i]=a[i+1];
			e=i+1;
			for(;e<m;e++)
			{
				b[e]=b[e+1];
				a[e]=a[e+1];
			}
			i--;
			m--;
		}
	}
	sum=b[1];
	for(i=1;i<m;i++)
	{
		k=a[i];
		if(s[k]=='+')
		{
			sum+=b[i+1];
		}
		else if(s[k]=='-')
		{
			sum-=b[i+1];
		}
	}
	printf("%d",sum);
	
	
	
	return 0;
}


