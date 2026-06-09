#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long

int main(void){
	int stack[101];
	int top=0,op;
	while(scanf("%d",&op)!=EOF){
		if((op==1&&top>=99)||(op==0&&!top)){
			printf("error ");
		}else if(op==1){
			scanf("%d",&op);
			stack[top++]=op;
		}else if(op==0){
			printf("%d ",stack[--top]);
		}else if(op==-1){
			break;
		}
	}
	return 0;
}
