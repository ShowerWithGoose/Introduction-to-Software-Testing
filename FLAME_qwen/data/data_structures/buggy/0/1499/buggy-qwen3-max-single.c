#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Use 'fgets' instead.]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition may skip the last character if it's not part of a '-' pattern, leading to incomplete output. Also, if the string ends with '-', accessing a[toa+1] may go out of bounds.]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Incorrect range checks: e.g., for digits, it checks a[toa-1]>=48 and a[toa+1]<=57 but doesn't ensure both are digits. Should check both characters are in the same category (e.g., both digits). Also, uses <= instead of < for expansion condition per problem requirements.]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ [This prints from a[toa-1] to a[toa+1]-1, but per problem, should print from a[toa-1]+1 to a[toa+1]-1 (i.e., exclude the endpoints which are already printed or handled). Also, if condition used <=, this loop may run when it shouldn't.]
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]); // @@ [This prints three characters at once, but previous logic may have already printed a[toa-1], leading to duplication. Also, if at end of string, a[toa+1] may be out of bounds.]
            }
            toa++;
        }
    }
}