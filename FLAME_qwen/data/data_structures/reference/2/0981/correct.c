#include<stdio.h>
int main()
{
	int a1=0,a2,a3;
	char op1='+',op2,op3;
	while(op1!='=')
	{
		scanf("%d %c",&a2,&op2);
		
		while(op2=='*'||op2=='/')
		{
			scanf("%d %c",&a3,&op3);
			if(op2=='*')
				a2*=a3;
			if(op2=='/')
				a2/=a3;
			op2=op3;
		}
		if(op1=='+')
			a1+=a2;
	    if(op1=='-')
	    	a1-=a2;
	 	op1=op2;
	}
	printf("%d",a1);
	return 0;
}

