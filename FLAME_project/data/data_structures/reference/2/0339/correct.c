#include<stdio.h>
#include<string.h>
#include<math.h>
int cnt(char *s,int len,int x)
{
	int i=x,flag=0;
	for(i;i<len;i++)
	{
		if(s[i]=='*'||s[i]=='/')
		flag++;
		else break;
	}
	return flag;
}
int main()
{
	char s[1000]="\0",ss[1000]="\0";//清空空格
	gets(s);
	int i,j = 0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!=' ')
		{
			ss[j] = s[i];
			j++;
		}
		else continue;
	}    
	char s1[1000]="\0";//数字符号分开 
	int s2[1000]={0};
	int k,h,m = 0,n = 0,flag = 0;
	for(k=0;k<strlen(ss);k++)
	{
		if(ss[k]=='+'||ss[k]=='-'||ss[k]=='*'||ss[k]=='/'||ss[k]=='=')
		{
			s1[m] = ss[k];
			m++;
			for(h=flag;h>0;h--)
				s2[n] += (ss[k-h]-'0')*pow(10,h-1);
			n++;
			flag = 0;
		}
		else
			flag++;
	}
	int sum0,sum1=0,sum2=0,sum3,total,d;//计算结果 
	for(sum0=0;sum0<strlen(s1);sum0++)
	{
		sum1 = sum0;
		total = s2[sum0];
		if(s1[sum0]=='*'||s1[sum0]=='/')
		{
			for(sum3=sum0;sum3<sum0+cnt(s1,strlen(s1),sum1);sum3++)
			{
				
				if(s1[sum3]=='*')
				total *= s2[sum3+1];
				else if(s1[sum3]=='/')
				total /= s2[sum3+1];
				s2[sum3+1] = 0;
				
			}
			
		}
		s2[sum0] = total;
		sum0 += cnt(s1,strlen(s1),sum1);
		sum1 = sum0;
	}
	sum2 = s2[0];
	for(d=0;d<1000;d++)
	{
		
		if(s1[d]=='+')
		sum2+=s2[d+1];
		if(s1[d]=='-')
		sum2-=s2[d+1];
		if(s1[d]=='*'||s1[d]=='/')
		continue;
	}
	printf("%d",sum2);
	return 0;
}


