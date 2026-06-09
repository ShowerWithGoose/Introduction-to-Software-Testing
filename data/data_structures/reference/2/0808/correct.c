#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000]=" ",t[1000]=" ",f[1000]=" ",z[1000]=" ";
	int i,k,x1,x2=-1,zi,d[1000],di=0,fi=1,h=0,c[1000],ci=0,flag=0,j=0;
	int jg;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ')
		{
			t[j]=s[i];
			j++;
		}
	}
	for(i=0;t[i]!='\0';i++)
	{
		if((t[i]=='+'||t[i]=='-'||t[i]=='*'||t[i]=='/'||t[i]=='=')&&(t[i-1]>='0'&&t[i-1]<='9'))
		{
			x1=i; 
			memset(z,0,1000*sizeof(char));
			for(k=x2+1,zi=0;k<x1;k++)
			{
				z[zi]=t[k];
				zi++;
			}
			d[di]=atoi(z);
			di=di+1;
			x2=i;
		}
	}
	for(i=0;t[i]!='\0';i++)
	{
		if(t[i]=='+'||t[i]=='-'||t[i]=='*'||t[i]=='/'||t[i]=='=')
		{
			f[fi]=t[i];
			fi++;
		}
	 } 
	for(i=1;i<fi-1;i++)
	{
		if(f[i]=='*'||f[i]=='/')
		{
			if(f[i]=='*'&&f[i-1]!='*'&&f[i-1]!='/')
			{
				c[ci]=d[i-1]*d[i];
				if(f[i+1]!='*'&&f[i+1]!='/')
				{
					d[i-1]=c[ci];
					d[i]=c[ci];
					ci++;
					
				}
			}
			else if(f[i]=='*'&&(f[i-1]=='*'||f[i-1]=='/'))
			{
				flag++;
				c[ci]=c[ci]*d[i];
				if(f[i+1]!='*'&&f[i+1]!='/')
				{
					d[i-flag-1]=c[ci];
					d[i]=c[ci];
					ci++;
					flag=0;
				}
			}
			else if(f[i]=='/'&&f[i-1]!='*'&&f[i-1]!='/')
			{
				c[ci]=d[i-1]/d[i];
				if(f[i+1]!='*'&&f[i+1]!='/')
				{
					d[i-1]=c[ci];
					d[i]=c[ci];
					ci++;
				}
			}
			else if(f[i]=='/'&&(f[i-1]=='*'||f[i-1]=='/'))
			{
				flag++;
				c[ci]=c[ci]/d[i];
				if(f[i+1]!='*'&&f[i+1]!='/')
				{
					d[i-flag-1]=c[ci];
					d[i]=c[ci];
					ci++;
					flag=0;
				}
			}
		}
	}
	for(i=1;i<fi-1;i++)
	{
		if(f[i]=='+'||f[i]=='-')
		{
			if(f[i]=='+'&&f[i-1]!='+'&&f[i-1]!='-')
			{
				c[ci]=d[i-1]+d[i];
				if(f[i+1]!='+'&&f[i+1]!='-')
				{
					for(j=i+1;j<fi-1;j++)
					{
						if(f[j]=='+'||f[j]=='-')
						{
							d[j-1]=c[ci];
							break;
						}
					}
					ci++;
				}
			}
			else if(f[i]=='+'&&(f[i-1]=='+'||f[i-1]=='-'))
			{
				c[ci]=c[ci]+d[i];
				if(f[i+1]!='+'&&f[i+1]!='-')
				{
					for(j=i+1;j<fi-1;j++)
					{
						if(f[j]=='+'||f[j]=='-')
						{
							d[j-1]=c[ci];
							break;
						}
					}
					ci++;
				}
			}
			else if(f[i]=='-'&&f[i-1]!='+'&&f[i-1]!='-')
			{
				c[ci]=d[i-1]-d[i];
				if(f[i+1]!='+'&&f[i+1]!='-')
				{
					for(j=i+1;j<fi-1;j++)
					{
						if(f[j]=='+'||f[j]=='-')
						{
							d[j-1]=c[ci];
							break;
						}
					}
					ci++;
				}
			}
			else if(f[i]=='-'&&(f[i-1]=='+'||f[i-1]=='-'))
			{
				c[ci]=c[ci]-d[i];
				if(f[i+1]!='+'&&f[i+1]!='-')
				{
					for(j=i+1;j<fi-1;j++)
					{
						if(f[j]=='+'||f[j]=='-')
						{
							d[j-1]=c[ci];
							break;
						}
					}
					ci++;
				}
			}
		}
	}
	printf("%d\n ",c[ci-1]);
	return 0;
}
int atoi(char z[])
{
	int i,n;
	for(i=0,n=0;z[i]!='\0';i++)
	{
		n=n*10+z[i]-'0';
	}
	return n;
}

