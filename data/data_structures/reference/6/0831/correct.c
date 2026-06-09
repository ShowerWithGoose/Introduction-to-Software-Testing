#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define pi acos(-1)
#define eps 1e-8
int isForE();
void push(int x);
int pop();

int stack[100];
int opreation;
int num;
int top;
int bottom;
int main(){
    top=-1;

    while(1){
        scanf("%d",&opreation);
        if(opreation==-1)
            break;
        else {
            if(opreation==1){
                scanf("%d",&num);
                push(num);
            }
            else if(opreation==0) {
                if(isForE()==-1)
                    printf("error ");
                else  printf("%d ", pop());
            }
        }
    }

    return 0;
}
int isForE(){
    int a=top==-1;
    int b=top==99;
    if (a==1) return -1;
    if(b==1) return 1;
    return 0;
}
void push(int x){
    if(isForE()==1)
        printf("error ");
    else {
        stack[++top]=x;
    }
}
int pop(){
    
        return stack[top--];

}

