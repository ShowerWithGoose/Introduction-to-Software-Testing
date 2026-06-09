#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[2000];
int main(){
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, the compilation error might be due to missing linking or compiler issues, but more critically, 'gets' is not allowed in safe code.]
    int i,j;
    char t;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i-1]>='A' && s[i-1]<='Z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){ // @@ [Incorrect loop bound: should be j <= (s[i+1] - s[i-1] - 1) or simply j < (s[i+1] - s[i-1]). Current logic subtracts offsets unnecessarily and skips the last character.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){ // @@ [Same incorrect loop bound issue as above; expansion will miss the last character.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){ // @@ [Same incorrect loop bound issue; expansion incomplete.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else
            printf("-"); // @@ [This 'else' only pairs with the last 'if' (lowercase), not all three type checks. So if the '-' is between uppercase or digits but doesn't satisfy condition, it falls through and prints '-' even if earlier conditions failed. Logic flaw in control structure.]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}