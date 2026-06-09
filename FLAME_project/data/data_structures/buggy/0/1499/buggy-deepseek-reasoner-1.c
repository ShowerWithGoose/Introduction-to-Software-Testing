#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a);
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ The loop condition excludes the last character. When the right side of an expansion is the last character (e.g., 'F' in "B-F"), it is never printed because the loop ends before processing it.
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ The loop uses i < right, so it prints from left to right-1. The right character is not printed here. If the right character is the last character, it will never be output, causing missing characters (e.g., missing 'F' for expansion "B-F").
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]);
            }
            toa++;
        }
    }
}