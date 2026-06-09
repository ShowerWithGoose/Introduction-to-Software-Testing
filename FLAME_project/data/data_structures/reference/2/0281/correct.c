#include<stdio.h>
#include<string.h>
#include<math.h>
int judgenumber(){
	int num;
	scanf(" %d",&num);  //为什么一定要有这个空格？ 
	return num;
}
char judgeOp(){
	char op;
	scanf(" %c",&op);
	return op;
}
int calculation(int x,int y,char op){
	int temp;
	if (op == '+')
		temp = x + y;
	else if (op == '-')
		temp = x - y;
	else if (op == '*')
		temp = x * y;
	else
		temp = x / y;
	return temp;
}
int main(){
	int a[2];
	char b[1];
	int num;
	char op;
	a[0]=judgenumber();
	b[0]=judgeOp();
	if(b[0]!='='){
		a[1]=judgenumber();
	}
	while(b[0]!='='){
		if(b[0]=='*'||b[0]=='/'){
			a[0]=calculation(a[0],a[1],b[0]);
			b[0]=judgeOp();
			if(b[0]!='=')
			a[1]=judgenumber();
		}
		else{
			op=judgeOp();
			if(op == '+' || op == '-' || op == '=')
			{
			a[0]=calculation(a[0],a[1],b[0]);
			b[0]=op;
			if(op!='=')
			a[1]=judgenumber();
			}
			else if(op!='='){
				num=judgenumber();
				a[1]=calculation(a[1],num,op);
			}
			else b[0]=op;
			
		}
	}
	printf("%d",a[0]);
	return 0;
}
	

