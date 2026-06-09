#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char s[100];
int ans[100]={0};

int main()
{
	int i,j;
	int top=0,num=0,t=0;
	gets(s);
	int l=strlen(s);
	char sign = '+';
	
	s[l-1]='\0';
	
	for(i=0;i<l;i++){
		if(isdigit(s[i])) num=num*10+(int)(s[i]-'0');
		else if(s[i]!=' '||i==l-1){
			switch(sign){
				case '+': ans[top++]=num;
					break;
				case '-': ans[top++]=-num;
					break;
				case '*': ans[top-1]*=num;
					break;
				default : ans[top-1]/=num;	
			}
			num=0;
			sign=s[i];
		}	
	}
	while(top){
		t+=ans[--top];
	}
	printf("%d",t);
	
	return 0;
}




