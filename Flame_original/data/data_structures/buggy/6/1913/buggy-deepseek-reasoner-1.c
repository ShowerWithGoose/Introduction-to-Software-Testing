#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define maxsize 100
int s[maxsize]={0};
int top=-1;
void push(char item,int s[]){ // @@ Error: item should be of type 'int', not 'char', because the values pushed are integers (could be outside the char range). This type mismatch will cause truncation or incorrect storage.
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
    while(scanf("%d",&sign)){ // @@ Potential error: scanf return value may be 0 (if non-integer input) or EOF, both non-zero, causing infinite loop or undefined behavior. Better to use while(1) and check for -1 explicitly.
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