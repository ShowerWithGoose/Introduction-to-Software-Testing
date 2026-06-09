#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [gets is removed in C11 standard and causes compilation error in modern compilers; also unsafe due to buffer overflow]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [strlen returns unsigned type, subtracting 1 from 0 causes underflow to a large number; also loop condition skips the last character]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Logical error: condition incorrectly checks character types by only verifying lower bound for left and upper bound for right, failing to ensure both are within the same valid range]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ [Logical error: loop starts at a[toa-1] instead of a[toa-1]+1 and uses < instead of <=, causing duplicate start character and missing end character; also causes C89 compilation error for variable declaration inside for]
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]); // @@ [Logical error: prints three characters but index management is flawed, potentially causing incorrect output or skipping characters when expansion is not performed]
            }
            toa++;
        }
    }
}