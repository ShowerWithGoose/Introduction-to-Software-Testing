#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 100
int STACK[M];
int top=-1;
int Emptys(int top){
    return top==-1;
}
int Full(int top){
    return top==M-1;
} 
int PUSH(int STACK[],int *top,int item){
    if(Full(*top))
        return 0;
    else{
        STACK[++*top]=item;
        return 1;
    }
}
int POP(int STACK[],int *top){
    if(Emptys(*top))
        return 0;
    else{
        printf("%d ",STACK[(*top)--]);
        return 1;
    }
}
int main(){
    int a,b;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            scanf("%d",&b);
            if(PUSH(STACK,&top,b)==0)
                printf("error ");
        }
        else if(a==0){
            if(POP(STACK,&top)==0)
                printf("error ");
        }
        else
            break;
    }
    
    return 0;
}
