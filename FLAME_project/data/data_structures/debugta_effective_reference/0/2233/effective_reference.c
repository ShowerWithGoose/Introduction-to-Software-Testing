#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isSameType(char l,char r) {
    if(isdigit(l) & isdigit(r)) return 1;
    if(islower(l) & islower(r)) return 2;
    if(isupper(l) & isupper(r)) return 3;
    return 0;
}

int isSeq(char l,char r) {
    if(isSameType(l,r)) {
        return l<r ? 1 : 0;
    } else return 0;
}

void printSeq(char l,char r) {
    while(l<r-1) {
        putchar(++l);
    }
}

#define L ((int)1e6)
char inp[L];

int main() {
    gets(inp);
    for(char *p=inp;*p!='\0';p++) {
        if(*p!='-') {
            putchar(*p);
        } else {
            if(isSeq(*(p-1) , *(p+1))) {
                printSeq(*(p-1), *(p+1));
            } else {
                putchar(*p);
            }
        }
    }

    return 0;
}


