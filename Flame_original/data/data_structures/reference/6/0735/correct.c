#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000
int s[10086];
int i,flag,n;
void push(){
	if(i==100){
	    printf("error ");
	}
	else {
		scanf("%d",&n);
		s[++i]=n;
	}
}
void pop(){
	if(i!=0){
		printf("%d ",s[i--]);
	}
	else{
		printf("error ");
	}
}
int main(){
	i=0;
	scanf("%d",&flag);
	do{
		if(!flag){
		   pop();
		   scanf("%d",&flag);
		}
		else if(flag){
		   push();
		   	scanf("%d",&flag);
		}
	}while(flag!=-1);
	return 0;
} 


