#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[2000];
int main(){
    gets(s); // @@ Using gets is unsafe; but logical errors are elsewhere.
    int i,j;
    char t;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i-1]>='A' && s[i-1]<='Z'){ // @@ [Error] No check if i>0; out-of-bounds access when '-' is at beginning.
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){ // @@ [Error] Should use '>' instead of '>='; also need to check i+1 < strlen to avoid out-of-bounds.
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){ // @@ [Error] Same out-of-bounds issue for i=0.
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){ // @@ [Error] Should use '>' and check i+1.
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){ // @@ [Error] Same out-of-bounds issue.
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){ // @@ [Error] Should use '>' and check i+1.
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else // @@ [Error] This else is attached only to the last if (line 29). For uppercase and digit cases, if expansion does not occur, the '-' is not printed and is lost.
            printf("-"); 
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}