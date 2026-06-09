#include <stdio.h>
#include <string.h>

char arr[300];

int main(){
	int a,b,c;
	char x,y,z;int flag=0;
	a=0;
	x='+';
	while(x!='='){
	scanf("%d %c",&b,&y);
	while(y=='*'||y=='/'){
		scanf("%d %c",&c,&z);
		if(z=='='&&flag==0){
			a=c;
			break;
		}
		flag=1;
			if(y=='/'){
				b=b/c;
			}
			if(y=='*'){
				b=c*b;
			}
			y=z;
		}
		if(x=='+'){
			a+=b;
		}
		if(x=='-'){
			a-=b;
		}
		x=y;
	}
	printf("%d",a);
	return 0;
}




