#include <stdio.h>
#include <ctype.h>
#include <string.h>
char ch[1005];
int num[1005];
char sign[1005];
void squeez(char s[],char c);
int main()
{
	num[0]=0;
	gets(ch);
	squeez(ch,' ');
	int len=strlen(ch);
	int j=0;
	int hold=ch[0]-48;
	for(int i=1;i<len;i++)
	{
		if(isdigit(ch[i]))//是数字
		{
			hold=hold*10+ch[i]-48;
		 }
		else if(ch[i]=='=')
		{
			num[j++]=hold;
			int sum=num[0];
			for(int k=1;k<j;k++)
			{
				if(sign[k]=='+')
					sum+=num[k];
				else if(sign[k]=='-')
				    sum=sum-num[k];
			}
			printf("%d",sum);
			return 0;
		}
		else if(ch[i]=='+'||ch[i]=='-')
		{
			num[j++]=hold;
		    hold=0;
		    sign[j]=ch[i];
		}
		else
		{
			int last=i+1;//i代表符号位，last代表乘除运算结束位 
			int hold2=0;
			while(ch[i]!='+'&&ch[i]!='-')//i不是加减
			{
				while(isdigit(ch[last]))//last是数字
				{
					hold2=hold2*10+ch[last]-48;
					last++; 
				 } //这一步计算下个符号出现前数字大小hold2 
				if(ch[i]=='*')
				{
					hold=hold*hold2;
				}
				else if(ch[i]=='/')
				{
					hold=hold/hold2;
				}
				else if(ch[i]=='=')
				{
					num[j++]=hold;
					int sum=num[0];
					for(int k=1;k<j;k++)
					{
						if(sign[k]=='+')
							sum+=num[k];
						else if(sign[k]=='-')
						    sum=sum-num[k];	    
					}
					printf("%d",sum);
					return 0;
				}
				hold2=0;
				i=last;
				last=i+1;
			 } 
			num[j++]=hold;
			hold=0;
			sign[j]=ch[i];
		}
	}
	return 0;
}
void squeez(char s[],char c)
{
	int i,j;
	for(i=j=0;i<strlen(s);i++)
	    if(s[i]!=c)
	        s[j++]=s[i];
	s[j]='\0';
}



