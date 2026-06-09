#include <stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
int main(){
	int op;
	int data;
	while(~scanf("%d",&op)){
		if(op==-1){
			break;
		}
		if(op==1){
			scanf("%d",&data);
			top++;
			if(top==MAX){
				printf("error ");
			}
			else{
				stack[top]=data;
			}
		}
		else if(op==0){
			if(top==-1){
				printf("error ");
			}
			else{
				printf("%d ",stack[top]);
				top--;
			}
		}
	}
	return 0;
}

