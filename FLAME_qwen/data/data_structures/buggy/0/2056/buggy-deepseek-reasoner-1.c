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
            if(s[i-1]>='A' && s[i-1]<='Z'){ // @@ Missing check for i>0; accesses s[-1] when i=0
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){ // @@ Should be > instead of >=; also need to ensure s[i+1] is uppercase (already implied)
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){ // @@ Missing check for i>0
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){ // @@ Should be > instead of >=
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){ // @@ Missing check for i>0
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){ // @@ Should be > instead of >=
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else
            printf("-"); // @@ The else is attached to the last if only, causing extra '-' after successful expansion from previous if statements
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}