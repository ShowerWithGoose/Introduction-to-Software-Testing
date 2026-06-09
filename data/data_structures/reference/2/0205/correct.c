#include<stdio.h>
int main()
{
	char s[1000], sig[1000]={};
	int num[1000]={0};
	int i, j=0, k=0, l=0, a=0, b;  //j:数字的个数，k：运算符的个数 
	gets(s);
	for(i=0;s[i]!='=';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a=a*10+s[i]-'0';
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			num[j++]=a;a=0;
			sig[k++]=s[i];
		}
	}
	num[j]=a;j++;
	if(k==0)
		printf("%d",a);
	else
	{
		for(i=0;i<k;i++)
		{
				if(sig[i]=='*')
				{
					num[i+1]*=num[i];
					num[i]=0;
					if(i==0)
						sig[i]='+';
					else
						sig[i]=sig[i-1];
				}
				else if(sig[i]=='/')
				{
					num[i+1]=num[i]/num[i+1];
					num[i]=0;
					if(i==0)
						sig[i]='+';
					else
					sig[i]=sig[i-1];
				}
		}
		b=num[0];
		for(i=0;i<k;i++)
		{
			if(sig[i]=='+')
				b+=num[i+1];
			else
				b-=num[i+1];
		}
		printf("%d",b);
		
		return 0;
	} 
	
}

