/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1000 
int s[MAXSIZE];
int top;

void  push(int s[],int e);
void pop(int s[]);
int isEmpty();
int isFull();
void  initint();

int main(){
	initint();
	int f,e;
	while(~scanf("%d",&f)){
		if(f==1){
			scanf("%d",&e);
			push(s,e);
		}
		else if(f==0){
		pop(s);
		}
		else if(f==-1)
		break;
	}
	return 0;
}
void  initint(){
    top=-1;
}
int isEmpty(){
    return top==-1;
} 
int isFull(){
    return top==MAXSIZE-1;
}
void  push(int s[],int e){
    if(isFull())
    printf("error ");
    else
    s[++top]=e;
}
void pop(int s[]){
    if(isEmpty()){
    	printf("error ");
	}
    else
	printf("%d ",s[top--]);
}



