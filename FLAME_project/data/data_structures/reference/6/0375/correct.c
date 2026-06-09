#include <stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;
int isFull(){
	return top==MAXSIZE;
}
int isEmpty(){
	return top==-1;
}
void push(int b){
	if (isFull()){
		printf("error ");
	}
	else stack[++top] = b;
	return;
}

/*int pop(){
	int m=0;
	if (isEmpty()){
		printf("error ");
		
	}
	else m=stack[top--];
	return m;
}*/
int main(){
	int flag=0, a;
	do{
		scanf("%d", &flag);
		//printf("%d", top);
	if (flag==1){
		scanf("%d", &a);
		push(a);
	}
	else if (flag==0){
		if (isEmpty()){
		printf("error ");
		}
		else printf("%d ", stack[top--]);
		}
		
	
	}while (flag != -1);
	
	return 0;
}

