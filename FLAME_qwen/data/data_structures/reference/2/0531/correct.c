#include<stdio.h>
#include<string.h>
char identify(char x)
{
	if(x>='0'&&x<='9')
	return 1;
	else
	return 9;
}
int main()
{
	char a;
	int k=1,ans=0;
	int  num[40000]={0};
	char fuhao[40000]={0};
	while(scanf("%c",&a)!='\0')
	{   if (a=='=')
	  break;
		else if(a==' ')
		continue;
		else if(identify(a)==1)
		num[k]=num[k]*10+a-'0';
		else if(identify(a)!=1)
		{
		fuhao[k]=a;
		k++;
	    }
	}
	int i;
	for(i=1;i<=k-1;i++)
	{
		if(fuhao[i]=='-')
		num[i+1]=-num[i+1];
		if(fuhao[i]=='*')
		{
		num[i+1]=num[i]*num[i+1];
		num[i]=0;
	    }
	    if(fuhao[i]=='/')
		{
		num[i+1]=num[i]/num[i+1];
		num[i]=0;
	    }
	}
	for(i=1;i<=k;i++)
	ans+=num[i];

	printf("%d",ans);
	
	return 0;
}

