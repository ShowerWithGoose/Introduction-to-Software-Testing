#include<stdio.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int top=-1;
int isEmpty(){
     if (top==-1)
     return 1;
     else return 0;
}
int isFull(){
     if(top==MAXSIZE-1)
        return 1;
     else return 0;
}
void push(int s[],int item){
      if(isFull()!=0)
        printf("error ");
      else
        s[++top]=item;
}
int pop(int s[]){
      if(isEmpty()!=0)
        printf("error ");
      else
        printf("%d ",s[top--]);
}
int main(){
    int a=0;
    int b;
    while(a!=-1)
    {
        scanf("%d",&a);
        if(a==-1)
            break;
        else if(a==1)
        {
            scanf("%d",&b);
            push(STACK,b);
        }
        else if(a==0)
        {
            pop(STACK);
        }
    }
    return 0;
}

