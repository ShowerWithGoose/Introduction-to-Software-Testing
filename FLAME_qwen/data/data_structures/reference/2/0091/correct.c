#include <stdio.h>
int main ()
{
	int data1,data2,data3;
	char op1,op2,op3;
	scanf("%d%c",&data1,&op1);
	while(op1==' ')
	scanf("%c",&op1);
	if(op1!='=')
	{
	do {
	scanf("%d%c",&data2,&op2);
	while(op2==' ')
	scanf("%c",&op2);
	if(op1=='*')
	data1=data1*data2;
	else if(op1=='/')
	data1=data1/data2;//如果是乘除就直接运算 
	else if(op2=='*'||op2=='/')//先做乘除 
	{
		do {
		scanf("%d%c",&data3,&op3);
		while(op3==' ')
	    scanf("%c",&op3);
	    if(op2=='*')
	    data2*=data3;
	    if(op2=='/')
	    data2/=data3;
	    op2=op3;
	    }while(op3=='*'||op3=='/');
	}
	if(op1=='+')
	data1+=data2;
	if(op1=='-')
	data1-=data2;
	op1=op2;
    }while(op2!='=');
    }
    printf("%d",data1);
	return 0;
}
    

