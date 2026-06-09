#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int s[MAXSIZE];
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
    int x,n;
    scanf("%d",&x);
    while(x!=-1){
        if(x==1){
            scanf("%d",&n);
            push(s,n);
        }
        if(x==0){
        	pop(s);
        }
        scanf("%d",&x);
    }
    return 0;
}











