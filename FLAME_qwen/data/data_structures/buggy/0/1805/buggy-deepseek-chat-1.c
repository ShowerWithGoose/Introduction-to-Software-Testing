#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(i>=1&&s[i]=='-'){
            if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){
                for(int j=s[i-1]+1;j<s[i+1];j++){
                    printf("%c",j);
                }
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){
                for(int j=s[i-1]+1;j<s[i+1];j++){
                    printf("%c",j);
                }
            }
            else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){
                for(int j=s[i-1]+1;j<s[i+1];j++){
                    printf("%c",j);
                }
            }
            else {
                printf("'-'"); // @@ Error: Should print the hyphen character '-' without quotes. Using "'-'" prints the literal string '-', not the hyphen character.
            }
            
        }
        else{
                printf("%c",s[i]);
            }
    }
}