//
//  main.c
//  DS4-1
//
//  Created by  on 2022/4/14.
//

#include <stdio.h>
#define MAXSIZE 100
int s[105];//栈
int count=0;
int top=-1;

void StackPush(int x){
    if(top==MAXSIZE-1){
        printf("error ");
        return;
    }
    top++;
    s[top]=x;
    return;
}
void StackPop(int y){
    int x;
    if(top==-1){
        printf("error ");
        return;
    }
    x=s[top];
    top--;
    printf("%d ",x);
    return;
}
int main() {
    int a[300];//暂存数组;
    int x;
    int i=0,n=0;
    while((scanf("%d",&a[i]))!=EOF)
        i++;
    n=i;
    for(i=0;i<n;i++){
        if(a[i]==-1)
            break;
        else if(a[i]==1){
            x=a[i+1];
            StackPush(x);
            i++;
        }
        else if(a[i]==0){
            StackPop(0);
        }
    }
   
    
    return 0;
}
//栈的最大容量为100
//栈操作：1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素；0表示出栈操作；-1表示操作结束
//如果栈状态为空时进行出栈操作，或栈满时进行入栈操作，则输出字符串“error”，并且字符串后也要有一空格。所有操作都执行完后，栈也有可能不为空。
//


