#include<stdio.h>
#include<string.h>
char a[100],b[100];
int main()
{
	int i,j=0,t;
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!='-')
		{
			b[j]=a[i];
			j++;
		}
		else if(a[i]=='-'&&i>=1)
		{
			if(a[i-1]>='0'&&a[i-1]<='9')
			{
				if(a[i+1]-a[i-1]>=2&&a[i+1]-a[i-1]<=9&&a[i+1]<='9')
				{
					for(j=j;b[j-1]<=a[i+1]-2;j++)
					{
						b[j]=b[j-1]+1;
					}
				}
				else 
			{
				b[j]='-';
				j++;
			}
			}
			else if(a[i-1]>='a'&&a[i-1]<='z')
			{
				if(a[i+1]-a[i-1]>=2&&a[i+1]-a[i-1]<=25)
				{
					for(j=j;b[j-1]<=a[i+1]-2;j++)
					{
						b[j]=b[j-1]+1;
					}
				}
				else 
			{
				b[j]='-';
				j++;
			}
			}
			else if(a[i-1]>='A'&&a[i-1]<='Z')
			{
				if(a[i+1]-a[i-1]>=2&&a[i+1]-a[i-1]<=25&&a[i+1]<='Z')
				{
					for(j=j;b[j-1]<=a[i+1]-2;j++)
					{
						b[j]=b[j-1]+1;
					}
				}
				else 
			{
				b[j]='-';
				j++;
			}
			}
			else 
			{
				b[j]='-';
				j++;
			}
		}
	}
	printf("%s",b);
}

