#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int s[100]={0},t=-1;
int isEmpty(){
       return t==-1;
} 
int isFull(){
      return t==99;
}
void push(int *s){
	int x;
	scanf("%d",&x);
	s[t+1]=x;
	t++;
}
void pop(int *s){
	printf("%d ",s[t]);
	t--;
}
int main()
{
	int a=0;
	while(a!=-1){
		scanf("%d",&a);
		if(a==1){
			if(isFull()){
				printf("error ");
			}
			else{
				push(s);
			}
		}
		if(a==0){
			if(isEmpty()){
				printf("error ");
			}
			else{
				pop(s);
			}
		}
	} 
 	return 0;
}


