#include <stdio.h>

int stack[103]={};
int *top=stack-1;

void insert(int num){
	if((int)(top-stack)>98){
		printf("error ");
		return;
	}
	*(++top)=num;
	return;
}

void pop(){
	if(top<stack){
		printf("error ");
		return;		
	}
	printf("%d ",*(top--));
	return;
}

int main(){
	int num;
	while(scanf("%d",&num)&&num!=-1){
		if(num==0) pop();
		else if(num==1){
			scanf("%d",&num);
			insert(num);
		}
	}
	
	return 0;
}

