#include<stdio.h>
#include<string.h> 

int main()
{
	char s[2000];
	char p='+';
	gets(s);
	int i=0,j=0,k=0,sum=0,c=0;
	int a[200]={0};
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			sum = (int)(s[i]-'0') + sum*10;
		else if(s[i]!=' ')
		{
			if(p=='+')
			{
				a[j]=sum;
				j++;
			}
			else if(p=='-')
			{
				a[j]=-sum;
				j++;
			} 
			else if(p=='*')
				a[j-1]*=sum;
			else if(p=='/')
				a[j-1]/=sum;
			else if(p=='=')
			{
				a[j]=sum;
				break;
			}
			sum=0;
			p=s[i];
		}
	}
	for(k=0;k<=j;k++)
		c+=a[k];
	printf("%d\n",c);
	return 0;
}

