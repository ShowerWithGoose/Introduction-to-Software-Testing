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
            i+=2; // @@ [Error: When the expansion is complete, the loop increments i by 2 to skip the character after '-', but the for loop also increments i by 1, causing i to skip an extra character. This leads to missing output for the character after the expansion range, as seen in the buggy output where 'B' is missing after 'u'.]
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; // @@ [Error: When s[i] is '-', the code decrements i to re-check the previous character, but this logic is flawed. It causes the loop to process the same '-' multiple times or skip characters incorrectly, leading to undefined behavior and incorrect output.]
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