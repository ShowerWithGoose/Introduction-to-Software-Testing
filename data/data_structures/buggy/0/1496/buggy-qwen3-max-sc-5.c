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
    for(i=1;i<strlen(s)-1;i++){ // @@ [Loop condition excludes the last character, so if the string ends with a non-'-' character, it won't be printed. Also, when accessing s[i+1], if i == strlen(s)-2, then i+1 is the last valid index, but the loop stops before processing the last character in the output.]
        if(s[i]=='-'){
            if(s[i-1]<s[i+1]&&'a'<=s[i-1]&&s[i+1]<='z'){ // @@ [Condition incorrectly checks if s[i+1] <= 'z' without verifying that s[i-1] is also >= 'a'. This allows mixed cases like 'A'-'z' to pass if s[i-1] < s[i+1]. Same issue exists in uppercase and digit conditions.]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'A'<=s[i-1]&&s[i+1]<='Z'){ // @@ [Same as above: does not ensure s[i-1] <= 'Z' or that both are uppercase.]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'0'<=s[i-1]&&s[i+1]<='9'){ // @@ [Same as above: does not ensure s[i-1] <= '9' or that both are digits.]
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