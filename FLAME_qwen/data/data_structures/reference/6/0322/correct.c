#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
int stack[maxsize];
int top;

void init(){
    top=-1;
}
void error(char s[]){
    printf("%s",s);
    //exit(-1);//非正常运行，并退出程序！！
}
int isempty(){//检测，栈空返1
    if(top==-1)
        return 1;
    return 0;
}
int isfull(){//检测，栈满返1
    if(top==maxsize-1)
        return 1;
    return 0;
}
void push(int a[],int b){//入栈
    if(isfull()==1){
        error("error ");
    }
    else{
        top++;
        a[top]=b;
    }
}
int pop(int a[]){//出栈
    if(isempty()==1){
        error("error ");
        //memset(a,0,maxsize);
        return EOF;//必须带return。若不带就需exit(-1)，但会破坏循环
    }
    else{
        return a[top--];//返回原top对应项后，top前移一位
    }
}

int main(){
    int n=0,m=0,i=0;
    init();
    while(~scanf("%d",&n)){
        if(n==1){//入栈
            scanf("%d",&m);//再输入要录入的元素
            push(stack,m);
        }
        else if(n==0){//出栈
            i=pop(stack);
            if(i!=EOF)
                printf("%d ",i);
        }
        else if(n==-1)
            break;
    }
    return 0;
}
