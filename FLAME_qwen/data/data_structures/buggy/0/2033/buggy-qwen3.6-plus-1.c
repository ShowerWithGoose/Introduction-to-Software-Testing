#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int main(){
    char s[1000];
    gets(s); // @@ gets() is removed in the C11 standard and causes compilation errors in modern compilers. Use fgets() or scanf() instead.
    printf("%c",s[0]);
    for(int i=1;s[i]!='\0';i++){
        if(s[i]=='-'){
            if(islower(s[i-1])&&islower(s[i+1])&&(s[i+1]>s[i-1])){
                for(int j=s[i-1]+1;j<s[i+1];j++)
                printf("%c",j);
            }
            else if(isupper(s[i-1])&&isupper(s[i+1])&&(s[i+1]>s[i-1])){
                for(int j=s[i-1]+1;j<s[i+1];j++)
                printf("%c",j);
            }
            else if(isdigit(s[i-1])&&isdigit(s[i+1])&&(s[i+1]>s[i-1])){
                for(int j=s[i-1]+1;j<s[i+1];j++)
                printf("%d",j); // @@ Logical error: "%d" format specifier prints the integer ASCII value instead of the character. Should be "%c".
            }
            else printf("-");
        }
        else printf("%c",s[i]);
    }
    return 0;
}