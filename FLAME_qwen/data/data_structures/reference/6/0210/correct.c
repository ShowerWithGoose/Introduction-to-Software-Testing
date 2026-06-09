#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	int *sta;
	int base;
	int top;
}stack;

int main(){
	stack mysta;
	mysta.sta=(int*)malloc(sizeof(int)*100);
	mysta.base=0;
	mysta.top=0;
	int op;
	scanf("%d",&op);
	do{
		if(op == 1){
			int ele;
			scanf("%d",&ele);
			mysta.sta[mysta.top++] = ele;
		}else if(op == 0){
			if(mysta.base == mysta.top){
				printf("error ");
			}else{
				int t = mysta.sta[--(mysta.top)];
				printf("%d ",t);
			}
		}
		scanf("%d",&op);
	}while(op != -1);
	return 0;
}

