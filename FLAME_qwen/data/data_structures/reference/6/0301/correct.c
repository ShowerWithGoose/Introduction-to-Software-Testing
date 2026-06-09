#include<stdio.h>
int stack[101];
int first=-1; 
void push(int data){
	if(first<=100){
		first++;
		stack[first]=data;
	}
	else
		printf("error ");
}
void pop(){
	if(first>=0){
		printf("%d ",stack[first]);
		first--;
	}
	else{
		printf("error ");
	}
}
int main(){
	int n,data;
	while(scanf("%d",&n),n!=-1){
		if(n==1){
			scanf("%d",&data);
			push(data);
		}
		else{
			pop();
		}
	}
	return 0;
}

