#include<stdio.h>
#include<string.h>
int len;
long long calculation(char s[])
{
	int i;
	int op=1;
	int flag1=0,flag2=0;
	long long ans=0,num1=0,num2=0;//num1用于暂存，num2代表最终 
	
	for(i=0;i<len;i++)
	{
		num1=0;
		while(s[i]>='0'&&s[i]<='9')
		{
			num1=num1*10+s[i]-'0';
			i++;
		}
		
		if(s[i]=='+')
		{
			if(flag1==1&&flag2==0)
			{
				num2*=num1;
			}
			else if(flag1==0&&flag2==1)
			{
				num2/=num1;
			}
			else
			{
				num2=num1;
			}
	        ans+=op*num2; 
			flag1=0,flag2=0;		
			op=1;
			num2=0; 
		}
		else if(s[i]=='-')
		{
			if(flag1==1&&flag2==0)
			{
				num2*=num1;
			}
			else if(flag1==0&&flag2==1)
			{
				num2/=num1;
			}
			else
			{
				num2=num1;
			}
	        ans+=op*num2; 
			flag1=0,flag2=0;
			op=-1;
			num2=0;
		}
		else if(s[i]=='*')
		{
			if(flag1==1&&flag2==0)
			{
				num2*=num1;
			}
			else if(flag1==0&&flag2==1)
			{
				num2=num2/num1;
				flag1=1;
				flag2=0;
			}
			else if(flag1==0&&flag2==0)
			{
				flag1=1;
				num2=num1;
			}
		}
		else if(s[i]=='/')
		{
			if(flag1==1&&flag2==0)
			{
				num2*=num1;
				flag1=0,flag2=1;
			}
			else if(flag1==0&&flag2==1)
			{
				num2/=num1;
			}
			else if(flag1==0&&flag2==0)
			{
				flag2=1;
				num2=num1;
			}
		}
		else if(s[i]=='=')
		{
			if(flag1==1&&flag2==0)
			{
				num2*=num1;
			}
			else if(flag1==0&&flag2==1)
			{
				num2/=num1;
			}
			else if(flag1==0&&flag2==0)
			{
				num2=num1;
			}
			ans+=op*num2;
			
			return ans;
		} 
	} 
	
}
int main()
{
	int i,j;
	long long ans;
	char s[100];
	gets(s);
	len=strlen(s);
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ')
		{
			s[j++]=s[i];
		}
	}
	s[j]='\0';
	len=strlen(s);
	ans=calculation(s);
    printf("%lld",ans);
	
	return 0;
}



