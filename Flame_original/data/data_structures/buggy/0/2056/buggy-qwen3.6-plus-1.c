#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[2000];
int main(){
    gets(s); // @@ gets is removed in modern C standards, causing compilation errors; use scanf or fgets instead.
    int i,j;
    char t;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i-1]>='A' && s[i-1]<='Z'){ // @@ Accesses s[i-1] when i=0 causing out-of-bounds memory access; should check i>0 first.
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){ // @@ Accesses s[i+1] when i is the last index causing out-of-bounds; condition should use > instead of >= per requirements.
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){ // @@ Should be else if to form a mutually exclusive chain and prevent incorrect fallback to the final else.
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){ // @@ Accesses s[i+1] out of bounds when i is last index; condition should use > instead of >=.
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){ // @@ Should be else if to correctly chain type checks.
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){ // @@ Accesses s[i+1] out of bounds when i is last index; condition should use > instead of >=.
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else // @@ This else only pairs with the lowercase check, causing - to print incorrectly for uppercase/digit cases.
            printf("-"); // @@ Executes incorrectly due to misplaced else, overriding valid expansions or other type checks.
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}