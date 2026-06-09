#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cL while (getchar() != '\n')  //clear line
#define fi(x) for (i = 0; i < x; i++)
#define fj(x) for (j = 0; j < x; j++)
#define FOR(a, b, c) for (int(a) = (b); (b) < (c) ? (a) <= (c) : (a) >= (c); (b) < (c) ? (a)++ : (a)--)
#define LL long long
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a < b ? b : a)
#define pf printf
#define sf scanf

char c[200000];
int cmp(char a,char b);
int main() {
    fgets(c,199999,stdin);
    int l=strlen(c);
    FOR(i,1,l){
        if(c[i]!='-')putchar(c[i-1]);
        else if(cmp(c[i-1],c[i+1])){
            FOR(j,c[i-1],c[i+1]-1)putchar(j);
            i++;
        }
        else {
            putchar(c[i-1]);
        }
    }
    return 0;
}
int cmp(char a,char b){
    if(b<=a)return 0;
    if(a>='a'&&b<='z')return 1;
    if(a>='A'&&b<='Z')return 1;
    if(a>='0'&&b<='9')return 1;
    return 0;
}
