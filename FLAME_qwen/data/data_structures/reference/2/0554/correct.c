#include<stdio.h>

int calculate(int a, int b, char op);

int readnum();

char readop();

int main(){

	int a[5],num;

	char b[5],op;

	a[0]=readnum();

	b[0]=readop();

	if(b[0]!='=') a[1]=readnum();

	while(b[0]!='='){

		if(b[0]=='*'||b[0]=='/'){

			a[0]=calculate(a[0],a[1],b[0]);

			b[0]=readop();

			if(b[0]!='=') a[1]=readnum();
		}
		else{

		    op=readop();

			if(op=='+'||op =='-'||op=='='){

				a[0]=calculate(a[0],a[1],b[0]);

				b[0]=op;

				if(op!='=') a[1]=readnum();
			}

			else if(op!='='){

				num=readnum();

				a[1]=calculate(a[1],num,op);
			}

			else b[0]=op;
		}
    }

	printf("%d\n",a[0]);

	return 0;
}

int calculate(int a, int b, char op){

	int result;

	if(op=='+') result=a+b;

	else if(op=='-') result=a-b;

	else if(op=='*') result=a*b;

	else result=a/b;

	return result;
}

int readnum(){

	int num;

	scanf(" %d",&num);

	return num;
}
char readop(){

	char op;

	scanf(" %c",&op);

	return op;
}



