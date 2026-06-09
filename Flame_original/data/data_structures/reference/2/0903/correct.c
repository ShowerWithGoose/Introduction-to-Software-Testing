#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int calculate(char* s) {
    int n=strlen(s);
    int stk[n],top=0;
    char preSign='+';
    int num=0;
    int i=-1;
	while (i<n-1) {
    	i++;
        if (isdigit(s[i])) {
            num=num*10+(int)(s[i]-'0');
        }
        if (!isdigit(s[i])&&s[i]!=' '||i==n-1) {
        	if(preSign=='+'){
        		stk[top++]=num;
		    }else if(preSign=='-'){
		   		stk[top++]=-num;
		    }else if(preSign=='*'){
		   		stk[top-1]*=num;
		    }else{
		    	stk[top-1]/=num;
			}
		    
            preSign=s[i];
            num=0;
        }
    }
    int ret=0;
    i=0;
	while(i<top) {
        ret+=stk[i];
		i++;
    }
    return ret;
}

int main() 
{ 
	
	char s[2000];
	gets(s);
	s[strlen(s)-1]='\0';
	printf("%d\n",calculate(s)); 
	return 0; 
} 
/*
isdigit()函数：
用来检测一个字符是否是十进制数字。
若参数c为阿拉伯数字0~9，则返回非0值，否则返回0。
示例：isdigit() 函数用来检测 str 字符串的首个字符是否是十进制数字，如果是，就调用 atoi() 函数将 str 转换为整数。
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char str[]="1776ad";
    int year;
    if(isdigit(str[0]))    
    {
            year = atoi (str);
            printf ("The year that followed %d was %d.\n", year, year+1);
    }
    return 0;
}*/




