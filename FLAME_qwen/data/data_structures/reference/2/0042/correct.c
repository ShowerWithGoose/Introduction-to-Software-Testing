#include<string.h>
#include<stdio.h>
int main()
{
	int i=0,j,k,result;
	int a[1001];
	char b[1001];
	while(1)
	{
		scanf("%d %c",&a[i],&b[i]);
		i++;
		if(b[i-1]=='=')
		{
			break;
		}
	}
	for(j=0;j<i;j++)
	{
		if(b[j]=='*'||b[j]=='/')
		{
			if(b[j]=='*')
			{
				result=a[j]*a[j+1];
				a[j+1]=result;
				a[j]=1000000;
				b[j]=' ';
			}
			else
			{
				result=a[j]/a[j+1];
				a[j+1]=result;
				a[j]=1000000;
				b[j]=' ';
			}
			
		}
	}
	for(j=0;j<i;j++)
	{
		if(b[j]=='+'||b[j]=='-')
		{
			if(b[j]=='+')
			{
				for(k=j+1;k<i;k++)
			{
				if(a[k]!=1000000)
				{
					break;
				}
				
			}
			a[k]=a[j]+a[k];
			a[j]=1000000;
			b[j]=' ';
			}
			if(b[j]=='-')
		{
			for(k=j+1;k<i;k++)
			{
				if(a[k]!=1000000)
				{
					break;
				}
				
			}
			a[k]=a[j]-a[k];
			a[j]=1000000;
			b[j]=' ';
		}
		}
		
	}
	printf("%d",a[i-1]);
	return 0;
}



