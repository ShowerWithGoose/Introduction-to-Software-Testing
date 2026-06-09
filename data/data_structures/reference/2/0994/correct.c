#include<stdio.h>

#include<string.h>

#include<stdlib.h>

int  Calculation(int  num1,char op,int  num2);

int main(){
	
	int  date,date1,date2;
	char op1,op2,op;
	scanf("%d %c",&date1,&op1);
	while(op1!='='){
		while(op1=='*'||op1=='/'){
			scanf("%d %c",&date2,&op2);
			date1=Calculation(date1,op1,date2);
			op1=op2;
		}
		if(op1=='=')	
			break;
		scanf("%d %c",&date2,&op2);
		while(op2=='*'||op2=='/'){
			scanf("%d %c",&date,&op);
			date2=Calculation(date2,op2,date);
			op2=op;
		}
		date1=Calculation(date1,op1,date2);
		op1=op2;
	}
	printf("%d\n",date1);
	
	return 0;
}

int  Calculation(int  num1,char op,int  num2){
	
	if(op=='+'){
		
		return num1+num2;
	}
	else if(op=='-'){
		
		return num1-num2;	
	}
	else if(op=='*'){
		
		return num1*num2;
	}
	else{
		
		return num1/num2;
	}

}

