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
            if(s[i-1]>='a' && s[i-1]<='z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else
            printf("-"); // @@ The 'else' only applies to the last 'if' (lowercase), so if '-' is between uppercase or digits but doesn't meet condition, it incorrectly prints '-' even when it shouldn't (e.g., valid uppercase range would skip this else, but invalid ones in other categories may fall through). Also, when expansion conditions are met, the code prints intermediate chars but does NOT skip the next character (s[i+1]), causing duplication or omission.
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}