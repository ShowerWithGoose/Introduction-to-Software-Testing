#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"


char ch[1000+7],op1[1000+7],op2[1000+7];
int num1[1000+7],num2[1000+7];

void killspace(){
    char temp[1000+7];
    strcpy(temp,ch);
    memset(ch,0,strlen(ch));int i=0,j=0;
    while(temp[i]) {
        if (temp[i] != ' ') ch[j++] = temp[i++];
        else i++;
    }
}

int operate(int l,int r,char op){
    if(op=='+') return l+r;
    else if(op=='-') return l-r;
    else if(op=='*') return l*r;
    else if(op=='/') return l/r;
}

int main(){
    gets(ch);
    killspace();
    char *p=ch;

    for(int i=0,j=1;*p!=0;i+=2,j+=2){
        num1[i]=atoi(p);
        while(isdigit(*p)) p++;
        op1[j]=*p++;
    }

    for(int i=1,j=0;op1[i]!='\0';){
        if(op1[i]=='+' || op1[i]=='-' || op1[i]=='='){
            num2[j++]=num1[i-1];
            op2[j++]=op1[i];
            i+=2;
        }
        if(op1[i]=='*' || op1[i]=='/'){
            while(op1[i]=='*' || op1[i]=='/'){
                num1[i+1]=operate(num1[i-1],num1[i+1],op1[i]);
                i+=2;
            }
        }
    }

    int i=1;
    while(op2[i]=='+' || op2[i]=='-'){
        num2[i+1]=operate(num2[i-1],num2[i+1],op2[i]);
        i+=2;
    }

    printf("%d",num2[i-1]);
    return 0;
}


