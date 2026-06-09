#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { // @@ [Out-of-bounds access when i=0; condition should use '<' instead of '<='; p() incorrectly groups uppercase letters with other characters]
            while(s[i-1]<s[i+1]) { // @@ [Modifying s[i-1] in place corrupts the original string and fails to print the starting character]
                s[i-1]++; // @@ [In-place modification leads to data corruption and incorrect expansion sequence]
                printf("%c",s[i-1]); // @@ [Only prints intermediate characters, missing the original start and end characters required for full expansion]
            }
            i+=2;
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; // @@ [Causes an infinite loop when the '-' does not meet the expansion criteria]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; // @@ [Fails to distinguish uppercase letters from other symbols, violating the requirement to only process [A-Z], [a-z], and [0-9]]
}