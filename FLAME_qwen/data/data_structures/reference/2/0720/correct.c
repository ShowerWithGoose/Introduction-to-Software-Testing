#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 10010
char s_tmp[MAX],s[MAX];
int len_tmp,len;
char op[MAX];
int num[MAX];
int top_num=-1,top_op=-1;
int calculate(char x)
{
	if(x=='+')return num[top_num]+num[top_num-1];
	else if(x=='-')return num[top_num-1]-num[top_num];
	else if(x=='*')return num[top_num-1]*num[top_num];
	else if(x=='/')return num[top_num-1]/num[top_num];
}
int pow0(int a,int b)
{
	int ans=1;
	for(int i=0;i<b;i++)ans*=a;
	return ans;
}
int main()
{
	int tmp=0,i=0,j=0;
	gets(s_tmp);
	len_tmp=strlen(s_tmp);
	for(i=0;i<len_tmp;i++)
	{
		if(s_tmp[i]!=' '&&s_tmp[i]!='=')
		{
			s[len]=s_tmp[i];
			len++;
		}
	}
	s[len]='\0';
	i=0;
	int isnegtive=0;
	while(i<len)
	{
		if(isdigit(s[i]))
		{
			tmp=0;
			for(j=i;isdigit(s[j]);j++);
			int weishu=j-i;
			int ddd,ddd_;
			ddd=ddd_=weishu-1;
			for(j=i;j<=i+ddd_;j++)
			{
				tmp+=(s[j]-'0')*pow0(10,ddd);
				ddd--;
			}
			top_num++;
			if(isnegtive)
			{
				tmp=0-tmp;
				isnegtive=0;
			}
			num[top_num]=tmp;
			i+=weishu;
		}
		else
		{
			if(s[i]=='+'||s[i]=='-')
			{
				if(i==0||!isdigit(s[i-1]))
				{
					isnegtive=1;
					i++;
					continue;
				}
				if(top_op==-1)
				{
					top_op++;
					op[top_op]=s[i];
				}
				else
				{
					while(top_op!=-1) 
					{
						int x=calculate(op[top_op]);
						top_op--;
						top_num--;
						num[top_num]=x;
					}
					top_op++;
					op[top_op]=s[i];
				}
			}
			else if(s[i]=='*'||s[i]=='/')
			{
				if(op[top_op]=='+'||op[top_op]=='-'||top_op==-1)
				{
					top_op++;
					op[top_op]=s[i];
				}
				else
				{
					int x=calculate(op[top_op]);
					top_op--;
					top_num--;
					num[top_num]=x;
					top_op++;
					op[top_op]=s[i];
				}
			}
			i++;	   
		}
	}
	while(top_op!=-1)
	{
		int x=calculate(op[top_op]);
		top_op--;
		top_num--;
		num[top_num]=x;
	}
	printf("%d\n",num[top_num]);
	return 0;
}

