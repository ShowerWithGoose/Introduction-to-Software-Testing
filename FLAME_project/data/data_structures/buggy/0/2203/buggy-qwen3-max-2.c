#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { // @@ [The condition should require s[i-1] < s[i+1], not <=, because expansion is only done when the character after '-' is greater than the one before. Also, this check accesses s[i-1] and s[i+1] without ensuring i>0 and i<len-1, leading to out-of-bound reads.]
            while(s[i-1]<s[i+1]) {
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2;
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; // @@ [When s[i] is '-', and it wasn't expanded (e.g., invalid pattern), this else clause decrements i, causing the loop to reprocess the same '-' again, potentially leading to infinite loops or incorrect output. Also, after expansion, the original characters around '-' are not properly skipped in all cases.]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; // @@ [This returns 2 for uppercase letters AND any other character (like '-', symbols, etc.), which may incorrectly classify non-alphanumeric characters as same type as uppercase letters, violating the requirement to only process [a-z], [A-Z], [0-9].]
}