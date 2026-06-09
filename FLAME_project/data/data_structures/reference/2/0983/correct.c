#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int innum(void){
	int num;
	scanf("%d",&num);
	return num;
}
char inchar(void){
	char c;
	scanf("%c",&c);
	while(c==' '){
		scanf("%c",&c);
	}
	return c;
}
int compare(char c1,char c2){
	if((c1=='*')||(c1=='/')){
		return 1;
	}
	else{
		if((c2=='+')||(c2=='-')){
			return 1;
		}
		else{
			return 0;
		}
	}
}
int calculate(int x,char c,int y){
	if(c=='+'){
		return x+y;
	}
	else if(c=='-'){
		return x-y;
	}
	else if(c=='*'){
		return x*y;
	}
	else{
		return x/y;
	}
}
int main()
{
	int num1,num2,num3,midresult;
	char ch1,ch2,chtmp;
	num1=innum();
	ch1=inchar();
	if(ch1=='='){
		printf("%d",num1);
	}
	else{
		num2=innum();
		ch2=inchar();
		if(ch2=='='){
			printf("%d",calculate(num1,ch1,num2));
		}
		else{
			num3=innum();
			chtmp=inchar();
			while(chtmp!='='){
				if(compare(ch1,ch2)==1){
					num1=calculate(num1,ch1,num2);
					ch1=ch2;
					num2=num3;
					ch2=chtmp;
					num3=innum();
				}
				else{
					num2=calculate(num2,ch2,num3);
					ch2=chtmp;
					num3=innum();
				}
				chtmp=inchar();
			}
			if(compare(ch1,ch2)==1){
				midresult=calculate(num1,ch1,num2);
				printf("%d",calculate(midresult,ch2,num3));
			}
			else{
				midresult=calculate(num2,ch2,num3);
				printf("%d",calculate(num1,ch1,midresult));
			}
		}
	}
	return 0;
}

