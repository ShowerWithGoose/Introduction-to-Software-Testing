#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char s[2000];
int main(){
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. Also, some compilers no longer support 'gets', leading to compilation errors.]
    int i,j;
    char t;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(s[i-1]>='A' && s[i-1]<='Z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='Z'){
                    for(j=1;j<(s[i+1]-'A')-(s[i-1]-'A');j++){ // @@ [Incorrect loop bound: should be j <= (s[i+1] - s[i-1] - 1) or simply j < (s[i+1] - s[i-1]). Current logic subtracts offsets unnecessarily and skips the correct number of characters.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            if(s[i-1]>='0' && s[i-1]<='9'){
                if(s[i+1]>=s[i-1] && s[i+1]<='9'){
                    for(j=1;j<(s[i+1]-'0')-(s[i-1]-'0');j++){ // @@ [Same incorrect loop bound issue as above; also fails to handle cases where expansion shouldn't occur if types differ or order is invalid.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }    
            }
            if(s[i-1]>='a' && s[i-1]<='z'){
                if(s[i+1]>=s[i-1] && s[i+1]<='z'){
                    for(j=1;j<(s[i+1]-'a')-(s[i-1]-'a');j++){ // @@ [Same incorrect loop bound issue; also missing check that s[i+1] > s[i-1], since condition allows equality which should not expand.]
                        t=s[i-1]+j;
                        printf("%c",t);
                    }
                }
            }
            else
            printf("-"); // @@ [This 'else' only pairs with the last 'if' (lowercase), not all three type checks. So if uppercase or digit conditions fail but lowercase also fails, it prints '-', but if uppercase succeeds and lowercase fails, it still prints '-' incorrectly. Logic structure is flawed.]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}