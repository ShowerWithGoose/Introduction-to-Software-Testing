#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int Top=-1; 
void push(int s[], int item)
{
    if(Top == MAXSIZE-1)
        printf("error ");
    else
        s[++Top]=item;
}
int pop(int s[])
{
      if(Top <= -1){
        printf("error ");
	  }
      if(Top>=0){
      	printf("%d ",s[Top]);
      	Top--;
	  }
	  return 0;
}
int main(){
    int x,y;
    scanf("%d",&x);
    while(x!=-1){
        if(x==1){
            scanf("%d",&y);
            push(STACK,y);
        }
        if(x==0){
        	pop(STACK);
        }
        scanf("%d",&x);
    }
    return 0;
}











