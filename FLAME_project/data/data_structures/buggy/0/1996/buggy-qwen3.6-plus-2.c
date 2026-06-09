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
            printf("%c",ch[i-1]);
            if(isupper(ch[i-1])&&isupper(ch[i+1])){ // @@ The condition checks if both are uppercase, but fails to check if the start character is strictly less than the end character (ch[i-1] < ch[i+1]). For "B-e", 'B' is upper and 'e' is lower, so this block is skipped correctly, but the logic for valid ranges like "a-z" needs the less-than check to avoid expanding backwards or equal chars if not handled. More importantly, the problem requires NO expansion if types don't match.
                for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if(islower(ch[i-1])&&islower(ch[i+1])){ // @@ Similar to above, missing check for ch[i-1] < ch[i+1].
                for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if(ch[i-1]>='0'&&ch[i-1]<='9'&&ch[i+1]>='0'&&ch[i+1]<='9'){ // @@ Missing check for ch[i-1] < ch[i+1].
                    for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if (ch[i] != '-') // @@ This condition is logically unreachable because we are inside the `else if(ch[i]=='-')` block. It should be an `else` block to handle cases where expansion conditions are not met (e.g., mismatched types or invalid order), in which case the '-' should be printed.
            printf("%c", ch[i]);
            }
            
    }
    printf("%c",ch[m-1]);
    return 0;
}