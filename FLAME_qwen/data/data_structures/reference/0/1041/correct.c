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

int type(char x){
    if (x >= 'a' && x <= 'z')return 1;
    if (x >= 'A' && x <= 'Z')return 2;
    if (x >= '0' && x <= '9')return 3;
    return (int)x;
}

char s[100000], a[100000];

int main(){
    scanf("%s", s);
    for (int i = 0, j = 0; i < strlen(s); i++){
        if (s[i] == '-' && s[i+1] > s[i-1] && type(s[i+1]) == type(s[i-1])){
            for (char ch = s[i-1]+1; ch < s[i+1]; ch++){
                a[j++] = ch;
            }
        }
        else {
            a[j++] = s[i];
        }
    }
    printf("%s", a);
    return 0;
}



