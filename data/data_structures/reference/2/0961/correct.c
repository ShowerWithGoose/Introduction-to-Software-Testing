#include<stdio.h>
#include<string.h>
int getnum(){
	int num;
	scanf(" %d",&num);
	return num;
}
char getop(){
	char op;
	scanf(" %c",&op);
	return op;
}
int algorithm(int a,int b,char op)
{
	int result;
	if(op == '+') result=  a+b;
	if(op == '-') result=  a-b;
	if(op == '*') result=  a*b;
	if(op == '/') result=  a/b;
	return result;
}
int main() {
	int a[5],num;
	char b[5],op;
	a[0]=getnum();b[0]=getop();
	if(b[0]!='=')
	{
		a[1]=getnum();
	}
	while(b[0]!='='){
		if(b[0]=='*'||b[0]=='/'){
			a[0]=algorithm(a[0],a[1],b[0]);
			b[0]=getop();
			if(b[0]!='='){
				a[1]=getnum();
			}
		}
		else{
			b[1]=getop();
			if(b[1]=='*'||b[1]=='/'){
				a[2]=getnum();
				a[1]=algorithm(a[1],a[2],b[1]);
			}
			else{
				a[0]=algorithm(a[0],a[1],b[0]);
				b[0]=b[1];
				if(b[0]!='=') a[1]=getnum();
			}
		}
	}
	printf("%d",a[0]);
	return 0;
}

