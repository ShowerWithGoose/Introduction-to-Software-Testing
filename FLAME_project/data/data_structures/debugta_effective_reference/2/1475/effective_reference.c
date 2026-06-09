#include<stdio.h>
#include<string.h>
int len;
long long calculation(char c[])
{
	int i;
	int op=1;
	int flag1=0,flag2=0;
	long long ans=0,num1=0,num=0;//num1用于暂存，num2代表最终 
	
	for(i=0;i<len;i++)
	{
		num1=0;
		while(c[i]>='0'&&c[i]<='9')
		{
			num1=num1*10+c[i]-'0';
			i++;
		}
		
		if(c[i]=='+')
		{
			if(flag1==1&&flag2==0)
			{
				num*=num1;
			}
			else if(flag1==0&&flag2==1)
			{
				num/=num1;
			}
			else
			{
				num=num1;
			}
	        ans+=op*num; 
			flag1=0,flag2=0;		
			op=1;
			num=0; 
		}
		else if(c[i]=='-')
		{
			if(flag1==1&&flag2==0)
			{
				num*=num1;
			}
			else if(flag1==0&&flag2==1)
			{
				num/=num1;
			}
			else
			{
				num=num1;
			}
	        ans+=op*num; 
			flag1=0,flag2=0;
			op=-1;
			num=0;
		}
		else if(c[i]=='*')
		{
			if(flag1==1&&flag2==0)
			{
				num*=num1;
			}
			else if(flag1==0&&flag2==1)
			{
				num=num/num1;
				flag1=1;
				flag2=0;
			}
			else if(flag1==0&&flag2==0)
			{
				flag1=1;
				num=num1;
			}
		}
		else if(c[i]=='/')
		{
			if(flag1==1&&flag2==0)
			{
				num*=num1;
				flag1=0,flag2=1;
			}
			else if(flag1==0&&flag2==1)
			{
				num/=num1;
			}
			else if(flag1==0&&flag2==0)
			{
				flag2=1;
				num=num1;
			}
		}
		else if(c[i]=='=')
		{
			if(flag1==1&&flag2==0)
			{
				num*=num1;
			}
			else if(flag1==0&&flag2==1)
			{
				num/=num1;
			}
			else if(flag1==0&&flag2==0)
			{
				num=num1;
			}
			ans+=op*num;
			
			return ans;
		} 
	} 
	
}
int main()
{
	int i,j;
	long long ans;
	char c[100];
	gets(c);
	len=strlen(c);
	for(i=j=0;c[i]!='\0';i++)
	{
		if(c[i]!=' ')
		{
			c[j++]=c[i];
		}
	}
	c[j]='\0';
	len=strlen(c);
	ans=calculation(c);
    printf("%lld",ans);
	
	return 0;
}



