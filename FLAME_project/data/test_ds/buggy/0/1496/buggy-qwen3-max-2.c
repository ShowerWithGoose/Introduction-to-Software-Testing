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
            if(s[i-1]<s[i+1]&&'a'<=s[i-1]&&s[i+1]<='z'){ // @@ [The condition 'a'<=s[i-1]&&s[i+1]<='z' does not ensure both characters are lowercase; it allows mixed cases like 'A'-'z'. It should check both ends are in [a-z].]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'A'<=s[i-1]&&s[i+1]<='Z'){ // @@ [Similarly, this condition does not ensure both characters are uppercase; e.g., 'A' <= s[i-1] is okay but s[i+1] <= 'Z' doesn't guarantee s[i-1] is uppercase or s[i+1] is uppercase. Should check both are in [A-Z].]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'0'<=s[i-1]&&s[i+1]<='9'){ // @@ [Same issue: this checks only that s[i-1] >= '0' and s[i+1] <= '9', but doesn't ensure both are digits. For example, s[i-1]=':' (ASCII 58) and s[i+1]='5' would pass incorrectly.]
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