#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char op1='+',op2,op3;
	int x1=0,x2,x3;
	while(op1!='=')
    {
        scanf("%d %c",&x2,&op2); 
		       	
			while(op2=='*'||op2=='/')//ÓÐµã±ðÅ¤£¿ 
        	{
        		scanf("%d %c",&x3,&op3);
        		if(op2=='*')
                    x2=x2*x3;
                else if(op2=='/')
                    x2=x2/x3;
                op2=op3;
			}
		     
        if(op1=='+')
            x1=x1+x2;
        else if(op1=='-')
            x1=x1-x2;
		op1=op2;
    }
    printf("%d",x1);
    return 0;
}

