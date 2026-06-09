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
            printf("%c",ch[i-1]); // @@ This prints the character before '-' unconditionally, but if the expansion condition fails, the '-' itself should be printed instead of the preceding character. The logic incorrectly outputs ch[i-1] even when no expansion occurs.
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
            printf("%c", ch[i]); // @@ This condition is always false because we are already in the else if(ch[i]=='-') block, so ch[i] is always '-'. This line is dead code and never executes, causing the '-' to be omitted when expansion conditions fail.
            }
            
    }
    printf("%c",ch[m-1]); // @@ This prints the last character unconditionally, but if the last character is part of an expansion (e.g., in "a-d", 'd' is printed here after the loop), it may duplicate output or cause incorrect order. The loop already handles printing up to m-1, so this extra print can cause errors.
    return 0;
}