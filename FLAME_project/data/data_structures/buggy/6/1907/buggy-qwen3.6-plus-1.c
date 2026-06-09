#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAXSIZE 100//储存空间初始分配量
int Top=-1; //initStack()初始化栈
int STACK[MAXSIZE];
void push(int s[],int item){
    if(Top==MAXSIZE-1)//栈满
        printf("error "); // @@ The problem requires a space after "error", but the original code only prints "error" without a space.
    else
        s[++Top]=item;//入栈
}
void pop(int s[]){
    if(Top==-1)//栈空
        printf("error "); // @@ The problem requires a space after "error", but the original code only prints "error" without a space.
    else
        printf("%d ",s[Top--]);//打印出栈元素
}
int main(){
    int sign,temp;
    while(scanf("%d",&sign)!=EOF){
        if(sign==1)//入栈
        {
            scanf("%d",&temp);
            push(STACK,temp);
        }
        else if(sign==0)//出栈
            pop(STACK);
        else if(sign==-1)
            break;
    }
}