#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
char s[100001];
int l;
int main(){
	scanf("%s",&s);
	//(x!=0)
	//0.xxxxx at most
	//0.000000000xxxxx
	//xxx.xxxxxxxxx
	l=strlen(s);
	if(s[0]=='0'){
		int pos=0;
		REP(i,2,l-1)
			if(s[i]!='0')
				{pos=i;break;}
		putchar(s[pos]);
		if(pos!=l-1)putchar('.');
		REP(i,pos+1,l-1)putchar(s[i]);
		printf("e-%d",pos-1);
	}else{
		int pos=0;
		REP(i,0,l-1)
			if(s[i]=='.')
				{pos=i;break;}
		putchar(s[0]);
		putchar('.');
		REP(i,1,l-1)
			if(s[i]!='.')
				putchar(s[i]);
		printf("e%d",pos-1);
	}
}

