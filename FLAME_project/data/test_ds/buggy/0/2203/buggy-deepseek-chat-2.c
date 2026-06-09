#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) {
            while(s[i-1]<s[i+1]) {
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2; // @@ The loop increments i by 2 to skip the expanded range, but this may skip characters incorrectly when the expansion is not at the end of the string. Additionally, the condition s[i-1]<=s[i+1] should be s[i-1]<s[i+1] to match the requirement that the character after '-' must be greater than the one before it.
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; // @@ This decrements i to reprocess the '-' character, but it can cause an infinite loop or incorrect behavior because the '-' is not printed and the loop index is manipulated in a confusing way. The logic for handling non-expansion cases is flawed.
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2;
}