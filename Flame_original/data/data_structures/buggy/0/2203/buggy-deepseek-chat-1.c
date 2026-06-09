#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { // @@ Error: When i=0, s[i-1] accesses out-of-bounds memory; also condition should be s[i-1] < s[i+1] (strictly less) not <=
            while(s[i-1]<s[i+1]) { // @@ Error: This loop modifies s[i-1] which corrupts the original string and may cause incorrect output; also it prints characters including the last one which should not be printed
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2; // @@ Error: This skips the next character after '-', but the loop increment i++ will also run, causing incorrect index advancement
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; // @@ Error: This decrements i when encountering '-', causing infinite loop or incorrect behavior
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