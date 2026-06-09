#include <stdio.h>
int main(){
	int a,b,c;
	char A,B,C;
	a=0;
	A='+';
	
	
	while(A!='=')
	{
		scanf("%d %c",&b,&B);
		while(B=='*'||B=='/'){
			scanf("%d %c",&c,&C);
			if(B=='*'){
				b=b*c;
			}else if((B=='/')){
				b=b/c;
			}
			B=C;
		}
		if(A=='+'){
			a=a+b;
			
		}else if(A=='-'){
			a=a-b;
			
		}
		A=B;
		
		
	}
	printf("%d",a);
	return 0;
}



