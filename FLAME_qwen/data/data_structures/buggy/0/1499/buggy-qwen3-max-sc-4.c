#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in many modern environments, 'gets' is removed entirely, leading to compilation error]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition may skip the last character if it's not part of a '-' pattern, leading to incomplete output]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Incorrect range checks: e.g., for digits, it checks a[toa-1]>=48 and a[toa+1]<=57 but doesn't ensure both are digits; similar issues for letters. Should check both ends belong to same category. Also uses <= instead of < for expansion condition per problem requirement]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ [This prints from a[toa-1] to a[toa+1]-1, but per problem, should print characters between them, i.e., starting from a[toa-1]+1]
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]);
            }
            toa++;
        }
    }
}