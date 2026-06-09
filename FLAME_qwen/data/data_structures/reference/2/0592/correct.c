#include <stdio.h>
#include <ctype.h>
int c(int a,char op,int b){
	int result;
	if(op=='+')
		result=a+b;
	if(op=='-')
		result=a-b;
	if(op=='*')
		result=a*b;
	if(op=='/')
		result=a/b;
	return result;
}
int rnum(){
	int num;
	scanf(" %d",&num);
	return num;
}
char rop(){
	char op;
	scanf(" %c",&op);
	return op;
}

int main() {
	int a[2],num;
	char s,op;
	a[0]=rnum();
	s=rop();
	if(s!='=')
	a[1]=rnum();
	while(s!='=') {
		if(s=='*'||s=='/') {
			a[0]=c(a[0],s,a[1]);
			s=rop();
			if(s!='=')
				a[1]=rnum();
		} else{
			op=rop();
			if(op=='+'||op=='-'||op=='=') {
				a[0]=c(a[0],s,a[1]);
				s=op;
				if(op!='=')
					a[1]=rnum();
			} else if(op!='=') {
				num=rnum();
				a[1]=c(a[1],op,num);
			} else
				s=op;
		}
	}
	printf("%d\n",a[0]);
	return 0;
}


