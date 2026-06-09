#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[2000];
int main(){
    gets(s);
    int i,j;
    char t;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i-1]>='A' && s[i-1]<='Z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){ // @@ The use of independent 'if' statements instead of 'else if' causes logical errors. When the first 'if' (uppercase) is false, it falls through to the second 'if' (digits). If that is also false, it falls through to the third 'if'. If the third 'if' (lowercase) is false, the subsequent 'else' executes, printing '-'. However, if the first or second 'if' was entered but didn't print anything (e.g. condition failed inside), or if multiple types match incorrectly, the logic breaks. Specifically here, the 'else' only binds to the last 'if'. For input 'B-F', the first 'if' is true, prints CDE. The second 'if' is false. The third 'if' is false. The 'else' executes, printing '-'. This results in "BCDE-" instead of "BCDEF". The structure should be if-else if-else if-else to ensure mutually exclusive handling of types and correct fallback to printing '-' only when no expansion condition is met.
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else // @@ This 'else' is associated only with the immediately preceding 'if' (lowercase check). It should be part of an if-else-if chain covering all three cases (upper, digit, lower) to correctly decide whether to print '-' or not. As written, if the uppercase or digit blocks execute (or don't), the flow continues to the lowercase check. If the lowercase check fails, it prints '-', which is incorrect if a previous block already handled the expansion or if the character wasn't a lowercase letter but was a valid uppercase/digit expansion that shouldn't have printed '-'. In the specific case of B-F, the uppercase block prints CDE, then the digit block is skipped, then the lowercase block is skipped, then this else prints '-', resulting in wrong output.
            printf("-"); 
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}