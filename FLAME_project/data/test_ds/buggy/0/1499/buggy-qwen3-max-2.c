#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a);
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition stops one character early, so the last character is never printed if it's not part of a '-' expansion.]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Incorrect range checks: e.g., (a[toa-1]>=48 && a[toa+1]<=57) does not ensure both are digits; should check both ends are in same category. Also uses <= instead of < for expansion condition, which violates requirement that second char must be greater.]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]);
            }
            toa++;
        }
    }
}