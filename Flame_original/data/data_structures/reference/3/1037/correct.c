#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LL long long

int RD(){
    int x=0; char ch; int f=1;
    for (; ch < '0' || ch > '9'; ch = getchar())if (f == '-') f=-1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())x = x*10 + ch-'0';
    return x*f;
}

LL RDL(){
    LL x=0; char ch; int f=1;
    for (; ch < '0' || ch > '9'; ch = getchar())if (f == '-') f=-1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())x = x*10 + ch-'0';
    return x*f;
}

int main(){
    char s[1000000];
    scanf("%s", s);
    int i;
    if (s[0] == '0' && s[1] == '.'){
        for (i = 2; i < strlen(s) && s[i] == '0'; i++);
        if (i == strlen(s)-1){
            printf("%ce-%d", s[i], i-1);
            return 0;
        }
        printf("%c.%se-%d",s[i], s+i+1, i-1);
        return 0;
    }
    for (i = 0; i < strlen(s) && s[i] != '.'; i++);
    int len = strlen(s);
    s[i] = '\0';
    printf("%c.%s%se%d", s[0], s+1, s+i+1, i-1);
    return 0;
}
