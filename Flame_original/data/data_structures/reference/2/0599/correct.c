#include <stdio.h>

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
			switch (op2) {
				case '*':
					a2=a2*a3;
					break;
				case '/':
					a2=a2/a3;
					break;
			}
			op2=op3; 
		}
		switch (op1) {
			case '+':
				a1=a1+a2;
				break;
			case '-':
				a1=a1-a2;
				break;
		}
		op1=op2;
	}
	printf("%d",a1);
	return 0;
}

