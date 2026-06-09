#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100
int s[SIZE];
int top=-1;
int isempty(){
	return top==-1;
}
int isfull(){
	return top==SIZE-1;
} 
int main()
{
	int op,a;
	while(~scanf("%d",&op)){
		if(op==-1) break;
		if(op==1){
			scanf("%d",&a);
			if(isfull()) printf("error ");
			else s[++top]=a;
		}
		if(op==0){
			if(isempty()) printf("error ");
			else printf("%d ",s[top--]);
		}
	}
	return 0;
}




