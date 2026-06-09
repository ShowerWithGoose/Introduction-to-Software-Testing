#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int stack[200]= {0};
	int top=-1;
	int a=0,b=0;
	while((a=getchar())!='-') {
		if(a=='1') {
			scanf(" %d",&b);
			if(top==99) {
				printf("error ");
			}
			else {
				top++;
				stack[top]=b;
			}
		}
		else if(a=='0') {
			if(top < 0){
				printf("error ");
			}
			else {
				printf("%d ",stack[top]);
				top--;
			}
		}
	}
	scanf("%d",&a);
	return 0;
}


