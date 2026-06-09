#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int main(){
    char s[1000];
    gets(s); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also, the compilation error may stem from missing linking or environment issue, but primary code flaw is 'gets']
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
                printf("%d",j); // @@ [Should use "%c" instead of "%d" to print character, not integer ASCII value]
            }
            else printf("-");
        }
        else printf("%c",s[i]);
    }
    return 0;
}