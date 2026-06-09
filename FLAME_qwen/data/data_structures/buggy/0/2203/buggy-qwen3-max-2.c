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
        else i--; // @@ [When i is 0, s[i-1] accesses s[-1], causing undefined behavior. Also, after expanding (e.g., a-d), the loop skips printing the character after '-', but the logic for handling non-expansion cases and loop control is flawed, leading to incorrect output or infinite loops. Additionally, when expansion condition fails, '-' should be printed, but current logic may skip it or cause index underflow.]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; // @@ [This returns 2 for uppercase letters AND any other character (like '-', symbols, etc.), which causes incorrect type matching. For example, 'A' and '-' would both return 2, falsely considered same type. Should return distinct values or validate only allowed types.]
}