#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
int main(){
	int op,a[105],top=-1;
	do{
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&a[top+1]);
			if(top!=99){
				top++;
			}
			else{
				printf("error ");
			}	
		}
		if(op==0){
			if(top!=-1){
				printf("%d ",a[top]);
				top--;
			}else{
				printf("error ");
			}
		}
	}while(op!=-1);
	return 0;
}


