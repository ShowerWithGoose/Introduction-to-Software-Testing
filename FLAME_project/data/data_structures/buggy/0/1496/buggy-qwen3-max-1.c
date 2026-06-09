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
            if(s[i-1]<s[i+1]&&'a'<=s[i-1]&&s[i+1]<='z'){ // @@ [The condition checks if s[i-1] is >= 'a' but does not ensure s[i+1] is >= 'a'; similarly, it checks s[i+1] <= 'z' but not s[i-1] <= 'z'. This allows mixed cases like 'Z-a' to incorrectly pass if ASCII values satisfy s[i-1] < s[i+1]. Also, the same issue exists in uppercase and digit conditions.]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'A'<=s[i-1]&&s[i+1]<='Z'){ // @@ [Same issue: does not verify that s[i+1] >= 'A' or that s[i-1] <= 'Z', so invalid ranges like '9-A' might be misprocessed if ASCII comparison passes.]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'0'<=s[i-1]&&s[i+1]<='9'){ // @@ [Same issue: does not check that s[i+1] >= '0' or s[i-1] <= '9', allowing invalid digit-letter mixes to be processed if s[i-1] < s[i+1] in ASCII.]
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
    return 0; // @@ [The last character of the input string is never printed because the loop runs from i=1 to strlen(s)-2 (inclusive). For input "a-uB-F", the final 'F' is skipped, causing missing output.]
}