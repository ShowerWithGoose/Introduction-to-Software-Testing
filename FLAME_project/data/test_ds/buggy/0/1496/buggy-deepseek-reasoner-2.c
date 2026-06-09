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
    for(i=1;i<strlen(s)-1;i++){ // @@ [Error: Loop condition i < strlen(s)-1 excludes the last character. The last character of the string is never printed, causing missing output like 'F' in the test case.]
        if(s[i]=='-'){
            if(s[i-1]<s[i+1]&&'a'<=s[i-1]&&s[i+1]<='z'){ // @@ [Error: Incomplete range check. Should also verify s[i-1]<='z' and s[i+1]>='a'. Otherwise, characters like 'Z' (which is <= 'z') can incorrectly satisfy the condition.]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'A'<=s[i-1]&&s[i+1]<='Z'){ // @@ [Error: Incomplete range check. Should also verify s[i-1]<='Z' and s[i+1]>='A'.]
                int p=s[i-1];
                while(++p<s[i+1]){
                    printf("%c",p);
                }
            }else if(s[i-1]<s[i+1]&&'0'<=s[i-1]&&s[i+1]<='9'){ // @@ [Error: Incomplete range check. Should also verify s[i-1]<='9' and s[i+1]>='0'.]
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