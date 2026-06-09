#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { // @@ [Condition should be '<' instead of '<=' because the character after '-' must be strictly greater than the character before for expansion]
            while(s[i-1]<s[i+1]) {
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2;
        }
        if(s[i]!='-')
        printf("%c",s[i]); // @@ [After i+=2, i may be equal to len, printing the null terminator; should add a check i < len before printing]
        else i--; // @@ [If '-' is not expanded, it should be printed as is, not skipped; decrementing i leads to infinite loop or incorrect skipping]
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