#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#define ma(a,b) (a)>(b)?(a):(b);
#define mi(a,b) (a)<(b)?(a):(b);
#include<ctype.h>
typedef struct {
    char s[55];
    int num = 0; // @@ error: cannot initialize member in C struct definition; use assignment after declaration or rely on zero-initialization
} word;
word a[10000];
int n, l, fl;
char ci[55];
int cmp(const void*a, const void*b) {
    if (strcmp(((word*)a)->s, ((word*)b)->s) < 0) {
        return -1;//a在b前，-1；
    }
    if (strcmp(((word*)a)->s, ((word*)b)->s) > 0) {
        return 1;//a在b前，-1；
    }
    return 0;
}
int main() {
    FILE*in;
    char c;
    in=fopen("article.txt", "r");
    while ((c = fgetc(in)) != EOF) { // @@ potential error: fgetc returns int; using char may cause truncation or infinite loop if char is unsigned
        if (isalpha(c)) {
            ci[l] = tolower(c);
            l++;
        } else {
            if(l==0){
                continue;
            }
            ci[l] = '\0';
            for (int i = 0; i <n; i++) {
                if (strcmp(ci, a[i].s) == 0) {
                    fl = 1;
                    a[i].num++;
                    break;
                }
            }
            if (!fl) {
                strcpy(a[n].s, ci);
                a[n].num = 1;
                n++;
            }fl = 0;l=0;
        }    
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%s %d\n",a[i].s,a[i].num);//TODO
    }
    return 0;
}