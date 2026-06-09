#include<stdio.h>
int stack[100];
int p=-1,num,sign;
void pop();
void push();
int main(){
	while(~scanf("%d",&sign)){
		if(sign==-1)break;
		else if(sign==0){
			pop();
		}
		else {
			scanf("%d",&num);
			push();
		}
	}
	return 0;
}
void pop(){
	if(p==-1)printf("error ");
	else {
		printf("%d ",stack[p]);
		p--;
	}
}
void push(){
	if(p==99){
		printf("error ");
	}
	else {
		p++;
		stack[p]=num;
	}
	
	
	
}

