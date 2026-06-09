#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { @@ [Accesses s[i-1] when i=0, causing out-of-bounds read; also uses <= instead of <, which violates requirement that expansion only occurs when the character after '-' is greater than the one before]
            while(s[i-1]<s[i+1]) { @@ [Modifies s[i-1] which alters original string and affects future comparisons; also prints one extra character beyond correct range due to loop condition]
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2; @@ [Skips next two characters, but may skip non-existent or unrelated characters, leading to incorrect output or missed processing]
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; @@ [Causes infinite loop or undefined behavior when '-' is not expanded, because i-- followed by loop's i++ results in same index being processed repeatedly]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; @@ [Returns 2 for uppercase letters AND any other character (including '-', digits outside range, etc.), causing incorrect type matching (e.g., 'A' and '-' both return 2, leading to false expansion)]
}