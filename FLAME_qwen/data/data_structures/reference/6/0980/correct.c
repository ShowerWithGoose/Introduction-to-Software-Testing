#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

int stack[100];

int main()
{
	int op,num;
	int top=0;
	while(scanf("%d",&op)!=EOF){
		if(op==1){
			scanf("%d",&num);
			if(top==100){
				printf("error ");
			}
			else{
				stack[++top]=num;
			}
		}
		else if(op==0){
			if(top==0){
				printf("error ");
			}
			else{
				printf("%d ",stack[top--]);
			}
		}
		else if(op==-1){
			return 0;
		}
	}
	return 0;
}

