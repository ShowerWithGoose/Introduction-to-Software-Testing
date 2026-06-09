#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int data[100];
int top;

int isfull(){
    return top == 99;
}

int isempty(){
    return top == -1;
}

int pop(){
    int tem = data[top];
    data[top] = 0;
    top--;
    return tem;
}

int insert(int a){
    data[top+1] = a;
    top++;
}

int main(){
    top = -1;
    int op = 0,recpop = 0,data_insert = 0;
    while(scanf("%d",&op)){
        if(-1 == op){
            break;
        }
        else if(1 == op){
            scanf("%d",&data_insert);
            if(isfull() != 1){
                insert(data_insert);
            }
            else{
                printf("error ");
            }
        }
        else if(0 == op){
            if(isempty() == 1){
                printf("error ");
            }
            else if(isempty() != 1){
                recpop = pop();
                printf("%d ",recpop);
            }
        }
    }
    printf("\n");
    return 0;
}
