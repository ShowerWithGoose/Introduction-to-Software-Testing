#include<stdio.h>
int stack[100];
int top=-1;
int main(){
	int op,num;
	scanf("%d",&op);
	while(op!=-1){
		if(op==1){
			scanf("%d",&num);
			if(top==99){
				printf("error ");
			}
			else{
				stack[++top]=num;
			}
		}
		if(op==0){
			if(top==-1){
				printf("error ");
			}
			else{
				printf("%d ",stack[top--]);
			}
		}
		scanf("%d",&op);
	}
	return 0;
}

