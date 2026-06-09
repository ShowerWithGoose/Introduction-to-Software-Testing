/*
 * @Author:
 * @Date: 2022-03-03 19:38:09
 * 扩展字符A
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#define MaxN 1000000

char s[MaxN+5]={0};
int len;

bool check(int i){
    return\
    (((isdigit(s[i-1])&&isdigit(s[i+1]))\
    ||(isupper(s[i-1])&&isupper(s[i+1]))\
    ||(islower(s[i-1])&&islower(s[i+1])))\
    &&s[i-1]<s[i+1]-1);
}

int main(int argc, char const *argv[]){
    gets(s+1);
    len=strlen(s+1);
    for(int i=1;i<=len;i++){
        if(s[i]=='-'){
            if(check(i)){
                for(int c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
            }else{
                putchar('-');
            }
        }else{
            printf("%c",s[i]);
        }
    }
    return 0;
}
