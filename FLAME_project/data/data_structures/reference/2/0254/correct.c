#include<stdio.h>  
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int num[100];
char fu[100];
char fuing='+'; 
int f(char* s);
int main()
{  char s[1000];
    gets(s);
   	printf("%d",f(s));
    return 0;  
}
int f(char* s){
	int tmp=0,zhan=0,sum=0;
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(isdigit(s[i])){
			tmp=tmp*10+s[i]-'0';//存数字 
		}
		if(!isdigit(s[i])&&s[i]!=' '||i==strlen(s)-1)
	{
		switch(fuing)
		{
			case '+':
				num[zhan++]=tmp;//加减开一个栈 
				break;
			case '-':
				num[zhan++]=-tmp;
				break; 
			case '*':
				num[zhan-1]*=tmp;//在同一个栈乘除运算 
				break;
			default:
				num[zhan-1]/=tmp;
				break;
		} 
		fuing=s[i];//记录下一个符号 
		tmp=0;//重新存数字	
	}
	}
	for(i=0;i<zhan;i++)
	sum+=num[i];
	return sum;
}

