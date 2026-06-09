#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[2000];
int main(){
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Additionally, some compilers may not support it, leading to compilation errors or warnings treated as errors.]
    int i,j;
    char t;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i-1]>='A' && s[i-1]<='Z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){ // @@ [Incorrect loop bound: should be j <= (s[i+1] - s[i-1] - 1) or simply j < (s[i+1] - s[i-1]). Current logic subtracts offsets from 'A', which gives same result as direct subtraction but is unnecessarily complex and error-prone. However, the main issue is that this condition does not check if s[i+1] > s[i-1], allowing equal characters which should not expand. Also, missing bounds check for i+1 being within string length.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){ // @@ [Same issues as above: allows expansion when s[i+1] == s[i-1], and no check that i+1 is valid index. Also, condition should require s[i+1] > s[i-1].]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){ // @@ [Same issues: allows non-increasing ranges and lacks boundary check for i+1. Should only expand if s[i+1] > s[i-1].]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else
            printf("-"); // @@ [This 'else' only pairs with the last 'if' (lowercase), not all three type checks. So if the '-' is between uppercase or digit ranges that don't qualify, it will fall through and print '-' correctly, but if it's between lowercase that doesn't qualify, it prints '-', but if it's between uppercase that qualifies, then also checks digits and lowercase, and if lowercase fails, prints '-' again incorrectly. Logic structure is flawed due to separate if blocks instead of else-if chain. Also, no handling for cases where i==0 or i==strlen(s)-1 (i+1 out of bounds).]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}