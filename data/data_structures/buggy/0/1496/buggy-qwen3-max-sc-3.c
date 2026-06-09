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
    for(i=1;i<strlen(s)-1;i++){ @@ [Loop condition should be i <= strlen(s)-2 or i < strlen(s)-1 is correct, but the main issue is that when string length is 0 or 1, strlen(s)-1 becomes negative and converted to large positive due to unsigned nature of size_t, causing undefined behavior. However, the actual critical error is missing output of last character.]
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
    return 0; @@ [Missing output of the last character of the string when the string has more than one character. The loop runs from i=1 to i < strlen(s)-1, so the last character at index strlen(s)-1 is never printed.]
}