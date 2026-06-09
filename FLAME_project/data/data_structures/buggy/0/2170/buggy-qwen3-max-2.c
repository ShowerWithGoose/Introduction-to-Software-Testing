#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[100000];
    int j=0;
    gets(s);
    int l=strlen(s);
    printf("%c",s[0]);
    for(int i=1;i<l;i++){
        if(s[i]=='-'){
            if(s[i-1]>=48&&s[i-1]<=57&&s[i+1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; // @@ This increment causes skipping of the next character after expansion, leading to duplicate output when multiple expansions are adjacent or followed by a non-expanded '-'
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; // @@ Same issue: incrementing i here skips the next character, which may be part of another pattern or a regular character that should be printed
            }
            else printf("%c",s[i]); // @@ This 'else' only applies to the last 'if', not the whole block. So if the first or second condition matches but the third doesn't, it incorrectly prints '-' even though expansion already happened.
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}