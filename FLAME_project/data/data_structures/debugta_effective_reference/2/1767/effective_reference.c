#include <stdio.h>
int main ()
{
	int sum,x,y;
	char op1,op2,op3;
	scanf("%d%c",&sum,&op1);
	while(op1==' ')
	scanf("%c",&op1);
	if(op1!='=')
	{
	do {
	scanf("%d%c",&x,&op2);
	while(op2==' ')
	scanf("%c",&op2);
	if(op1=='*')
	sum=sum*x;
	else if(op1=='/')
	sum=sum/x;//如果是乘除就直接运算 
	else if(op2=='*'||op2=='/')//先做乘除 
	{
		do {
		scanf("%d%c",&y,&op3);
		while(op3==' ')
	    scanf("%c",&op3);
	    if(op2=='*')
	    x*=y;
	    if(op2=='/')
	    x/=y;
	    op2=op3;
	    }while(op3=='*'||op3=='/');
	}
	if(op1=='+')
	sum+=x;
	if(op1=='-')
	sum-=x;
	op1=op2;
    }while(op2!='=');
    }
    printf("%d",sum);
	return 0;
}
    

