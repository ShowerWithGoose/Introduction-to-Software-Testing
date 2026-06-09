#include<stdio.h>
#define MAXSIZE 100;
int stack[105];
int top=-1;
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==MAXSIZE-1;
}
void push(int stack[],int item){
    if(isFull()){
        printf("error ");
    }else{
        stack[++top]=item;
    }
}
int pop(int stack[]){
    if(isEmpty()){
        printf("error ");
        return -1;

    }else{
        return stack[top--];
    }
}
int main(){
    int a,item,c;
    while(1){
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&item);
            push(stack,item);
        }else if(a==0){
            c=pop(stack);
            if(c!=-1)
            printf("%d ",c);
        }else if(a==-1) break;
    }
    return 0;
}


