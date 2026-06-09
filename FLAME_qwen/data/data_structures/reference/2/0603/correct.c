#include<stdio.h>
#include<string.h>
char a[1001],c[1001];
int b[1001];
double an=0.1;
int ss(int i)
{
	an*=10;
	if(a[i]=='+'||a[i]=='/'||a[i]=='*'||a[i]=='-')return 0;
	else if(i==0)return a[i]*an;
	return a[i]*an+ss(i-1);
}
int sk(int k)
{
	while(a[k]!='+'&&a[k]!='/'&&a[k]!='*'&&a[k]!='-'&&a[k]!='=')
	{
		k++;
	}
	return k;
}
int main()
{
	int i,j,n=1;
	gets(a);
	for(i=0;a[i]!='=';i++)
		{
			if(a[i]=='+'||a[i]=='/'||a[i]=='*'||a[i]=='-')
			{
				c[n]=a[i];n++;
			}
		}
		n--;
		if(n==0){for(i=0;a[i]!='=';i++){printf("%c",a[i]);}return 0;}
	for(i=0;a[i]!='=';i++)
	{
		if(a[i]>=48&&a[i]<=57)a[i]=a[i]-48;
		else if(a[i]==' '){
			for(j=i;a[j]!='=';j++)
			{
				a[j]=a[j+1];
			}
			i--;
		}
	}j=1;
	for(int i=1;i<=n+1;i++)
	{
		j=sk(j);
		an=0.1;b[i]=ss(j-1);j++;
	}
	for(i=1;i<=n;i++)
	{
		if(c[i]=='*'){
			b[i]=b[i]*b[i+1];
			for(j=i;j<=n;j++)
			{
				c[j]=c[j+1];
			}
			for(j=i+1;j<=n+1;j++)
			{
			b[j]=b[j+1];
			}
			n--;
			i--;
		}
			if(c[i]=='/'){
				b[i]/=b[i+1];
				for(j=i;j<=n;j++)
				{
					c[j]=c[j+1];
				}
				for(j=i+1;j<=n+1;j++)
				{
				b[j]=b[j+1];
				}
				n--;
				i--;
			}
		}
	for(i=1;i<=n;i++)
			{
				if(c[i]=='+'){
					b[1]+=b[i+1];
					for(j=i;j<=n;j++)
					{
						c[j]=c[j+1];
					}
					for(j=i;j<=n+1;j++)
					{
					b[j+1]=b[j+2];
					}
					n--;
					i--;
				}
			}
for(i=1;i<=n;i++)
			{
				if(c[i]=='-'){
					b[1]-=b[i+1];
					for(j=i;j<=n;j++)
					{
						c[j]=c[j+1];
					}
					for(j=i;j<=n+1;j++)
					{
					b[j+1]=b[j+2];
					}
					n--;
					i--;
				}
			}
	printf("%d\n",b[1]);
	return 0;
}

