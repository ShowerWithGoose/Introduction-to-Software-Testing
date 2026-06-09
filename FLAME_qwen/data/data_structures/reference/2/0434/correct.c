#include <stdio.h>
#include <string.h>

char sfirst[10086],s[10086],sign[10086];
long long num[10086];


int main ()
{
	int i=0,j,k,lenfirst,len,temp,num1=0;
	long long sum;
	char ch;
	ch=getchar();
	while (ch!='\n')
	{
		sfirst[i]=ch;
		i++;
		ch=getchar();
	}
	
	lenfirst=strlen(sfirst);
	for (i=0,j=0;i<lenfirst;i++)
	if (sfirst[i]!=' ')
	{
		s[j]=sfirst[i];
		j++;
	}
	len=strlen(s);
	
	for (i=0,j=0,k=0;i<len;i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			temp=0;
			for (;s[i]>='0'&&s[i]<='9';i++)
			temp=temp*10+s[i]-'0';
			i--;
			num[j]=temp;
			j++;
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
		{
			sign[k]=s[i];
			k++;
		}	
		
		while(k>1&&(sign[k-2]=='*'||sign[k-2]=='/'))
		{
			if (sign[k-2]=='*')
			{
				temp=num[j-1]*num[j-2];
				num[j-2]=temp;
				j--;
			}
			else 
			{
				temp=num[j-2]/num[j-1];
				num[j-2]=temp;
				j--;
			}
			sign[k-2]=sign[k-1];
			k--;	
		}
	}
	
	for (num1=0,sum=num[0];num1<k;num1++)
	{
		if (sign[num1]=='+')
		sum+=num[num1+1];
		else if (sign[num1]=='-')
		sum-=num[num1+1];
	}
	
	printf ("%lld",sum);
	
	return 0;
}
