/*
 * @Author:
 * @Date: 2022-03-03 23:12:20
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define MaxN 100000

char s[MaxN+5];
int len,dot,begin;

int main(int argc, char const *argv[]){
    gets(s+1);
    len=strlen(s+1);

    bool mark=false;
    for(int i=1;i<=len;i++){
        if(s[i]=='.') dot=i;
        if(!mark&&isdigit(s[i])&&s[i]!='0'){mark=true;begin=i;} 
    }

    if(begin==len){
        printf("%ce%d",s[begin],dot-begin);
    }else{
        printf("%c.",s[begin]);
        for(int i=begin+1;i<=len;i++){
            if(s[i]!='.') printf("%c",s[i]);
        }
        printf("e%d",dot-begin-(dot-begin>0));
    }
    
    
    return 0;
}
