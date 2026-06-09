#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
int STACK[MAXSIZE],top=-1;
int STACKfull(){
	return (top==MAXSIZE-1)?1:0;//1Âú
}
int STACKempty(){
	return (top==-1)?1:0;
}
int main()
{
	int op,item;
	while (~scanf("%d",&op)){
		if (op==-1)
			break;
		else if (op==1){
			scanf("%d",&item);
			if (STACKfull())
				continue;
			else
				STACK[++top]=item;	
		}
		else if(!op){
			if (STACKempty()){
				printf("error ");
				continue;
			}
			else
				printf("%d ",STACK[top--]);
		}
	}
	return 0;
}

