#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. Also, in many modern compilers/environments, 'gets' is removed entirely, which can lead to compilation errors.]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition stops at strlen(a)-1, so last character is never processed if it's not part of a '-' pattern. This leads to missing output of the last character in some cases.]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Incorrect range checks: e.g., for digits, it checks a[toa-1]>=48 and a[toa+1]<=57 but doesn't ensure both are digits. Same for letters. Should check both ends belong to same category. Also, allows equal characters (<=), but problem requires strictly increasing (so should be <).]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ [This loop starts from a[toa-1], but expansion should start from a[toa-1]+1. As written, it incorrectly includes the starting character again.]
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]); // @@ [This prints three characters, but in cases where '-' is not expanded, the middle '-' and next char might be reprinted later, causing duplication. Also, this approach disrupts the sequential processing of the string.]
            }
            toa++;
        }
    }
}