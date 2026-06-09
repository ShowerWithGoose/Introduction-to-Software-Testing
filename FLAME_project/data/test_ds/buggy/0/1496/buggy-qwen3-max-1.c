#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
char s[10086];
int i=0;
int main(){
    scanf("%s",s);
    printf("%c",s[0]); // @@ [If the input string is empty, this will print garbage or cause undefined behavior. Also, if the first character is '-', it should be printed as-is, but this prints s[0] unconditionally before processing.]
    for(i=1;i<strlen(s)-1;i++){ // @@ [The loop stops at strlen(s)-2, so the last character of the string is never printed. This causes missing output for the final character (e.g., 'F' in test case).]
        if(s[i]=='-'){
            if(s[i-1]<s[i+1]&&'a'<=s[i-1]&&s[i+1]<='z'){ // @@ [Incorrect range check: it allows cases like 'a' <= s[i-1] and s[i+1] <= 'z', but doesn't ensure both are lowercase. For example, if s[i-1]='A' and s[i+1]='z', this condition could incorrectly pass if 'A' < 'z'. Should check both ends are in [a-z].]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'A'<=s[i-1]&&s[i+1]<='Z'){ // @@ [Same issue: doesn't ensure both characters are uppercase. Could mix types if one is uppercase and the other is not but still within ASCII bounds.]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'0'<=s[i-1]&&s[i+1]<='9'){ // @@ [Same issue: doesn't verify both are digits. Could accept invalid cross-type ranges.]
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