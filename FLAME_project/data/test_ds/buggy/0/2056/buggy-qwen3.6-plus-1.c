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
                if(s[i+1]>s[i-1] && s[i+1]<='Z'){ // @@ Changed '>=' to '>' to strictly follow the requirement that the character after '-' must be greater than the one before it.
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else if(s[i-1]>='0' && s[i-1]<='9'){ // @@ Changed 'if' to 'else if' to form a proper if-else chain. The original independent 'if' statements caused the final 'else' to only apply to the lowercase check, incorrectly printing '-' after valid uppercase/digit expansions.
                if(s[i+1]>s[i-1] && s[i+1]<='9'){ // @@ Changed '>=' to '>' for correctness.
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            else if(s[i-1]>='a' && s[i-1]<='z'){ // @@ Changed 'if' to 'else if' to complete the if-else chain, ensuring the final 'else' correctly handles all non-expansion cases.
                if(s[i+1]>s[i-1] && s[i+1]<='z'){ // @@ Changed '>=' to '>' for correctness.
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else
            printf("-"); 
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}