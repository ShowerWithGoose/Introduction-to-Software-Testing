#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int TOP=-1;
int main(){
	int op,item;
	while(~scanf("%d ",&op)){
		if(op==-1) return 0;
		else if(op==1){
			scanf("%d ",&item);
			if(TOP==99){
				printf("error ");
				continue;
			}
			TOP++;
			stack[TOP]=item;
		}
		else if(op==0){
			if(TOP==-1){
				printf("error ");
				continue;
			}
			printf("%d ",stack[TOP]);
			stack[TOP]=0;
			TOP--;
		}
	}
}

