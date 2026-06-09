#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"


char s1[1000+7],op[1000+7],op2[1000+7];
int num[1000+7],num2[1000+7];

void killspace(){
    char temp[1000+7];
    strcpy(temp,s1);
    memset(s1,0,strlen(s1));int i=0,h=0;
    while(temp[i]) {
        if (temp[i] != ' ') s1[h++] = temp[i++];
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
    gets(s1);
    killspace();
    char *p=s1;

    for(int i=0,h=1;*p!=0;i+=2,h+=2){
        num[i]=atoi(p);
        while(isdigit(*p)) p++;
        op[h]=*p++;
    }

    for(int i=1,h=0;op[i]!='\0';){
        if(op[i]=='+' || op[i]=='-' || op[i]=='='){
            num2[h++]=num[i-1];
            op2[h++]=op[i];
            i+=2;
        }
        if(op[i]=='*' || op[i]=='/'){
            while(op[i]=='*' || op[i]=='/'){
                num[i+1]=operate(num[i-1],num[i+1],op[i]);
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


