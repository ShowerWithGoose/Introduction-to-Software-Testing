#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char ch[100010];
long long ans=0,len,cnt=0;
int main()
{
	gets(ch+1);
	len=strlen(ch+1);
	for(int i=1;i<=len;i++)
	{
		if(ch[i] == ' ') continue;
		ch[++cnt] = ch[i];
	}
	long long num = 0,flag = 1,op=0,ok=1;
	for(int i=1;i<=cnt;i++)
	{
		if(ch[i] == '=') 
		{
			ans += flag * num;
			break;
		}
		
		if(ch[i] < '0' || ch[i] > '9')
		{
			if(ch[i] == '+') 
			{
				ans += flag * num;
				num = 0;
				ok = 1;
				flag = 1;
			}
			else if(ch[i] == '-') 
			{
				ans += flag * num;
				num = 0;
				ok = 1;
				flag = -1;
			}
			else if(ch[i] == '*') op = 2;
			else op = 3;
		}
		else 
		{
			long long temp=0;
			while(ch[i] >= '0' && ch[i] <= '9')
			  temp = temp * 10 + ch[i++] - '0';
			
			i--;
			//printf("%lld****\n",temp);
			if(ok) num = temp,ok=0;
			else 
			{
				if(op == 2) num *= temp;
				else num /= temp;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}



