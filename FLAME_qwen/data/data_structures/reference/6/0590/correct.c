#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;int stack[100];
int main(){
int n=0,x=0;
while(1){
    scanf("%d",&n);
    if(n==-1){
        break;
    }
    if(n==1)
    {
    scanf("%d",&x);} if(n==1){
 if(top==100){
    printf("error ");
 } else
    stack[++top]=x;
    }
    else{
        if(top==-1){
            printf("error ");
        }else{printf("%d ",stack[top--]);
        }
}




}






return 0;}

