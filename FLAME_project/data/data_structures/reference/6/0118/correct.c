#include<stdio.h>

int main(){
	int stack[99];
	int top=-1;
	int op,data;
	while(scanf("%d",&op)){
		if(op==-1)break;
		if(op==1){
			scanf("%d",&data);
			if(top==100)printf("error ");
			else stack[++top]=data;
		}
		if(op==0){
			if(top==-1)printf("error ");
			else{
				printf("%d ",stack[top]);
				stack[top--]=0;
			}
		}
	}
	return 0;
}

