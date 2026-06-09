#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#define ma(a,b) (a)>(b)?(a):(b);
#define mi(a,b) (a)<(b)?(a):(b);
#include<ctype.h>
typedef struct {
    char s[55];
    int num = 0; // @@ C语言不允许在结构体定义中直接初始化成员变量，应改为`int num;`（全局数组默认初始化为0）
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
    char c; // @@ `fgetc`返回值为`int`类型，用`char`接收可能导致`EOF`判断错误，应改为`int c;`
    in=fopen("article.txt", "r");
    while ((c = fgetc(in)) != EOF) {
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