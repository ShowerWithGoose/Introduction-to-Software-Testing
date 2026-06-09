#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	char x[200],y[200],q[200];
	int w[200],num[200],type[200];
	gets(x);
	int i,j=0,k=0,t,l,o=0,n=1,m,p,sum;
	for(i=0;i<strlen(x);i++)
	{
		if(x[i]!=' ')
		{
		y[j]=x[i];
		j++;
		}
		
	}
	for(i=0;i<strlen(y);i++)
	{
		if(y[i]=='+'||y[i]=='-'||y[i]=='*'||y[i]=='/'||y[i]=='=')
			{q[k]=y[i];
			k++;
			}
		if(y[i]>='0'&&y[i]<='9')
			for(t=1,sum=0,n=1;t<15;t++)
			{
				if(y[i+t]>='0'&&y[i+t]<='9')
					continue;
				for(l=t;l>=1;l--)
				{
					sum+=(y[i+l-1]-'0')*n;
					n*=10;
				}

				w[o]=sum;
				sum=0;
				o++;
				i+=t-1;
				break;

			}
		
		
	}
	for(i=0,p=0;i<strlen(q)+1;i++)
	{
		if(q[i]=='+'||q[i]=='-'||q[i]=='=')
			{num[p]=w[i];
			type[p]=q[i];
			p++;
			}
		if(q[i]=='*')
			w[i+1]*=w[i];
		if(q[i]=='/')
			w[i+1]=w[i]/w[i+1];
	}
	int result=num[0];
	/*for(i=0;i<p;i++)
	printf("%c %d ",type[i],num[i]); 
	printf("%d %d",strlen(type),p);*/
	for(i=0;i<p;i++)
	{
		if(type[i]=='+')
		result+=num[i+1];
		if(type[i]=='-')
		result-=num[i+1];
	 } 
	printf("%d",result);
	

 } 

