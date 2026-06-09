#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
int cclt(int a, int b, char op)
{
	switch(op){
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
}
int num(){
	int n;
	S(" %d",&n);
	return n;
}
char op(){
	char op;
	S(" %c",&op);
	return op;
}
int main(){
	int a1,a2,n;
	char b,c;
	a1=num(),b=op();
	if(b!='=') a2=num();
	while(b!='='){
		if(b=='*'||b=='/'){
			a1=cclt(a1,a2,b);
			b=op();
			if(b!='=') a2=num();
		}
		else{
			c=op();
			if(c=='+'||c=='-'||c=='='){
				a1=cclt(a1,a2,b);
				b=c;
				if(c!='=') a2=num();
			}
			else if(c=='*'||c=='/'){
				n=num();
				a2=cclt(a2,n,c);
			}
			else b=c;
		}
	}
	P("%d\n",a1);
	return 0;
}

