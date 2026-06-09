#include<stdio.h>
void push(int s[],int item);
void pop(int s[]);
int top=-1;
int main(){
	int stack[100],x,y;
	scanf("%d ",&x);
	while(x!=-1)
	{
		if(x==1){
			scanf("%d ",&y);
			push(stack,y);
		}
		else if(x==0){
			pop(stack);
		}
		scanf("%d ",&x);
	}
	return 0;
}
void push(int s[],int item){
	if(top==99){
		printf("error ");
	}
	else{
		s[++top]=item;
	}
}
void pop(int s[]){
	if(top==-1){
		printf("error ");
	}
	else{
		printf("%d ",s[top--]);
	}
}

