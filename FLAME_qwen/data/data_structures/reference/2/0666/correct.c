#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int number1,number0=0,number2;
	char char0='+',char1,char2;
	scanf("%d %c",&number1,&char1);
	while(char0!='='){
		while(char1=='*'||char1=='/'){
		scanf("%d %c",&number2,&char2);
		if(char1=='*') number1*=number2;
		else number1/=number2;
		char1=char2;}
	
	if(char0=='+') number0+=number1;
	else if(char0=='-') number0-=number1;
	
	char0=char1;
	scanf("%d %c",&number1,&char1);
}
    printf("%d",number0);
    return 0;
}


