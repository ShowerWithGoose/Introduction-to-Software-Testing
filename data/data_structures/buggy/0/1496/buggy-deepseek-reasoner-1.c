#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
char s[10086];
int i=0;
int main(){
    scanf("%s",s);
    printf("%c",s[0]);
    for(i=1;i<strlen(s)-1;i++){ // @@ Loop condition is `i<strlen(s)-1`, which misses the last character of the string. Should be `i<strlen(s)` or `i<=strlen(s)-1`.
        if(s[i]=='-'){
            if(s[i-1]<s[i+1]&&'a'<=s[i-1]&&s[i+1]<='z'){ // @@ Incomplete range check for lowercase. Need to also ensure `s[i-1]<='z'` and `s[i+1]>='a'`. Current condition allows mismatched types.
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'A'<=s[i-1]&&s[i+1]<='Z'){ // @@ Incomplete range check for uppercase. Need to ensure `s[i-1]<='Z'` and `s[i+1]>='A'`. Current condition allows mismatched types.
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'0'<=s[i-1]&&s[i+1]<='9'){ // @@ Incomplete range check for digits. Need to ensure `s[i-1]<='9'` and `s[i+1]>='0'`. Current condition allows mismatched types.
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else{
                printf("-");
            }
        }else{
            printf("%c",s[i]);
        }
    }
    return 0;
}