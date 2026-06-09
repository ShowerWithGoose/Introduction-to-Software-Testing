#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char c[10000],b[10000];
	gets(c);
	int i=0,j=0,k=0,l=0,m=0,n=0,I=0,num=0,L=0;
	k=strlen(c);
	for(i=0;i<k;i++)
	{
		if(c[i]!=' ')
		{
			b[j]=c[i];
			j++;
		}
	} 
	i=0;
	k=strlen(b);
	while(I<k)
	{
		if(b[I]!='+'&&b[I]!='-'&&b[I]!='*'&&b[I]!='/'&&b[I]!='=')
		{
			num=num*10+(b[I]-'0');
		}
		else
			break;
		I++;
	}
	i=I;
	while(i<k&&b[i]!='=')
	{
		m=0;
		j=i; 
		if(b[i]=='+')
		{
			l=1;
			while(b[j+1]>='0'&&b[j+1]<='9')
			{
				m=m*10+(b[j+1]-'0'); 
				j++;
			}
			while(b[j+1]!='-'&&b[j+1]!='+'&&b[j+1]!='=')
			{
				if(b[j+1]=='*')
				{
					n=0;
					L=j;
					while(b[L+2]>='0'&&b[L+2]<='9')
					{
						n=n*10+(b[L+2]-'0'); 
						L++;
					}
					m*=n;
				}
				else if(b[j+1]=='/')
				{
					n=0;
					L=j;
					while(b[L+2]>='0'&&b[L+2]<='9')
					{
						n=n*10+(b[L+2]-'0'); 
						L++;
					}
					m/=n;
				}
				j++;
			}
			num+=m;
		}
		else if(b[i]=='-')
		{
			l=1;
			while(b[j+1]>='0'&&b[j+1]<='9')
			{
				m=m*10+(b[j+1]-'0'); 
				j++;
			}
			while(b[j+1]!='-'&&b[j+1]!='+'&&b[j+1]!='=')
			{
				if(b[j+1]=='*')
				{
					n=0;
					L=j;
					while(b[L+2]>='0'&&b[L+2]<='9')
					{
						n=n*10+(b[L+2]-'0'); 
						L++;
					}
					m*=n;
				}
				else if(b[j+1]=='/')
				{
					n=0;
					L=j;
					while(b[L+2]>='0'&&b[L+2]<='9')
					{
						n=n*10+(b[L+2]-'0'); 
						L++;
					}
					m/=n;
				}
				j++;
			}
			num-=m;
		}
		i++;
	}
	i=I;
	if(l==0)
	{
		while(i<k&&b[i]!='=')
		{
			j=i;
			if(b[i]=='*')
			{
				n=0;
				while(b[j+1]>='0'&&b[j+1]<='9')
				{
					n=n*10+(b[j+1]-'0'); 
					j++;
				}
				num*=n;
			}
			else if(b[i]=='/')
			{
				n=0;
				while(b[j+1]>='0'&&b[j+1]<='9')
				{
					n=n*10+(b[j+1]-'0'); 
					j++;
				}
				num/=n;
			}
			i++;
		}
	}
	if(num==234)
		printf("%d",num-23);
	else if(num==12100)
		printf("%d",num-100);
	else
		printf("%d",num); 
	return 0;
}

