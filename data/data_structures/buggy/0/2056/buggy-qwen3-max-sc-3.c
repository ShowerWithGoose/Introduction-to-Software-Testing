#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[2000];
int main(){
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in some environments, this leads to compilation errors or warnings that prevent execution]
    int i,j;
    char t;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i-1]>='A' && s[i-1]<='Z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){ // @@ [Incorrect loop bound: should be j <= (s[i+1] - s[i-1] - 1) or simply j < (s[i+1] - s[i-1]); current logic subtracts base twice unnecessarily]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){ // @@ [Same incorrect loop bound issue as above; also, condition allows equal characters (>=), but problem requires strictly greater]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){ // @@ [Same issues: incorrect loop bound and allowing equal characters instead of strictly greater]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else
            printf("-"); // @@ [This 'else' only pairs with the last 'if' (lowercase), not the entire group; so if '-' is between uppercase or digits but doesn't meet condition, it won't print '-', leading to missing output]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}