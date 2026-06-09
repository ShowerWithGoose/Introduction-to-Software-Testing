#include<stdio.h>
int homo(int a,int b,char op){
	int sum;
	if(op=='+'){
		sum=a+b;
	}
	else if(op=='-'){
		sum=a-b;
	}
	else if(op=='*'){
		sum=a*b;
	}
	else if(op=='/'){
		sum=a/b;
	}
	return sum;
}
int getNUM(){
	int num;
	scanf(" %d",&num);
	return num;
}
char getOP(){
	char op;
	scanf(" %c",&op);
	return op;
}
int main(){
	int k,sum,a[2];
	char op,b[1];
	a[0]=getNUM();
	b[0]=getOP();
	if(b[0]!='='){
		a[1]=getNUM();
	}
	while(b[0]!='='){
		if(b[0]=='/'||b[0]=='*'){
			a[0]=homo(a[0],a[1],b[0]);
			b[0]=getOP();
			if(b[0]!='='){
				a[1]=getNUM();
			}
		}
		else{
			op=getOP();
			if(op=='/'||op=='*'){
				k=getNUM();
				a[1]=homo(a[1],k,op);
			}
			else if(op=='+'||op=='-'){
				a[0]=homo(a[0],a[1],b[0]);
				b[0]=op;
				a[1]=getNUM();
			}
			else{
				a[0]=homo(a[0],a[1],b[0]);
				b[0]=op;
			}
		}
	}
	printf("%d\n",a[0]);
	return 0;
}

