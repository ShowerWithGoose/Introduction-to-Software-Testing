#include <stdio.h>
int stack[200];
int top=0;
void push(){
	if(top>100){
		printf("error ");
		return ;
	}
	int k;
	scanf("%d",&k);
	stack[top++]=k;
}
int pop(){
	if(top<=0){
		printf("error ");
		return -1;
	}
	return stack[--top];
}
int main(){
	int n;
	while((scanf("%d",&n)!=-1)){
		if(n==1){
			push();
		}
		if(n==0){
			int y;
			y=pop();
			if(y!=-1)
			printf("%d ",y);
		}
	}
	
	return 0;
}



