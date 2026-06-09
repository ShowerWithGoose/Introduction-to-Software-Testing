#include<stdio.h>
#include<string.h>
#define max 100 
int s[max],top=-1,number,number;
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
    while(scanf("%d",&number),number!=-1){
    	if(number==1) {
    		scanf("%d",&number);
    		push(s,number);
		}
		else if(number==0) {
			if(isEmpty())
				printf("error ");
			else
			printf("%d ",pop(s));
		}
	}   
	return 0;
}

