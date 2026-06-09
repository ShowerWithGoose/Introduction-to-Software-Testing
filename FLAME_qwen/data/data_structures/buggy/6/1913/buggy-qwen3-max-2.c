#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define maxsize 100
int s[maxsize]={0};
int top=-1;
void push(char item,int s[]){ @@ [The parameter 'item' is declared as 'char', but it should be 'int' to match the integer values being pushed onto the stack. This causes incorrect data handling when pushing integers larger than a char can hold.]
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
    while(scanf("%d",&sign)){ @@ [The loop condition 'while(scanf("%d",&sign))' does not properly handle the end-of-input or invalid input scenarios. scanf returns the number of successfully read items; it should check for ==1 to ensure an integer was read. However, given the problem context and test case ending with -1, this may not be the primary error. The main issue is the 'char' type in push.]
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