#include<stdio.h>
#include<string.h>
#define max 100 
int s[max],top=-1,number,x;
int isEmpty(){
	return top==-1;
}
int isFull(){
	return top==max-1;
}
void push(int s[],int number){
	if(isFull())
	   printf("error ");
	else 
	    s[++top]=number;
}
int pop(int s[]){
	return s[top--];
}
int main(){
    while(scanf("%d",&x),x!=-1){
    	if(x==1) {
    		scanf("%d",&number);
    		push(s,number);
		}
		else if(x==0) {
			if(isEmpty())
				printf("error ");
			else
			printf("%d ",pop(s));
		}
	}   
	return 0;
}

