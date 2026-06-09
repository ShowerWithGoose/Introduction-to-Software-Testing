#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int TOP=-1;
int yes[1000];
void initStack(){
	TOP=-1;
}
int isEmpty(){
	return TOP==-1;
}
int isFull(){
	return TOP==MAXSIZE-1;
}
void push(int yes[],int item){
	if(isFull()){
		printf("error");
	}
	else
		yes[++TOP]=item;
}
void pop(int yes[]){
	if(isEmpty()){
		printf("error ");
	}
	else
		printf("%d ",yes[TOP--]);
}
int main(){
	int a,i=0;
	while(scanf("%d",&a)!=EOF){
		if(a==-1){
			break;
		}
		yes[i]=a;
		i++;
	}
	for(int j=0;j<i;j++){
		if(yes[j]==1){
			push(yes,yes[j+1]);
			j++;
		}
		else if(yes[j]==0){
			pop(yes);
		}
	}
	return 0;
} 

