#include<stdio.h>
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#define ll long long
#define eps 1e-6
#define MAX 1000005
int main(){
	int num=0;
	int i,m;
	char s[100005]="";
	gets(s);
	if(s[0]!='0'){
		int j=1;
		printf("%c.",s[0]);
		while(s[j]!='\0'){
		if(s[j]!='.') printf("%c",s[j]);
		else  m=j;
		j++;	
		}
		printf("e%d",m-1);
	}
	else{
		while(s[num]=='0'||s[num]=='.')
		num++;
		printf("%c",s[num]);
		if(s[num+1]!='\0') printf(".");
		for(i=num+1;s[i]!='\0';i++){
			printf("%c",s[i]);
		}
		printf("e-%d",num-1);
	}



	return 0;
}




