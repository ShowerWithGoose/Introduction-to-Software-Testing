#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define maxsize 100
int s[maxsize]={0};
int top=-1;
void push(char item,int s[]){ // @@ Error: parameter type should be 'int' instead of 'char', because the value to push is an integer (e.g., 567). Using 'char' truncates the value modulo 256, causing incorrect output (e.g., 567 becomes 55).
    if(top==maxsize-1){
        printf("error ");
    }
    else{
        s[++top]=item;
    }
}
void pop(int s[]){
    if(top==-1){
        printf("error ");
    }
    else{
        printf("%d ",s[top--]);
    }
}
int main(){
    int sign,num;
    while(scanf("%d",&sign)){
        if(1==sign){
            scanf("%d",&num);
            push(num,s);
        }
        if(0==sign){
            pop(s);
        }
        if(-1==sign){
            break;
        }
    }
    return 0;
}