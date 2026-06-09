#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define maxsize 100
int s[maxsize]={0};
int top=-1;
void push(char item,int s[]){ @@ // The parameter 'item' is declared as 'char', but it should be 'int' to match the integer values being pushed onto the stack. This causes incorrect storage and potential data truncation.
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
            push(num,s); @@ // Passing an 'int' (num) to a function expecting a 'char' for 'item' leads to implicit conversion and possible loss of data. This is due to the incorrect function signature of 'push'.
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