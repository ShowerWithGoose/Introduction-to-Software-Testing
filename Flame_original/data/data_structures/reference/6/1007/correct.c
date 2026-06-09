#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define maxsize 100
int stack[maxsize];
int top=-1;
void push(int s[],int item){
	if(top==maxsize-1)
	printf("error ");
	else s[++top]=item;
}
void pop(int s[]){
	if(top==-1)
	printf("error ");
	else printf("%d ",s[top--]);
}
int main()
{
	int op,a;
	while(2){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&a);
			push(stack,a);
		}else if(op==0){
			pop(stack);
		}else if(op==-1){
			break;
		}	
	}
 	return 0;
}


