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
            if(s[i-1]>='A' && s[i-1]<='Z'){ // @@ Missing check for i==0, accessing s[-1] causes undefined behavior
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){ // @@ Condition should be > instead of >= as per requirement "greater than"
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){ // @@ Should be else if to prevent falling through and incorrectly printing - later
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){ // @@ Condition should be > instead of >=
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){ // @@ Should be else if to ensure mutually exclusive branches
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){ // @@ Condition should be > instead of >=
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else // @@ This else only pairs with the last if, causing - to be printed incorrectly for uppercase/digit cases
            printf("-"); 
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}