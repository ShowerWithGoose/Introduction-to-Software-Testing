/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1000 
int s[MAXSIZE];
int top;

void  push(int s[],int item);
void pop(int s[]);
int isEmpty();
int isFull();
void  initint();

int main(){
	initint();
	int d,item;
	while(~scanf("%d",&d)){
		if(d==1){
			scanf("%d",&item);
			push(s,item);
		}
		else if(d==0){
		pop(s);
		}
		else if(d==-1)
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
void  push(int s[],int item){
    if(isFull())
    printf("error ");
    else
    s[++top]=item;
}
void pop(int s[]){
    if(isEmpty()){
    	printf("error ");
	}
    else
	printf("%d ",s[top--]);
}



