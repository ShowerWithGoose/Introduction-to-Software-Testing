/*
 * @Author:
 * @Date: 2022-03-03 20:44:38
 * 表达式计算（支持空格，连乘，连除）
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define MaxN 100

int read(char s[],int *i);
char getOp(char s[],int *i);
int opPriority(char op);
int calc(int a,int b,char c);

void clearSpace(char s[]){
    int i,j;
    for(i=j=0;s[i]!='\0';i++){
        if(!(s[i]==' '||s[i]=='=')) s[j++]=s[i];
    }
    s[j]='\0';
}

char s[MaxN+5];
int len;

//========= inOrder to postOrder========

char opstk[MaxN+5];
int opstkTop=0;

typedef struct{
    int cls,val;//cls=0 num , cls=1 op
}Ele;
Ele postExp[MaxN+5];
int expEnd=0;

void inToPost(){
    for(int i=1;i<=len;){
        if(isdigit(s[i])){
            int num=read(s,&i);
            Ele tmp={0,num};
            postExp[++expEnd]=tmp;
        }else{
            char op=getOp(s,&i);
            if(opstkTop==0||op=='('){
                opstk[++opstkTop]=op;
            }else{
                if(op==')'){
                    while(opstk[opstkTop]!='('){
                        Ele tmp={1,opstk[opstkTop]};
                        postExp[++expEnd]=tmp;
                        opstkTop--;
                    }
                    opstkTop--;
                }
                else{
                    while(opstkTop>0&&opPriority(op)<=opPriority(opstk[opstkTop])){
                        Ele tmp={1,opstk[opstkTop]};
                        postExp[++expEnd]=tmp;
                        opstkTop--;
                    }
                    opstk[++opstkTop]=op;
                }
            }
        }
    }
    while(opstkTop>0){
        Ele tmp={1,opstk[opstkTop]};
        postExp[++expEnd]=tmp;
        opstkTop--;
    }
}

//==========后缀计算============
int stk[MaxN+5],stkTop=0;
int postCal(){
    int ans=0;
    for(int i=1;i<=expEnd;i++){
        if(postExp[i].cls){
            int a=stk[stkTop--];
            int b=stk[stkTop--];
            stk[++stkTop]=calc(b,a,postExp[i].val);
        }else{
            stk[++stkTop]=postExp[i].val;
        }
    }
    return stk[stkTop];
}

//===========主函数============

int main(int argc, char const *argv[]){
    gets(s+1);
    clearSpace(s+1);
    //puts(s+1);
    len=strlen(s+1);

    inToPost();
    // for(int i=1;i<=expEnd;i++){
    //     if(postExp[i].cls) printf("%c ",(char)postExp[i].val);
    //     else printf("%d ",postExp[i].val);
    // }printf("\n");
    printf("%d",postCal());

    return 0;
}

//===========辅助函数===========

int read(char arr[],int *i){
    char c;
    int re=0;
    while((c=arr[(*i)++])<'0'||c>'9'); re=c-'0';
    while((c=arr[(*i)])>='0'&&c<='9'){re=(re<<3)+(re<<1)+(c-'0');(*i)++;}
    return re;
}

bool isOp(char c){
    return c=='('||c=='+'||c=='-'||c=='*'||c=='/'||c==')';
}

char getOp(char arr[],int *i){
    while(!isOp(arr[(*i)])) (*i)++;
    return arr[(*i)++];
}

int opPriority(char op){
    switch(op){
        case ')': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        case '(': return 1;
    }
    return 0;
}

int calc(int a,int b,char c){
    switch (c){
        case'+': return a+b;
        case'-': return a-b;
        case'*': return a*b;
        case'/': return a/b;
    }
    return 0;
}
