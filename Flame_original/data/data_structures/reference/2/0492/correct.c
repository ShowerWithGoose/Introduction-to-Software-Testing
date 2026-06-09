#include<string.h>
#include<stdio.h>
int main()
{
	int a[100000],c[100000],i,j,t,fu,shu,result,jia,n=0;
	char shi1[100000],shi2[100000],sign[100000],fu2[100000];
	gets(shi1);
	for(i=0,j=0;i<strlen(shi1);i++)
	{
		if(shi1[i]!=' ')
		{
			shi2[j]=shi1[i];
			j++;
		}
	}      
	shi2[j]='\0';   
	int p=0,flag=0;            
	for(i=0;i<strlen(shi2);i++)
	{
		n=0;
		flag=0;
		for(j=i;shi2[j]>='0'&&shi2[j]<='9';j++)
	    {
		    n=10*n+shi2[j]-'0';
		    flag=1;
	    }
	    if(flag==1)
	    a[p++]=n;
	    i+=j-i;
	    if(shi2[i]=='=')  break;
	}
	
	for(i=0,j=0,t=0;i<strlen(shi2);i++)
	{
		if(shi2[i]=='+'||shi2[i]=='-'||shi2[i]=='*'||shi2[i]=='/'||shi2[i]=='=')
		{
			sign[j]=shi2[i];
			j++;
		}
		if(shi2[i]=='+'||shi2[i]=='-'||shi2[i]=='=')
		{
			fu2[t]=shi2[i];
			t++;
		}
		fu=j;
		jia=t;
	}
	if(sign[0]=='='){
		printf("%d",a[0]);
		return 0;
	}
		int kk=0;
	for(i=0;i<=j;i++)
	{
		if(sign[i]=='*'||sign[i]=='/')
		{
			if(sign[i]=='*')
			{
				result=a[i]*a[i+1];
			    a[i+1]=result;
			}
			else
			{
				result=a[i]/a[i+1];
				a[i+1]=result;
			}
		}
		else
		{
			c[kk]=a[i];
			kk++;
		}
	}
	for(i=0;i<=jia;i++)
	{
		result=0;
		if(fu2[i]=='+')
		{
			result=c[i]+c[i+1];
			c[i+1]=result;
		}
		if(fu2[i]=='-')
		{
			result=c[i]-c[i+1];
			c[i+1]=result;
		}
		if(fu2[i]=='=')
		{
			printf("%d",c[i]);
		}
	}
	return 0;
}

