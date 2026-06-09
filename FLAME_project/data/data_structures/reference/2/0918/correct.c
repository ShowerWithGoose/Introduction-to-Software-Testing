#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n1,n2,n3;
	char op1,op2,op3;
	n1=0;
	op1='+';
	while(op1!='=')
	{
		scanf("%d %c",&n2,&op2);
		while(op2=='*'||op2=='/')
		{
			scanf("%d %c",&n3,&op3);
			if(op2=='*')
			{
				n2*=n3;
			}
			if(op2=='/')
			{
				n2/=n3;
			}
			op2=op3;
		}
		if(op1=='+')
		{
			n1+=n2;
		}
		else if(op1=='-')
		{
			n1-=n2;
		}
		op1=op2;
	}
	printf("%d",n1);
	return 0;
} 

