#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char aa[1000000];
char a[1000000];
int q[100000];
int x[100000];

int main()
{
	gets(aa);
	int i,n=0,ans=0,fll=1,j=0,k;
	for(i=0;i<strlen(aa);i++)
	{
		if(aa[i]!=' ')
		{
			a[n]=aa[i];
			n++;
		}
	}
	i=0;
	while(a[i]!='=')
	{
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			j++;
			i++;
			continue;
		}
		q[j]=q[j]*10+(a[i]-'0');
		i++;	
	}
	i=0;
	j=0;
	k=0;
	x[0]=q[0];
	while(a[i]!='=')
	{
		if(a[i]=='*')
		{
			j++;
			x[k]=x[k]*q[j];
		}
		else if(a[i]=='/')
		{
			j++;
			x[k]=x[k]/q[j];
		}
		else if(a[i]=='+'||a[i]=='-')
		{
			j++;
			i++;
			k++;
			x[k]=q[j];
			continue;
		}
		i++;
	}
	ans=x[0];
	k=1;
	i=0;
	while(a[i]!='=')
	{
		if(a[i]=='+')
		{
			ans=ans+x[k];
			k++;
		}
		else if(a[i]=='-')
		{
			ans=ans-x[k];
			k++;
		}
		i++;
	}
	printf("%d",ans);
}



