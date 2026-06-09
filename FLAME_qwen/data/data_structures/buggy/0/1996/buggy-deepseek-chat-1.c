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
    for(i=1;i<m;i++){
        if(ch[i]!='-'&&ch[i-1]!='-'){
        printf("%c",ch[i-1]);
        }
        else if(ch[i]=='-'){
            printf("%c",ch[i-1]); // @@ This prints the character before '-' unconditionally, but if the expansion condition fails, the '-' itself should be printed instead of the character before it. The logic incorrectly outputs ch[i-1] even when no expansion occurs.
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
            else if (ch[i] != '-')
            printf("%c", ch[i]); // @@ This condition is always false because we are already inside else if(ch[i]=='-'), so ch[i] is always '-'. This line never executes, meaning when expansion fails, the '-' is not printed.
            }
            
    }
    printf("%c",ch[m-1]); // @@ This prints the last character unconditionally, but if the last character is part of an expansion (e.g., "a-d"), it will be printed twice: once in the loop and once here. Also, if the last character is '-', it will be printed incorrectly.
    return 0;
}