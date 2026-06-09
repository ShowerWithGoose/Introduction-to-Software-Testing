#include<stdio.h>
int main() {
	int S=0,a,b;
	char op='+',op1,op2;
	while(op!='=') {
		scanf("%d %c",&a,&op1);
		while(op1=='*'||op1=='/') {
			scanf("%d %c",&b,&op2);
			if(op1=='*') a*=b;
			if(op1=='/') a/=b;
			op1=op2;
		}
		if(op=='+') S+=a;		
		if(op=='-') S-=a;
		op=op1;		
	}
	printf("%d",S);
	return 0;
}



