#include <stdio.h>
int calula(int a,int b,char op)
{
	int sum;
	if(op=='+')sum=a+b;
	else if(op=='-')sum=a-b;
	else if(op=='*')sum=a*b;
	else sum=a/b;
	return sum;
}
int get_num(){
	int num;
	scanf(" %d",&num);
	return num;
}
int get_op(){
	char op;
	scanf(" %c",&op);
	return op;
}
int main()
{
	int a[2],num;
	char b[1],op;
	a[0]=get_num();
	b[0]=get_op();
	if(b[0]!='=')a[1]=get_num();
	while(b[0]!='='){
		if(b[0]=='*'||b[0]=='/'){
			a[0]=calula(a[0],a[1],b[0]);
			b[0]=get_op();
			if(b[0]!='=')a[1]=get_num();
		}
		else{
			op=get_op();
			if(op=='+'||op=='-'||op=='='){
				a[0]=calula(a[0],a[1],b[0]);
				b[0]=op;
				if(op!='=')a[1]=get_num();
			}
			else if(op!='='){
				num=get_num();
				a[1]=calula(a[1],num,op);
			}
			else b[0]=op;
		}
	}
	printf("%d\n",a[0]);
	return 0;
}

