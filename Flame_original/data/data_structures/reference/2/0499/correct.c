#include <stdio.h>
#include <string.h>
#define M 1000

char cal[M];
int calstack[3];
int ptr,stackptr;

void blankkiller(char*str,char*dis){
    int i=0,j=0;
    for(;i<strlen(str);i++){
        if(str[i]==' ') continue;
        else dis[j++]=str[i];
    }
    return;
}

int readnum(){
    int num=0;
    while(cal[ptr]>='0'&&cal[ptr]<='9')
        num=num*10+cal[ptr++]-'0';
    return num;
}

void sumup(){
    calstack[0]+=calstack[2]*calstack[1];
    stackptr=2;
    calstack[2]=0;
    return;
}

int main(){
    char str[M];
    gets(str);
    blankkiller(str,cal);
    while(ptr<strlen(cal)){
        if(cal[ptr]>='0'&&cal[ptr]<='9') calstack[stackptr]+=readnum();
        if(cal[ptr]=='*'){
            ptr++;
            calstack[stackptr]*=readnum();
    }
        if(cal[ptr]=='/'){
            ptr++;
            calstack[stackptr]/=readnum();
    }
        if(cal[ptr]=='='){
            sumup();
            break;
        }
        if(cal[ptr]=='+'){
            if(stackptr==0){
                calstack[1]=1;
                stackptr=2;
            }
            else{
                sumup();
                calstack[1]=1;
            }
            ptr++;
        }
        if(cal[ptr]=='-'){
            if(stackptr==0){
                calstack[1]=-1;
                stackptr=2;
            }
            else{
                sumup();
                calstack[1]=-1;
            }
            ptr++;
        }
    }
    printf("%d",calstack[0]);
    return 0;
}





