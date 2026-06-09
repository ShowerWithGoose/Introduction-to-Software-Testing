#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[2000];
int main(){
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Moreover, some compilers may not support it, leading to compilation errors or warnings treated as errors.]
    int i,j;
    char t;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i-1]>='A' && s[i-1]<='Z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){ // @@ [Incorrect loop bound: should be j <= (s[i+1] - s[i-1] - 1) or simply j < (s[i+1] - s[i-1]). Current logic subtracts offsets from 'A', which gives same result as direct subtraction but is unnecessarily complex and error-prone. However, the real issue is that when s[i+1]==s[i-1], the loop runs negative times, but condition above ensures s[i+1]>=s[i-1]. Still, if equal, no expansion should occur per problem statement ("greater than"), but condition allows equality. This violates spec. But compilation error likely due to 'gets'.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){ // @@ [Same issue: allows s[i+1]==s[i-1], but problem requires "greater than". Also, incorrect expansion range. However, primary compilation error is due to 'gets'.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){ // @@ [Same logical flaw: uses >= instead of >, and incorrect loop bound. But again, compilation error is mainly from 'gets'.]
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