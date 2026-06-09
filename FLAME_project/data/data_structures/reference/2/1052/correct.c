#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LL long long

const int INF = 2147480000;

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
    char s[10000];
    scanf("%[^\n]",s);

    int i, j;
    for (i = 0, j = 0; i < strlen(s); i++){
        if (s[i] != ' '){
            s[j++] = s[i];
        }
    }
    s[j] = 0;
    int a[10000];
    int mem = 0;
    for (i = 0, j = 0; i < strlen(s); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            mem = mem*10 + s[i]-'0';
        }
        else{
            a[j++] = mem;
            mem = 0;
            a[j++] = s[i];
        }
    }

    int res = 0, mem_op = 0;
    mem = INF;
    for (int i = 0; i < j; i += 2){
        if (a[i+1] == '='){
            if (mem != INF){  
                if (a[i-1] == '*')mem *= a[i];
                if (a[i-1] == '/')mem /= a[i];
                if (mem_op){
                    if (mem_op == '+')res += mem;
                    if (mem_op == '-')res -= mem;
                }
                else res = mem;
            }
            else if (mem_op){
                if (mem_op == '+')res += a[i];
                if (mem_op == '-')res -= a[i];
            }
            else res = a[i];
        }
        if (a[i+1] == '+' || a[i+1] == '-'){
            if (mem != INF){
                if (a[i-1] == '*')mem *= a[i];
                if (a[i-1] == '/')mem /= a[i];
                if (mem_op == '+')res += mem;
                if (mem_op == '-')res -= mem;
                if (mem_op == 0)res = mem;
                mem = INF;
            }
            else{
                if (mem_op == '+')res += a[i];
                if (mem_op == '-')res -= a[i];
                if (mem_op == 0)res = a[i];
            }
            mem_op = a[i+1];
        }
        if (a[i+1] == '*' || a[i+1] == '/'){
            if (mem == INF)mem = a[i];
            else{
                if (a[i-1] == '*')mem *= a[i];
                if (a[i-1] == '/')mem /= a[i];
            }
        }
   
    }
    printf("%d",res);

    return 0;
}

