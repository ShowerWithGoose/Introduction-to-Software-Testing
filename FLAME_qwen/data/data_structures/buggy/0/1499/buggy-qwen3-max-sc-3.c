#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, 'gets' is removed entirely, leading to a compilation error.]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition stops at strlen(a)-1, so the last character is never printed if it's not part of a '-' pattern. Also, if the string ends with '-', it may access out-of-bound memory.]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Incorrect range checks: e.g., for digits, it checks a[toa-1]>=48 and a[toa+1]<=57, but doesn't ensure both are digits. Should check both ends are in same category. Also uses <= instead of < for expansion condition per problem requirement.]
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