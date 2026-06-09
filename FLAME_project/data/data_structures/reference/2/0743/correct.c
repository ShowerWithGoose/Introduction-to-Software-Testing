#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define MaxTo(a,b) (a)=(a)>(b)?(a):(b)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define ull unsigned long long
#define FO2(N,M) for(int i=0;i<N;i++)for(int j=0;j<M;j++)
#define swap(type,a,b) {type t=a;a=b;b=t;}
#define CsTop CSTop
int NSt[114514];char CSt[114514];//数字栈和符号栈
int NSTop,CSTop;
char s[1919810];
void Deal(){//处理栈中间的两个元素
	int Num2=NSt[NSTop];NSt[NSTop--]=0;//减数
	int Num1=NSt[NSTop];NSt[NSTop--]=0;//被减数
	if(CSt[CSTop-1]=='+'){NSt[++NSTop]=Num1+Num2;}
	if(CSt[CSTop-1]=='-'){NSt[++NSTop]=Num1-Num2;}
	if(CSt[CSTop-1]=='*'){NSt[++NSTop]=Num1*Num2;}
	if(CSt[CSTop-1]=='/'){NSt[++NSTop]=Num1/Num2;}
	CSt[--CSTop]=0;
}
int main()
{
	gets(s);
	for(int Read=0;s[Read]!='='&&s[Read]!='\0';Read++){
		if(s[Read]==32) continue;
		if(s[Read]>='0'&&s[Read]<='9'){//是数字
			NSt[NSTop]=NSt[NSTop]*10+s[Read]-48;//栈的数字增加
		}
		else if(s[Read]=='+'||s[Read]=='-'){//是加减号
			while(CsTop>0) Deal();
			NSTop++;
			CSt[CSTop++]=s[Read];
		}
		else if(s[Read]=='*'||s[Read]=='/'){//是乘除
			if(CsTop>0) if(CSt[CSTop-1]=='*'||CSt[CSTop-1]=='/')Deal();
			NSTop++;
			CSt[CSTop++]=s[Read];
		}
	}
	while(CSTop>0) Deal();
	printf("%d",NSt[0]);
	return 0;
}




