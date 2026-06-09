#include<stdio.h>
#include<string.h>
int s[100];
int top = -1;
int isEmpty(){
	return top == -1;
}
int isFull(){
	return top == 99;
}
void push(int s[],int n){
	if(isFull()){
		printf("error ");
	}
	else{
		s[++top] = n;
	}
}
int pop(int s[]){
	if(isEmpty()){
		printf("error ");
	}
	else{
		return s[top--];
	}
}
int main(){
	int m,n;
    while(m!=-1){
    	scanf("%d",&m);
    	if(m==1){
    		scanf("%d",&n);
    		push(s,n);
		}
		else if(m==0){
			if(top != -1){
				printf("%d ",s[top]);
		    	pop(s);
			}
			else{
				pop(s);
			}
		}
		else if(m==-1){
			break;
		}
	}
	return 0;
}

