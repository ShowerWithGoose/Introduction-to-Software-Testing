#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. It should be replaced with 'fgets'.]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition stops at strlen(a)-1, which may skip the last character if it's not part of a '-' pattern, leading to incomplete output. Also, if the string ends with '-', accessing a[toa+1] could be out-of-bounds.]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Incorrect range checks: e.g., for digits, it checks a[toa-1]>=48 and a[toa+1]<=57 but does NOT ensure a[toa+1]>=48 or a[toa-1]<=57, so mixed cases like '9-a' could pass the digit condition incorrectly. Same issue applies to letters. Also, the condition allows equal characters (<=), but problem requires expansion only when the second char is greater (strictly).]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ [This loop prints from a[toa-1] to a[toa+1]-1, but according to problem, expansion of 'a-d' should produce 'abcd', meaning it should start from a[toa-1]+1 up to a[toa+1]-1, then the original surrounding chars are printed elsewhere? However, in this code, the surrounding chars are only printed in the else branch, so this logic is inconsistent with expected behavior.]
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]); // @@ [This prints three characters at once, but the main loop index 'toa' is incremented by 1 before this block and then again after, which may cause double printing or skipping of characters in overlapping patterns. Also, if the string ends right after '-', a[toa+1] may be out of bounds.]
            }
            toa++;
        }
    }
}