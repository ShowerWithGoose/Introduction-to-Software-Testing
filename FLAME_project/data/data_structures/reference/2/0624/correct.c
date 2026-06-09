#include<stdio.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)

char s;
int sign=1,x=0,y=0,sum=0;//x用来表示整体的绝对值，y表示当前因子的值 
char c='+';

void operate(char op){
	if(op=='+'||op=='-')x=y;
	else if(op=='*')x*=y;
	else if(op=='/')x/=y;
	y=0;
	return;
}

int main(){
	while(scanf("%c",&s)!=EOF){
		if(s==' ')continue;
		if('0'<=s&&s<='9')y=10*y+s-'0';
		else operate(c),c=s;
		if(s=='-'||s=='+'||s=='=')sum+=sign*x,x=y=0;
		if(s=='-')sign=-1;
		else if(s=='+')sign=1;
	}
	printf("%d",sum);
	return 0;
} 



