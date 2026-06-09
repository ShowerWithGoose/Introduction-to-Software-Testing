#include<stdio.h>
int calculate(int,char,int);
int number();
char operation();
int n1,n2,n3;
char o1,o2;
int n;
char o;
int main()
{
	n1=number();
	o1=operation();
	if(o1!='=') n2=number();
	while(o1!='='){
		if(o1=='*'||o1=='/'){
			n1=calculate(n1,o1,n2);
			o1=operation();
			if(o1!='=') n2=number();
		}
		else{
			o2=operation();
			if(o2=='+'||o2=='-'||o2=='='){
				n1=calculate(n1,o1,n2);
				o1=o2;
				if(o2!='=') n2=number();
			}
			else if(o2=='*'||o2=='/'){
				n3=number();
				n2=calculate(n2,o2,n3);
			}
			else if(o2=='='){
				o1='=';
			}
		}
	}
	printf("%d\n",n1);
	return 0;
}

int calculate(int n1,char o,int n2){
	if(o=='+') return (n1+n2);
	if(o=='-') return (n1-n2);
	if(o=='*') return (n1*n2);
	if(o=='/') return (n1/n2);
}

int number(){
	scanf("%d",&n);
	return n;
}

char operation(){
	scanf(" %c",&o);
	return o;
}

