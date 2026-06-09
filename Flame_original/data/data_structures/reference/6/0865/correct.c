#include<stdio.h>
void push(int n);
void pop();
int stack[105],top=-1;
int main(){
    int dowhat,num;
    scanf("%d",&dowhat);
    while(dowhat!=-1){
        if(dowhat==1){
            scanf("%d",&num);
            push(num);
        }
        else if(dowhat==0){
            pop();
        }
        scanf("%d",&dowhat);
    }
    return 0;
}

void push(int n){
    if(top==99) printf("error ");
    else{
        top++;
        stack[top]=n;
    }
    return ;
}
void pop(){
    if(top==-1) printf("error ");
    else{
        printf("%d ",stack[top]);
        top--;
    }
}
