#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { @@ [Accesses s[i-1] when i=0, causing out-of-bounds read; also condition should be s[i-1] < s[i+1], not <=]
            while(s[i-1]<s[i+1]) { @@ [Modifies s[i-1] which affects future comparisons and prints one extra character beyond intended range]
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2; @@ [Skips next two characters, but may skip valid parts of string or go out of bounds]
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; @@ [May cause infinite loop or undefined behavior due to modifying loop index inside loop]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; @@ [Does not validate that 'a' is an uppercase letter; returns 2 for non-alphanumeric chars, which may lead to incorrect expansion decisions]
}