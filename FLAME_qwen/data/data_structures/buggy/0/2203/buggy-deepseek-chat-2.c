#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { // @@ Error: When i=0, s[i-1] accesses index -1, causing undefined behavior. Also, the condition should be s[i-1] < s[i+1] (strictly less), not <=, to match the problem requirement that the character after '-' must be greater than the one before.
            while(s[i-1]<s[i+1]) { // @@ Error: This loop increments s[i-1] and prints characters, but it modifies the original string, which can cause issues. Also, it prints the characters in the wrong order (starting from the character after the first one, not including the first character). The correct expansion should print from s[i-1]+1 to s[i+1]-1.
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2; // @@ Error: This skips the character after '-', but the loop increment i++ will also execute, causing incorrect index advancement. The logic for handling the expansion is flawed.
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; // @@ Error: This decrements i when encountering a '-' that wasn't expanded, but this can lead to an infinite loop or incorrect behavior because i will be decremented and then incremented by the loop, potentially reprocessing the same character.
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