#include <stdio.h>
#include <string.h>
int main()
{
	char s[10000];
	gets(s);
	int i,j,k,a[1000]={0};
	for(i=0,j=0;s[i]!='=';i++)
	if(s[i]!=' ')
	s[j++]=s[i];
	s[j]='=';
	s[j+1]='\0';
	for(i=0,j=0;s[i]!='=';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[j]=a[j]*10+s[i]-'0';
		else if(s[i]=='*'||s[i]=='/')
		{
			k=i;
			j++;
			for(i+=1;s[i]<='9'&&s[i]>='0';i++)
				a[j]=a[j]*10+s[i]-'0';
			i--;
			if(s[k]=='*')
			{
			a[j-1]*=a[j];
			a[j]=0;
			}
			else
			{
			a[j-1]/=a[j];
			a[j]=0;
			}
			j--;
		}
		else
		{
			k=i;
			j++;
			for(i+=1;s[i]<='9'&&s[i]>='0';i++)
				a[j]=a[j]*10+s[i]-'0';
			if(s[k]=='-')
				a[j]*=-1;
			i--;
		}
	}
	for(k=0,j=0;k<1000;k++)
	j+=a[k];
	printf("%d",j);
	return 0;
}



