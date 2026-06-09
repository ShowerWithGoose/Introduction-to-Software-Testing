#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100007
#define ll long long
char s[M],ch[M],str[M],op[M];
ll a[M];
ll a1=0,a2,a3;
char op1='+',op2,op3;
int main() {
	gets(s);
	int i,j=0,head=0,now=0,top=0,rear=0,k=0,len=strlen(s);
	for(i=0; i<len; i++) {
		if(isspace(s[i])) {
			continue;
		}
		ch[j++]=s[i];
	}
	int lench=strlen(ch);
	for(i=0; i<lench; i++) {
		if(isdigit(ch[i])) {
			str[k++]=ch[i];
		} else {
			a[now++]=atoi(str);
			while(k--){
				str[k]='\0';
			}
			k=0;
			op[rear++]=ch[i];
		}
	}
	while(op1!='=') {
		a2=a[head++],op2=op[top++];
		while(op2=='*' || op2=='/') {
			a3=a[head++],op3=op[top++];
			if(op2=='*')
				a2 *= a3;
			else if(op2=='/')
				a2 /= a3;
			op2 = op3;
		}
		if(op1=='+')
			a1 += a2;
		else if(op1=='-')
			a1 -= a2;
		op1 = op2;
	}
	printf("%lld",a1);
	return 0;

}

