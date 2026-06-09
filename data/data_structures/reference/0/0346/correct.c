#include<stdio.h>
#include<string.h>
char s[10000001];
int main(){
    scanf("%s", s);
    int i = 0;
    int len = strlen(s);
    for (i = 0; i < len;i++){
        if(((s[i]-'a'<26&&s[i]-'a'>=0)&&s[i+1]=='-'&&(s[i+2]-'a'<26&&s[i+2]-'a'>=0))||((s[i]-'A'<26&&s[i]-'A'>=0)&&(s[i+1]=='-')&&(s[i+2]-'A'<26&&s[i+2]-'A'>=0))||((s[i]-'0'<=9&&s[i]-'0'>=0)&&s[i+1]=='-'&&(s[i+2]-'0'<=9&&s[i+2]-'0'>=0))){
            int j;
            for (j = 0; j <(s[i + 2] - s[i]);j++){
                printf("%c", s[i] + j);
            }
            i++;
        }
        else 
        printf("%c", s[i]);
       
    }
     return 0;
}


