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
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){ // @@ Condition should use '>' instead of '>=' per requirement, and the loop below misses the end character.
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){ // @@ Loop condition '<' should be '<=' to include the end character in the expansion.
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){ // @@ Should be 'else if' to form a mutually exclusive chain, otherwise the final 'else' incorrectly binds only to the lowercase check.
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){ // @@ Condition should use '>' instead of '>='.
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){ // @@ Loop condition '<' should be '<=' to include the end character.
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){ // @@ Should be 'else if' to correctly chain the conditions.
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){ // @@ Condition should use '>' instead of '>='.
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){ // @@ Loop condition '<' should be '<=' to include the end character.
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else // @@ This 'else' currently only attaches to the lowercase 'if'; chaining previous 'if's with 'else if' fixes the logic so it only prints '-' when no valid expansion occurs.
            printf("-"); 
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}