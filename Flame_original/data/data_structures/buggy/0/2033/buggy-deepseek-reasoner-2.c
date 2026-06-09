#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int main(){
    char s[1000];
    gets(s); // @@ [Error: gets() is deprecated and unsafe; use fgets() instead. In strict C11/C17, it may cause compilation error.]
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
                printf("%d",j); // @@ [Error: Should use %c to print the character, not %d. Using %d will print the ASCII integer value instead of the character.]
            }
            else printf("-");
        }
        else printf("%c",s[i]);
    }
    return 0;
}