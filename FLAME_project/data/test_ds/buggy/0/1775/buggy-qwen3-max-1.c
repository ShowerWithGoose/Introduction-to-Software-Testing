#include<stdio.h>
#include<string.h>
char s[10010]={'\0'},b[100010]={'\0'};
int main(){
    int i,j=0;
    gets(s);
    for(i=0;i<strlen(s);i++,j++){
        b[j]=s[i];
        if(s[i]=='-'&&s[i+1]>s[i-1]){
            if((s[i-1]-'0'<=9&&s[i-1]-'0'>=0&&s[i+1]-'0'>=0&&s[i+1]-'\0'<=9)||(s[i-1]-'A'<=25&&s[i-1]-'A'>=0&&s[i+1]-'A'>=0&&s[i+1]-'A'<=25)||(s[i-1]-'a'<=25&&s[i-1]-'a'>=0&&s[i+1]-'a'>=0&&s[i+1]-'a'<=25)){
                for(int k=1;k<s[i+1]-s[i-1];k++){
                    b[j]=s[i-1]+k; // @@ [This overwrites the '-' that was just stored in b[j]; it should append new characters after the previous character, not replace the '-']
                    j++;
                }
                b[j]=s[i+1]; // @@ [This writes the end character of the range, but the loop already goes up to s[i+1]-1, so this duplicates the last character and also skips proper handling of the next input character]
                i++; // @@ [This skips the next character (s[i+1]) which is correct in intent, but due to flawed logic above, causes duplication or omission]
            }    
            
        }
    }
    puts(b);
    return 0;
}