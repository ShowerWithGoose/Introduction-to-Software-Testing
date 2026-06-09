#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(i>=1&&s[i]=='-'){
            if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ Out-of-bounds access when s[i] is '-' at the end of string; missing check i+1 < strlen(s).
                for(int j=s[i-1]+1;j<s[i+1];j++){
                    printf("%c",j);
                }
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ Similar out-of-bounds risk.
                for(int j=s[i-1]+1;j<s[i+1];j++){
                    printf("%c",j);
                }
            }
            else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ Similar out-of-bounds risk.
                for(int j=s[i-1]+1;j<s[i+1];j++){
                    printf("%c",j);
                }
            }
            else {
                printf("'-'"); // @@ Should print '-' without quotes to match required output.
            }
            
        }
        else{
                printf("%c",s[i]);
            }
    }
}