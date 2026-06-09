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
	int n;
	scanf("%d",&n);
	do{
		if(n == 1){
			int m;
			scanf("%d",&m);
			mysta.sta[mysta.top++] = m;
		}else if(n == 0){
			if(mysta.base == mysta.top){
				printf("error ");
			}else{
				int t = mysta.sta[--(mysta.top)];
				printf("%d ",t);
			}
		}
		scanf("%d",&n);
	}while(n != -1);
	return 0;
}

