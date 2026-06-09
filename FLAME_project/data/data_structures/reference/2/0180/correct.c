#include<stdio.h>	
#include <string.h>
int ans=0,liu=1,t=0;
char pan1='+';
inline void f1(char ch)
{
	switch(ch)
	{
		case '+':
			ans+=liu;
			break;
		case '-':
			ans-=liu;
			break;
	}
}
char pan2='*';
inline void f2(char ch)
{
	switch(ch)
	{
		case '*':
			liu*=t;
			break;
		case '/':
			liu/=t;
			break;
	}
}
int main(){
	char std[10000],s[10000];
	gets(std);
	int end,i;
	for(end=0,i=0;std[end]!='=';end++){if(std[end]!=' ') {s[i]=std[end];i++;}}
	int j; 
	for(j=0;j<strlen(s);j++){
		if(s[j]=='+'){
			f2(pan2);f1(pan1);
			pan1='+';
			liu=1;t=0;
			pan2='*';
		}
		else if(s[j]=='-'){
			f2(pan2);f1(pan1);
			pan1='-';
			liu=1;t=0;
            pan2='*';
		}
		else if(s[j]=='*'){
			f2(pan2);
			pan2='*';
			t=0;
		}
		else if(s[j]=='/'){
			f2(pan2);
			pan2='/';
			t=0;
		}
		else {
			t=t*10;
			t+=s[j]-'0';
		}
	}
    f2(pan2);f1(pan1);
	printf("%d",ans);
    return 0;	
}

