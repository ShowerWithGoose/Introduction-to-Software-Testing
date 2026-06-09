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
    for(i=1;i<strlen(s)-1;i++){ @@ [The loop condition should be i <= strlen(s)-2 or i < strlen(s)-1 is correct, but the issue is that when the string ends with '-', accessing s[i+1] leads to out-of-bound read. However, the primary error causing compilation failure is not in this code—it's likely a missing compiler in the environment. But based on logic errors affecting correctness: the loop stops too early; it should go up to i < strlen(s) - 1 to safely access s[i+1], which it does, so this is okay. However, the real logical flaw is that the last character of the string is never printed if it's not part of a '-' expansion. For example, input "a-b" prints 'a', then processes '-', prints 'b' is never printed because loop runs only until i < strlen(s)-1 (i.e., i=1 for "a-b" of length 3, so i goes 1 only), and after processing '-', the next char s[2]='b' is never printed by the else clause because loop ends. So the final character is omitted.]
        if(s[i]=='-'){
            if(s[i-1]<s[i+1]&&'a'<=s[i-1]&&s[i+1]<='z'){
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'A'<=s[i-1]&&s[i+1]<='Z'){
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'0'<=s[i-1]&&s[i+1]<='9'){
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