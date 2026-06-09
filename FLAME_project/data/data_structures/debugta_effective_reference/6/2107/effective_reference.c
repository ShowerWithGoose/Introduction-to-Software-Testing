#include<stdio.h>
#include<string.h>
int a[100];
int top = -1;
int isEmpty(){
	return top == -1;
}
int isFull(){
	return top == 99;
}
void push(int a[],int m){
	if(isFull()){
		printf("error ");
	}
	else{
		a[++top] = m;
	}
}
int pop(int a[]){
	if(isEmpty()){
		printf("error ");
	}
	else{
		return a[top--];
	}
}
int main(){
	int n,m;
    while(n!=-1){
    	scanf("%d",&n);
    	if(n==1){
    		scanf("%d",&m);
    		push(a,m);
		}
		else if(n==0){
			if(top != -1){
				printf("%d ",a[top]);
		    	pop(a);
			}
			else{
				pop(a);
			}
		}
		else if(n==-1){
			break;
		}
	}
	return 0;
}

