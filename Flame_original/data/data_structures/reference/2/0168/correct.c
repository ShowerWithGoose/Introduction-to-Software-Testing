#include <stdio.h>
#include <string.h>
int main()
{
	char s[1005],sym[1005];
	int num[1005],n=0;
	int i=0,j=0,k=0;
	gets(s); 
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n=n+s[i]-'0';
			if(s[i+1]>='0'&&s[i+1]<='9')
			{
				n*=10;
			} 
			else
			{
				num[j++]=n;
				n=0;
			}	 
		}
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
		sym[k++]=s[i];
	}
	num[j]='\0';sym[k]='\0';
	for(i=0;i<strlen(sym);i++)
	{
		if(sym[i]=='*')
		{
		    num[i+1]=num[i]*num[i+1];
		    num[i]=0;
		    if(i!=0)
		    sym[i]=sym[i-1];
		    if(i==0)
		    sym[i]='+';
		}
		else if(sym[i]=='/')
		{
		    num[i+1]=num[i]/num[i+1];
		    num[i]=0;
		    if(i!=0)
		    sym[i]=sym[i-1];
		    if(i==0)
		    sym[i]='+';
		}
	}
    for(i=0;i<strlen(sym);i++)
    {
    	if(sym[i]=='+')
		{
		    num[i+1]=num[i]+num[i+1];
		    num[i]=0;
		}
		if(sym[i]=='-')
		{
		    num[i+1]=num[i]-num[i+1];
		    num[i]=0;
		}
		if(sym[i]=='=')
		{
			printf("%d",num[i]);
		}
	}
	return 0;
}

