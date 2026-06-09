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
            i+=2; // @@ [Error: When the expansion is complete, i is incremented by 2, skipping the character after the '-'. However, the loop's i++ will also execute, causing the character after the expansion to be skipped entirely. For example, in input "a-uB-F", after expanding "a-u", i points to 'B', then i+=2 makes i point to 'F', and the loop's i++ makes i point to the null terminator, causing 'B' to be missed. The correct behavior is to skip only the '-' and the characters already printed, so i should be incremented by 1 (to skip the '-') and let the loop's i++ handle the rest, or adjust the logic to avoid skipping the next character.]
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; // @@ [Error: When s[i] is '-', the code decrements i to re-process the previous character, but this causes an infinite loop or incorrect behavior because the '-' is not expanded (e.g., when types don't match). The decrement leads to revisiting the same '-' repeatedly without progress. The correct approach is to simply skip the '-' without printing it, not to decrement i.]
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