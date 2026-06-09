#include<stdio.h>
#include<string.h>
int a[10005],b[10005];
char s[10005],ss[10005];
int main()
{
	gets(s);
	int i,j=0,k=0,len,m,n,x,c,v1,v2,sum,z;
	len=strlen(s);
	
	for(i=0;i<len;i++)
	{
		if(s[i]==' ')	continue;
		else
		{
			ss[j]=s[i];
			j++;
		}
	}
	
	len=j;
	for(i=0;i<len;i++)
	{
		if(ss[i]>='0'&&ss[i]<='9')
		{
			a[k]=a[k]*10+ss[i]-'0';
		}
		else if(ss[i]=='+'||ss[i]=='-'||ss[i]=='*'||ss[i]=='/')
		{
			k++;
			if(ss[i]=='+')	a[k]=111451;
			else if(ss[i]=='-')	a[k]=111452;
			else if(ss[i]=='*')	a[k]=111453;
			else if(ss[i]=='/')	a[k]=111454;
			k++;
		}
	}
	
	for(i=0;i<k+1;i++)
	{
		if(a[i]==111453)
		{
			v1=1,v2=1;
			for(c=1;;c++)	
			{
				if(a[i-c]!=999999)
				{
					v1=a[i-c];
					a[i-c]=999999;
					break;
				}
			}
			for(c=1;;c++)	
			{
				if(a[i+c]!=999999)
				{
					v2=a[i+c];
					a[i+c]=999999;
					break;
				}
			}
			a[i]=v1*v2;
		}
		else if(a[i]==111454)
		{
			v1=1,v2=1;
			for(c=1;;c++)	
			{
				if(a[i-c]!=999999)
				{
					v1=a[i-c];
					a[i-c]=999999;
					break;
				}
			}
			for(c=1;;c++)	
			{
				if(a[i+c]!=999999)
				{
					v2=a[i+c];
					a[i+c]=999999;
					break;
				}
			}
			a[i]=v1/v2;
		}
	}
	
	sum=0;
	for(i=0;i<k+1;i++)
	{
		if(a[i]!=999999)
		{
			sum=a[i];
			z=i;
			break;
		} 
	}
	for(i=z+1;i<k+1;i++)
	{
		if(a[i]==111451)
		{
			v1=1;
			for(c=1;;c++)	
			{
				if(a[i+c]!=999999)
				{
					v1=a[i+c];
					a[i+c]=999999;
					break;
				}
			}
			sum=sum+v1;
		}
		if(a[i]==111452)
		{
			v1=1;
			for(c=1;;c++)	
			{
				if(a[i+c]!=999999)
				{
					v1=a[i+c];
					a[i+c]=999999;
					break;
				}
			}
			sum=sum-v1;
		}
	}
	printf("%d",sum);
	return 0;
}

