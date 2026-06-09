#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long

char str[1000000];

int main(){
//    freopen("r.txt","r",stdin);
//    freopen("w.txt","w",stdout);
    gets(str+1);
    int e;
    if(str[1] == '0'){
        e = 0;
        for(int i = 1; str[i] != '\0'; ++i){
            if(str[i] == '0')++e;
            if(str[i] != '0' && str[i] != '.') break;
        }
        if(strlen(str+1) == e+2){
            printf("%ce-%d",str[strlen(str+1)],e);
        }else{
            int i = 1;
            for(; i <= strlen(str+1); ++i){
                if(str[i] != '0' && str[i] != '.'){
                    putchar(str[i]);
                    break;
                }
            }
            putchar('.');
            printf("%se-%d",str+1+i,e);
        }
    }else{
        e = -1;
        for(int i = 1; i <= strlen(str+1) && str[i] != '.'; ++i) ++e;
        putchar(str[1]);
        putchar('.');
        for(int i = 2; i <= strlen(str+1); ++i){
            if(str[i] != '.') putchar(str[i]);
        }
        printf("e%d",e);
    }
    return 0;
}
