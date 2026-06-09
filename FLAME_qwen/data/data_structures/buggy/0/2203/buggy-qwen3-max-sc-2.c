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
            while(s[i-1]<s[i+1]) { @@ [Modifies s[i-1] which affects future comparisons and may cause incorrect output or infinite loop]
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2; @@ [Skips next two characters, but logic doesn't account for proper output of the ending character or overlapping ranges]
        }
        if(s[i]!='-')
        printf("%c",s[i]); @@ [May print characters that were already printed during expansion or skip necessary '-' output]
        else i--; @@ [Causes potential infinite loop or undefined behavior when '-' is not expanded]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; @@ [Returns 2 for uppercase letters AND any other character (like '-', symbols), leading to false matches between non-alphanumeric chars]
}