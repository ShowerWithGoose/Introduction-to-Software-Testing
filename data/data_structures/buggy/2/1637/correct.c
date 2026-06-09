#include<stdio.h>

int main()
{
	int a[10000]={0},b[10000]={0};
	int k=1,j=0,i,r=0;
	char c;
	while((c=getchar())==' ')
	{
		continue;
	}
	a[0]=c-'0';
	while((c=getchar())!='=')
	{
		if(c==' ')
		{
			continue;
		}
		else
		{
			if(c>='0'&&c<='9')
			{
				if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/')
				{
					a[k-1]=a[k-1]*10+c-'0';
				}
				else
				{
					a[k]=c-'0';
					k++;
				}
			}
			else
			{
				a[k]=c;
				k++;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		if(a[i]=='*')
		{
			j--;
			b[j]=b[j]*a[i+1];
			i++;
		}
		else if(a[i]=='/')
		{
			j--;
			b[j]=b[j]/a[i+1];
			i++;
		}
		else
		{
			b[j]=a[i];
		}
		j++;
	}
	r=b[0];
	for(i=1;i<j;i++)
	{
		if(b[i]=='+')
		{
			r+=b[i+1];
		}
		else if(b[i]=='-')
		{
			r-=b[i+1];
		}
		else
		{
			continue;
		}
	}
	printf("%d\n",r);
	return 0;
}
