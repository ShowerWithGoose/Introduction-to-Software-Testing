#include<stdio.h>
#include<string.h>
char s[10010]={'\0'},b[100010]={'\0'};
int main(){
    int i,j=0;
    gets(s);
    for(i=0;i<strlen(s);i++,j++){
        b[j]=s[i];
        if(s[i]=='-'&&s[i+1]>s[i-1]){
            if((s[i-1]-'0'<=9&&s[i-1]-'0'>=0&&s[i+1]-'0'>=0&&s[i+1]-'\0'<=9)||(s[i-1]-'A'<=25&&s[i-1]-'A'>=0&&s[i+1]-'A'>=0&&s[i+1]-'A'<=25)||(s[i-1]-'a'<=25&&s[i-1]-'a'>=0&&s[i+1]-'a'>=0&&s[i+1]-'a'<=25)){ // @@ Typo: '\0' should be '0'. Using '\0' (ASCII 0) checks if the ASCII value of s[i+1] is <= 9, which is always false for digits (ASCII 48-57), causing the condition to fail and preventing digit range expansion.
                for(int k=1;k<s[i+1]-s[i-1];k++){
                    b[j]=s[i-1]+k;
                    j++;
                }
                b[j]=s[i+1];
                i++;
            }    
            
        }
    }
    puts(b);
    return 0;
}