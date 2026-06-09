#include <stdio.h>
#include <string.h>
char s1[101],s2[101],sign[101];
int res[101],ans[101],i=0,j=0,k,l,p,q=0,len,len2,flag,temp,answer=0;
int main()
{ 
	gets(s1);
	len=strlen(s1);
	for(i=0;i<len;i++)//去空格 
	{
		if(s1[i]!=' ') s2[j++]=s1[i];
	}
	len2=strlen(s2);
	for(i=0;i<len2;i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')//数字提取 
		{
			temp=temp*10+s2[i]-48;
			res[k]=temp;
		}
		else//符号提取 
		{
			temp=0;
			sign[l]=s2[i];
			k++;
			l++;
		}
	}
	for(i=0;i<k;i++){//合并乘除法 
		if(sign[i] == '+' || sign[i] == '-' || sign[i] == '=')
		{	
			ans[p] = res[i];
			p++;
		}
		else if(sign[i] == '*')
		{
			ans[i] = 1;
			res[i+1] = res[i] * res[i+1];
		}
		else if(sign[i] == '/')
		{
			ans[i] = 1;
			res[i+1] = res[i] / res[i+1];
		}
		else if(sign[i] == '=')
		{
			break;
		}
	}
	for(i = 0;i<k; i++)//去除加减法 
{
	if(sign[i] == '*' || sign[i] == '/')
	{
		continue;
	}
	else if(sign[i] == '+' || sign[i] == '-' || sign[i] == '=')
	{
		sign[q] = sign[i];
		q++;
	}
}
for(i=0;i<q;i++)//最后计算加减法 
{	
	if(i == 0)answer += ans[i];
	 if(sign[i] == '+')	answer+=ans[i+1];
	 if(sign[i] == '-')	answer-=ans[i+1];
}
printf("%d",answer);
	return 0;
 } 



