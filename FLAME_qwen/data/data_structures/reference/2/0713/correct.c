#include <stdio.h>
#include <string.h>
int numin(){
	int n;
	scanf("%d ",&n);
	return n;
}

char opin(){
	char op;
	scanf("%c ",&op);
	return op;
}

int calculate(int a,int b,char sign){
	int result=0;
	if(sign=='+') return a+b;
	else if(sign=='-') return a-b;
	else if(sign=='*') return a*b;
	else if(sign=='/') return a/b;
}

int main(){
	int n1,n2,n3;
	char op1,op2;
	n1=numin();
	op1=opin();
	if(op1=='='){
		printf("%d",n1);
	}
	else{
		n2=numin();
		op2=opin();
		while(op2!='='){
			n3=numin();
			if( op1=='*' || op1=='/'){
				n1=calculate(n1,n2,op1);
				op1=op2;
				n2=n3;
			}
			else{
				if( op2=='+' || op2=='-'){
					n1=calculate(n1,n2,op1);
					op1=op2;
					n2=n3;
				}
				else{
					n2=calculate(n2,n3,op2);
				}
				
			}
			op2=opin();
		}
		printf("%d",calculate(n1,n2,op1));
	}
	return 0;
}

