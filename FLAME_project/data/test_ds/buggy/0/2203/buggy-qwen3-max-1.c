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
            i+=2;
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; // @@ [When the current character is '-', the code decrements 'i', which can cause reprocessing of the same '-' in the next iteration, leading to infinite loops or incorrect output. Additionally, after expanding a range like 'a-u', the original characters before and after '-' are not skipped correctly, and the logic fails to handle multiple ranges properly. Also, when s[i-1]==s[i+1], it should not expand (as per requirement: "character after ... is greater than the one before"), but condition uses <= instead of <.]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; // @@ [This function returns 2 for uppercase letters as well as for any other character (like '-', symbols, etc.), which may incorrectly classify non-alphanumeric characters as same type as uppercase letters, violating the requirement that only [a-z], [A-Z], [0-9] should be processed. However, the main issue lies in the main loop logic.]
}