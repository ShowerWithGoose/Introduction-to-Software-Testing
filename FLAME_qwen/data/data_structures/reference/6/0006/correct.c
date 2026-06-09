#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define FEqual(a,b,eps) (fabs((a)-(b))<(eps)) 

#define M 100

int stack[M], top=-1;
int temp1, temp2;

int main(){
	while(scanf("%d", &temp1),temp1!=-1){
		switch(temp1){
			case 1:
				scanf("%d", &temp2);
				if(top==M-1){
					printf("error ");
				}else{
					stack[++top]=temp2;
				}break;
			case 0:
				if (top==-1){
					printf("error ");
				}else{
					printf("%d ", stack[top--]);
				}break;
		}
	}
	
	return 0;
}





