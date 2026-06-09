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
            while(s[i-1]<s[i+1]) { // @@ The loop condition should be `<=` to include the ending character, otherwise the last character of the expansion is omitted.
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2;
        }
        if(s[i]!='-') // @@ This condition does not exclude the null terminator; after a valid expansion, i may become len, and printing s[len] (null) adds an extra character.
        printf("%c",s[i]);
        else i--; // @@ This else is incorrect: for invalid hyphens, it should print the hyphen, but decrementing i causes an infinite loop. The entire if-else logic needs reworking.
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