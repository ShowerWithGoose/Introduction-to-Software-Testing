#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<memory.h>
#define MAXN 1000
char s[MAXN]; 
char str[MAXN];
char s0[200];

int main()
{	
int dis;//扩展串长度 
int pos=1;//字符位置 
int i,j;
scanf("%s",s);
str[0]=s[0];
int len=strlen(s);

	for(i=1;i<strlen(s)-1;i++)
	{
		
	if((s[i]=='-')&&(s[i+1]>s[i-1])&&((s[i-1]>='0'&&s[i+1]<='9')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')))
		{
		dis=s[i+1]-s[i-1];
		pos+=dis-1;
		for(j=0;j<dis-1;j++)
		{
			s0[j]=s[i-1]+j+1;//需要扩展的字符串 
		}	
			s0[dis-1]='\0';
			strcat(str,s0);//把扩展的字符串插入到新字符串中	
		}
	
	else 
		{
			str[pos]=s[i];
			pos++;	
		}
	
	} 
	
str[pos]=s[len-1];
puts(str);
return 0;
}


