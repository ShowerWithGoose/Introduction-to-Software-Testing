#include<stdio.h>
#include<string.h>
int top=-1;
long long x[1010];
void f(char c)
{
	if(c=='*')
	{
		x[top-1]=x[top]*x[top-1];
		x[top]=0;
		top--;
	}
	else if(c=='+')
	{
		x[top-1]=x[top]+x[top-1];
		x[top]=0;
		top--;
	}
	else if(c=='-')
	{
		x[top-1]=x[top-1]-x[top];
		x[top]=0;
		top--;
	}
	else
	{
		x[top-1]=x[top-1]/x[top];
		x[top]=0;
		top--;
	}
}
int main()
{
	char a[1010],b[1010],p,q;
	gets(a);
	int lena,i,j=0,lenb,n=0,count=0;
	lena=strlen(a);
	for(i=0;i<lena;i++){
		if(a[i]==' ')
			continue;
		else
		{
			b[j]=a[i];
			j++;
		}
	}
	lenb=j;
	for(i=0;i<lenb;i++){
		if(b[i]>='0'&&b[i]<='9')
		{
			n=10*n+b[i]-'0';
		}
		else
		{
			x[++top]=n;
			n=0;
			if(b[i]=='=')
			{
				if(count==0)
					printf("%d",x[0]);
				else if(count==1)
				{
					f(p);
					printf("%d",x[0]);
				}
				else
				{
					f(q);
					f(p);
					printf("%d",x[0]);
				}
			}
			else
			{
				if(count==0)
				{
					p=b[i];
					count++;
				}
				else if(count==1)
				{
					if((p=='+'||p=='-')&&(b[i]=='*'||b[i]=='/'))
					{
						count++;
						q=b[i];
					}
					else
					{
						f(p);
						p=b[i];
					}
				}
				else
				{
					if(b[i]=='*'||b[i]=='/')
					{
						f(q);
						q=b[i];
					}
					else
					{
						f(q);
						f(p);
						p=b[i];
						count--;
					}
				}
			}
		}
	}
	return 0;
}

