#include<stdio.h>
#include<string.h>
int main(){
	int result,num1,num2;
	char original,sign1,sign2;
	result=0; original='+';
	while(original!='='){
		scanf("%d %c",&num1,&sign1);
		while(sign1=='*'||sign1=='/'){
			scanf("%d %c",&num2,&sign2);
			if(sign1=='*') num1=num1*num2;
			else num1=num1/num2;
			sign1=sign2;
		}
		if(original=='+') result=num1+result;
		else result=result-num1;
		original=sign1;
	} 
	printf("%d", result);
	return 0;
}



