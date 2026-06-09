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
            printf("%c",ch[i-1]); // @@ This line prints the character before '-' unconditionally, but when the expansion condition is not met (e.g., 'B' and 'e' are different types), it should not print it here; the '-' and surrounding characters should be output as-is.
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
            printf("%c", ch[i]); // @@ This line is unreachable because the outer condition is ch[i]=='-', so ch[i] is always '-'; it should instead print the '-' and the following character when expansion is not performed.
            }
            
    }
    printf("%c",ch[m-1]); // @@ This line prints the last character unconditionally, but for input "B-e", it prints 'e' again, causing the output "Be" instead of "B-e". The logic for handling the last character is flawed.
    return 0;
}