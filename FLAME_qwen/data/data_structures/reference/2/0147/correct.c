#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
char str[100],num[100],sig[100];
int num2[100],flag[100];
int exchange(char s[])
{
	int n,m;
	for(n=0,m=0;s[m]>='0'&&s[m]<='9';m++)
	n=n*10+(s[m]-'0');
	return n;
}
int jisuan(char ch,int a,int b)
{
	if(ch=='+')
	return a+b;
	if(ch=='-')
	return a-b;
	if(ch=='*')
	return a*b;
	if(ch=='/')
	return a/b;
}
int main()
{
	int i,j,k,m,n=0,p=0,l=0,flag;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
		{
			for(j=i;str[j]!='\0';j++)
			str[j]=str[j+1];
		}
	}
	for(i=0,m=0;str[i]!='=';)
	{
		k=0;
		flag=0;
		while(str[i]>='0'&&str[i]<='9')
		{
			num[k]=str[i];
			i++;
			k++;
			flag=1;
		}
		num2[m]=exchange(num);
		if(flag==1)
		m++;
		else
		i++;
	//	printf("%d ",num2[m-1]);
		memset(num,0,sizeof(num));
	}
	for(i=0;str[i]!='=';i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
		    sig[n]=str[i];
			n++;
		}
	}
	sig[n]='\0';
	for(n=0;sig[n]!='\0';n++)
	{
		if(sig[n]=='*'||sig[n]=='/')
		{
			num2[n+1]=jisuan(sig[n],num2[n],num2[n+1]);
			num2[n]=0;
		}
		if(sig[n]=='-')
		num2[n+1]=-num2[n+1];
	}
	l=sizeof(num2)/sizeof(num2[0]);
	for(n=0;n<l;n++)
	p+=num2[n];
    printf("%d",p);
	return 0;
}



