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
    for(i=1;i<strlen(s)-1;i++){
        if(s[i]=='-'){
            if(s[i-1]<s[i+1]&&'a'<=s[i-1]&&s[i+1]<='z'){ // @@ [The condition 'a'<=s[i-1]&&s[i+1]<='z' does not ensure both characters are lowercase; it allows cases like s[i-1]='A' and s[i+1]='z', which violates the same-type requirement.]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'A'<=s[i-1]&&s[i+1]<='Z'){ // @@ [Similarly, 'A'<=s[i-1]&&s[i+1]<='Z' does not guarantee both are uppercase; e.g., s[i-1]='a' and s[i+1]='Z' would incorrectly pass.]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'0'<=s[i-1]&&s[i+1]<='9'){ // @@ [Same issue: '0'<=s[i-1]&&s[i+1]<='9' doesn't ensure both are digits; e.g., s[i-1]='a' and s[i+1]='9' would wrongly satisfy this.]
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