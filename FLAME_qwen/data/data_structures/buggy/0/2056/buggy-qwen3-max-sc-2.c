#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[2000];
int main(){
    gets(s); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. Also, in many modern compilers/environments, gets() is removed entirely, which may lead to compilation errors.]
    int i,j;
    char t;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i-1]>='A' && s[i-1]<='Z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){ // @@ [Incorrect loop bound: should be j <= (s[i+1] - s[i-1] - 1) or simply j < (s[i+1] - s[i-1]). Current logic subtracts base offsets unnecessarily and skips the last character.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){ // @@ [Same incorrect loop bound issue as above; also, condition allows s[i+1]==s[i-1], which should not expand per problem statement (must be strictly greater).]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){ // @@ [Same issues: incorrect loop bound and allows equal characters, which violates requirement that second char must be greater.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else
            printf("-"); // @@ [This 'else' only pairs with the last 'if' (lowercase), not all three type checks. So if uppercase or digit conditions fail but lowercase also fails, it prints '-', but if uppercase succeeds, it still checks digit/lowercase and may print extra '-' due to dangling else. Also, missing bounds check for i==0 or i==strlen(s)-1 leading to out-of-bounds access.]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}