#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//freopen("damn.txt","r",stdin);//
	
	char flag=0;//01 + -
	char flag2=0;//012 нч * /
	char s[100];
	int result=0;
	int temp=0,temp2=0;
	
	gets(s);
	
	int i;
	
	for(i=0;s[i]!='=';i++)
	{
		if(s[i]==' ') continue;
		
		if(s[i]=='+')
		{
			if(flag==0) result+=temp;
			else result-=temp;
			temp=0;
			flag=0;
		} 
		else if(s[i]=='-')
		{
			if(flag==0) result+=temp;
			else result-=temp;
			temp=0;
			flag=1;
		}
		else if(s[i]=='*')
		{
			flag2=1;
		}
		else if(s[i]=='/')
		{
			flag2=2;
	    }
		
		if(s[i]>='0'&&s[i]<='9')
		{
			if(flag2==0)
			{
				temp=temp*10+s[i]-'0';
			}
			else if(flag2==1)
			{
				temp2=temp2*10+s[i]-'0';
				if(!(s[i+1]>='0'&&s[i+1]<='9'))
				{
					temp*=temp2;
					temp2=0; 
					flag2=0; 
				}
			}
			else if(flag2==2)
			{
				temp2=temp2*10+s[i]-'0';
				if(!(s[i+1]>='0'&&s[i+1]<='9'))
				{
					temp/=temp2;
					temp2=0; 
					flag2=0; 
				}
			}
		}
		
		
	}
	
	if(flag==0) result+=temp;
	else result-=temp;
	
	
	printf("%d",result);
	
	
	
	
	
	return 0;
}

