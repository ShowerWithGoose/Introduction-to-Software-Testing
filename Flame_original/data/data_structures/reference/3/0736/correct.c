#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char s[10009];
char c[10009];

int main() {
    gets(s);
    int l = strlen(s),j=0,k;
    for(int i=0;i<l;i++) {
        if(s[i] == '.') {
            k=i;
        }else {
            c[j++] = s[i];
        }
    }
    int flg = 0,t = 0;
    for(int i=0;i<j;i++) {
        if(flg || c[i] != '0') {
            putchar(c[i]);
            if(i!=j-1 && !flg) putchar('.');
            flg = 1;
        }else t++;
    }
    printf("e%d",k-t-1);
    return 0;
}
