#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int a[100],top=-1,key;
int isEmpty(){
	return top==-1;
}
int isFull(){
	return top==99;
}

int main(){
	scanf("%d",&key);
	while(key!=-1){
		if(key==1){
			scanf("%d",&key);
			if(isFull()){
				printf("error ");
			}
			else{
				a[++top]=key;
			}
		}
		else{
			if(isEmpty()){
				printf("error ");
			}
			else{
				printf("%d ",a[top--]);
			}
		}
		scanf("%d",&key);
	}
	
	return 0;
}


