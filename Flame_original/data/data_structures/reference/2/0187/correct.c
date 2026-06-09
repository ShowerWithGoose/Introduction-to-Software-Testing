#include<stdio.h>
int readshu()
{
	int a;
	scanf("%d",&a);
	return a;
}
char readop()
{
	int c;
	scanf(" %c",&c);
	return c;
}
int cal(int a,int b,char c){
	if(c=='+')
	return a+b;
	if(c=='-')
	return a-b;
	if(c=='*')
	return a*b;
	if(c=='/')
	return a/b;
}
int bj(char op1,char op2)
{
	if(op1=='*'||op1=='/')
	return 1;
	else if(op2=='*'||op2=='/')
	return 0;
	else return 1;
}
int main()
{
	int shu1=readshu();
	char op1=readop();
	if(op1=='=') printf("%d",shu1);
	else{
		int shu2=readshu();
		char op2=readop();
		if(op2=='=') printf("%d",cal(shu1,shu2,op1));
		else{
			int shu3=readshu();
			while(1){
				if(bj(op1,op2))
				{
					shu1=cal(shu1,shu2,op1);
					shu2=shu3;
					op1=op2;
				}
				else shu2=cal(shu2,shu3,op2);
				op2=readop();
				if(op2=='=') break;
				shu3=readshu();
			}
			printf("%d",cal(shu1,shu2,op1));
		}
		
	}
	return 0;
}
 

