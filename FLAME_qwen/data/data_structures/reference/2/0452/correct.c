#include <stdio.h>
#include <string.h>
int main()
{
	char str1[1001],str2[1001];
	gets(str1);
	int m,i,n=0,j=0,t;
	int a[1001]={0};
	m=strlen(str1);
	for(i=0;i<m;i++)
	{
		if(str1[i]>='0'&&str1[i]<='9')
		{
			a[j]=a[j]*10+str1[i]-'0';
		}
		else if(str1[i]=='+'||str1[i]=='-'||str1[i]=='*'||str1[i]=='/'||str1[i]=='=')
		{
			str2[j]=str1[i];
			j++;
		}
	}
	t=strlen(str2);
	for(i=0;i<t;i++)
	{
		if(str2[i]=='*')
		{
			a[i+1]=a[i]*a[i+1];
			a[i]=0;
		}
		if(str2[i]=='/')
				{
					a[i+1]=a[i]/a[i+1];
					a[i]=0;
				}
		if(str2[i]=='-')
				{
					a[i+1]=-1*a[i+1];
				}		
	}
	for(i=0;i<t;i++)
	{
		n+=a[i];
	}
	printf("%d\n",n);
	return 0;
}



