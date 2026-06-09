#include<stdio.h>
#include<string.h>
int main()
{
	int a=0,b,c;
	char op1='+',op2='+',op3;
	while(op1!='='){
		scanf("%d %c",&b,&op2);
		while(op2=='/'||op2=='*'){
			scanf("%d %c",&c,&op3);
			if(op2=='/')
			b/=c;
			if(op2=='*')
			b*=c;
			op2=op3;
		}
		if(op1=='+'){
			a+=b;
		}
		if(op1=='-'){
			a-=b;
		}
		op1=op2;
	}
	printf("%d",a);
	return 0;
}

