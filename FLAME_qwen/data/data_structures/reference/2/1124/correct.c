#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,a[105],n,sum=0,x;
	char s[105],c[105],d[105]={"\0"};
	gets(s);
	for(i=0,j=0,k=0;i<strlen(s);i++)
	{
		if(s[i]!=' ')
		c[j++]=s[i];
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		d[k++]=s[i];
	}
	i=0,k=0;
	while(i<strlen(c)-1)
	{
		n=0,j=i;
		while(c[j]>='0'&&c[j]<='9'&&j<strlen(c)-1)
		{
			n*=10;
			n+=c[j]-'0';
			j++;
		}
		a[k++]=n;
		i+=j-i+1;
	}
	sum=a[0],i=0;
	while(i<strlen(d))
	{
		j=i;
		if(d[j]=='*')
		{
			sum*=a[j+1];
			i++;
		}
		else if(d[j]=='/')
		{
			sum/=a[j+1];
			i++;
		}
		else if(d[j]=='+')
		{
			j++;
			x=a[j];
			while(d[j]=='*'||d[j]=='/'&&j<strlen(d))
			{
				if(d[j]=='*')
				x*=a[j+1];
				if(d[j]=='/')
				x/=a[j+1];
				j++;
			}
			sum+=x;
			i+=j-i;
		}
		else if(d[j]=='-')
		{
			j++;
			x=a[j];
			while(d[j]=='*'||d[j]=='/'&&j<strlen(d))
			{
				if(d[j]=='*')
				x*=a[j+1];
				if(d[j]=='/')
				x/=a[j+1];
				j++;
			}
			sum-=x;
			i+=j-i;
		}
	}
	printf("%d",sum);
	return 0;
} 

