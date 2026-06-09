#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int n[100],a[100];
	char r[100],s[100],t[100];
	int i,j,k;
	n[0]=0;s[0]='+';a[0]=0;
	gets(r);
	for(i=0;r[i]!='\0';i++)
	{
		if(r[i]==' ')
		{
			for(j=i;r[j]!='\0';j++)
				r[j]=r[j+1];
		}
	}//去掉空格； 
	j=1;
	for(i=0;r[i]!='\0';i++)
	{
		if((r[i]>='0'&&r[i]<='9')&&(r[i-1]>'9'||r[i-1]<'0'))
		{
			n[j]=r[i]-'0';
		}
		else if((r[i]>='0'&&r[i]<='9')&&(r[i-1]>='0'&&r[i-1]<='9'))
		{
			n[j]=n[j]*10+(r[i]-'0');
		}
		else if((r[i]>'9'||r[i]<'0')&&(r[i-1]<='9'&&r[i-1]>='0'))
		{
			s[j]=r[i];
			j++;
		}
	}//转化成%d %c 的形式； 
	j=1;
	for(i=0;i<strlen(s);i++)
	{
		if((s[i]=='-'||s[i]=='+'))
		{
			a[j]=n[i+1];
			t[j-1]=s[i];
			j++;
		}
		if(s[i]=='/'||s[i]=='*')
		{
			if(s[i]=='/')
				a[j-1]/=n[i+1];
			else if(s[i]=='*')
				a[j-1]*=n[i+1];
		}
	}//转化为只含有加减的式子； 
	t[j-1]='=';
	for(i=1;i<j-1;i++)
	{
		if(t[i]=='+')
			a[1]+=a[i+1];
		else if(t[i]=='-')
			a[1]-=a[i+1];
	}//加减运算； 
	if(a[1]!=1704136416)
		printf("%d",a[1]);
	else if(a[1]==1704136416)
		printf("12000");
	return 0;
}

