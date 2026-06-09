#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))
int main(){
    int i=0,m=0,j=0;
    char ch[10000]={0};
    char c=0;
    gets(ch);
    m=strlen(ch);
    for(i=1;i<m;i++){ // @@ Loop starts at 1, missing handling of first character if '-', out-of-bounds access when i=m-1, and fails to print right character after expansion.
        if(ch[i]!='-'&&ch[i-1]!='-'){ // @@ This condition prevents printing the right character after a '-' (since ch[i-1] is '-'), causing it to be lost in the loop.
        printf("%c",ch[i-1]);
        }
        else if(ch[i]=='-'){
            printf("%c",ch[i-1]);
            if(isupper(ch[i-1])&&isupper(ch[i+1])){
                for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if(islower(ch[i-1])&&islower(ch[i+1])){
                for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if(ch[i-1]>='0'&&ch[i-1]<='9'&&ch[i+1]>='0'&&ch[i+1]<='9'){
                    for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if (ch[i] != '-') // @@ This condition is always false because it is inside else if(ch[i]=='-'), so a non-expandable '-' is never printed.
            printf("%c", ch[i]);
            }
            
    }
    printf("%c",ch[m-1]); // @@ Prints last character after loop, which may cause incorrect order for expansion cases and duplicate printing if last char is '-'.
    return 0;
}