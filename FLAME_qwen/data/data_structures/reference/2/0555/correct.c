#include<stdio.h>
#include<string.h>
int main()
{
	int num1=0,num2=0,num3,i=0;
	char c1='+',c2,c3;
    for( i=0;i<100;i++){
		scanf("%d %c",&num2,&c2);
		while(c2=='*'||c2=='/'){
			scanf("%d %c",&num3,&c3);
			if(c2=='*'){
				num2=num2*num3;
			}
			else{
				num2=num2/num3;
			}
			c2=c3;
		}
		if(c1=='+'||c1=='-'){
			if(c1=='+'){
				num1=num1+num2;
			}
			else{
				num1=num1-num2;
			}
		}
		c1=c2;
		if(c1=='='){
			printf("%d",num1);
			return 0;
		}
	}
 } 



