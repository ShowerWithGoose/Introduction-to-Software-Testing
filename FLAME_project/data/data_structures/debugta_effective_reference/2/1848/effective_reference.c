#include <stdio.h>
#include <ctype.h>
#include <string.h>
char aft[1005];
int num[1005];
char sign[1005];
void squeez(char s[],char c);
int main()
{
	num[0]=0;
	gets(aft);
	squeez(aft,' ');
	int len_num=strlen(aft);
	int k=0;
	int hold=aft[0]-48;
	for(int i=1;i<len_num;i++)
	{
		if(isdigit(aft[i]))//是数字
		{
			hold=hold*10+aft[i]-48;
		 }
		else if(aft[i]=='=')
		{
			num[k++]=hold;
			int hold=num[0];
			for(int k=1;k<k;k++)
			{
				if(sign[k]=='+')
					hold+=num[k];
				else if(sign[k]=='-')
				    hold=hold-num[k];
			}
			printf("%d",hold);
			return 0;
		}
		else if(aft[i]=='+'||aft[i]=='-')
		{
			num[k++]=hold;
		    hold=0;
		    sign[k]=aft[i];
		}
		else
		{
			int last=i+1;//i代表符号位，last代表乘除运算结束位 
			int hold2=0;
			while(aft[i]!='+'&&aft[i]!='-')//i不是加减
			{
				while(isdigit(aft[last]))//last是数字
				{
					hold2=hold2*10+aft[last]-48;
					last++; 
				 } //这一步计算下个符号出现前数字大小hold2 
				if(aft[i]=='*')
				{
					hold=hold*hold2;
				}
				else if(aft[i]=='/')
				{
					hold=hold/hold2;
				}
				else if(aft[i]=='=')
				{
					num[k++]=hold;
					int hold=num[0];
					for(int k=1;k<k;k++)
					{
						if(sign[k]=='+')
							hold+=num[k];
						else if(sign[k]=='-')
						    hold=hold-num[k];	    
					}
					printf("%d",hold);
					return 0;
				}
				hold2=0;
				i=last;
				last=i+1;
			 } 
			num[k++]=hold;
			hold=0;
			sign[k]=aft[i];
		}
	}
	return 0;
}
void squeez(char s[],char c)
{
	int i,k;
	for(i=k=0;i<strlen(s);i++)
	    if(s[i]!=c)
	        s[k++]=s[i];
	s[k]='\0';
}



