#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef int dataType;

typedef struct Stack{
	dataType* stackMemory;
	int stackSize;
	int stackTop;
}stack;

int main()
{
	stack* pStack = (stack*)malloc(sizeof(stack));
	pStack->stackMemory = (dataType*)malloc(sizeof(dataType) * MAX);
	pStack->stackSize = 0;
	pStack->stackTop = -1;
	int n = 10,data;
	while(n != -1){
		scanf("%d",&n);
		if(n == 1){//push
			if(pStack->stackSize >= MAX)
				printf("error ");
			else{
				scanf("%d",&data);
				pStack->stackTop++;
				pStack->stackMemory[pStack->stackTop] = data;
				pStack->stackSize++;
			}
		}
		else if(n == 0){//pop
			if(pStack->stackSize == 0){
				printf("error ");
			}
			else{
				printf("%d ",pStack->stackMemory[pStack->stackTop]);
				pStack->stackTop--;
				pStack->stackSize--;
			}
		}
	}
	return 0;
}

