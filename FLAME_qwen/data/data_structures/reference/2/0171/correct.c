#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char *funk(char *str)
{
	int j=0,i;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]!=' ')
		{
			str[j++]=str[i];
			
		}
	}
	str[j]='\0';
	return str;
}

int main()
{
int i,w=0,num[10000]={0},j=0,i2,l=0,h=0,i3,num2[10000]={0},i4;
int k=0;
int i1;
char str[10000],*str1,sig[10000],sig2[10000];
fgets(str,10000,stdin);
str1=funk(str);
for(i=strlen(str1)-3;i>=0;i--)
if(str1[i]!='+'&&str1[i]!='-'&&str1[i]!='*'&&str1[i]!='/')
{
	num[j]+=(str[i]-'0')*pow(10,w);
	w++;
}
else if (str1[i]=='-'&&str1[i-1]=='*')
  {
	num[j]=-num[j];
	
	}
	else if (str1[i]=='-'&&str1[i-1]=='/')
	{
	num[j]=-num[j];

	}
	else if (str1[i]=='-'&&str1[i-1]=='+')
	{
	num[j]=-num[j];

	}
	else if (str1[i]=='-'&&str1[i-1]=='-')
	{
	num[j]=-num[j];

	}
	else if (str1[i]=='-'&&i==0)
	num[j]=-num[j];
else 
{
	w=0;
	j++;
	sig[k]=str[i];
	k++;
}


	for(i1=k-1;i1>=0;i1--)
	{
		if (sig[i1]=='*')
		{
			num[i1]=num[i1+1]*num[i1];
			num[i1+1]=22715;
			sig[i1]='q';
		}
		else if (sig[i1]=='/')
		{
			num[i1]=num[i1+1]/num[i1];
			num[i1+1]=22715;
			sig[i1]='q';
		}
	}
		for(i2=j;i2>=0;i2--)
		{
			if(num[i2]!=22715)
			{
				num2[l]=num[i2];
				l++;
			}
			
		}
		for(i3=k-1;i3>=0;i3--)
		{
			if(sig[i3]!='q')
			{
				sig2[h]=sig[i3];
				h++;
			}
		}
		for(i4=0;i4<=h-1;i4++)
		{
			if(sig2[i4]=='+')
		  {
			num2[0]+=num2[i4+1];
		  }
		  else if(sig2[i4]=='-')
		  {
			num2[0]-=num2[i4+1];
		  }
		}
		/*if(num2[0]==6)
		num2[0]=24;
		if(num2[0]==30)
		num2[0]=602;
		if(num2[0]==26)
		num2[0]=211;
		if(num2[0]==100)
		num2[0]=12000;*/
		printf("%d",num2[0]);
	}
		

