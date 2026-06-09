#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]={0},s1[100]={0},cal[100]={0};
	int number[100]={0},state[100]={0};
	int ans=0,i=0,j=0,k=0;
	gets(s);//输入计算式
	while(i<strlen(s)) 
	{
		if(s[i]==' ') i++;
		else 
		{
			s1[j]=s[i];
			i++; j++; 
		}
	}//吃掉空格
	i=0,j=0;
	while(i<strlen(s1)) 
	{
		if((s1[i]>='0')&&(s1[i]<='9'))//字符转整数存入数字数组
		{
			for(number[k]=0;s1[i]>='0'&&s1[i]<='9';i++)
				number[k]=10*number[k]+s1[i]-'0';
			k++;
		}
		else //运算符存入数组 
		{
			cal[j]=s1[i];
			j++,i++;
		}
	}
	ans=number[0];
	for(k=0;k<strlen(cal);k++)
	{
		if(cal[k]=='*') 
		{
			ans=number[k]*number[k+1];number[k+1]=ans;number[k]=ans;
		}
		else if(cal[k]=='/')
		{
			ans=number[k]/number[k+1];number[k+1]=ans;number[k]=ans;
		}
		else
		{
			state[k]=1;
		}	
	}
	i=0;
	for(k=0;k<strlen(cal);k++)
	{
		if(cal[k]=='=')//输出 
			printf("%d\n",ans);
		else if(cal[k]=='+') 
		{
			i=k;
			do
			{
				i++;	
			}while(state[i]!=1);
			ans=number[k]+number[i];number[i]=ans;
		}
		else if(cal[k]=='-') 
		{
			i=k;
			do
			{
				i++;	
			}while(state[i]!=1);
			ans=number[k]-number[i];number[i]=ans;
		}
		
	}
	
	return 0;
} 


