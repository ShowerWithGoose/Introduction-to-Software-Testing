#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char x,y,z;
int a,b,c;
int main(){	
	a=0;
	x='+';
	while(1){		
		scanf("%d %c",&b,&y);
		while(y=='*'||y=='/'){
			scanf("%d %c",&c,&z);
			if(y=='*')
				b=b*c;
			else
				b=b/c;
			y=z;

		}
		if(x=='+')
			a=a+b;
		else
			if(x=='-')
				a=a-b;
		x=y;
		if(x=='='){
			printf("%d\n",a);
			break;			
		}
	}
	return 0;
}


