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
        else i--; // @@ [Accessing s[i-1] and s[i+1] when i=0 or i=len-1 leads to out-of-bounds array access, causing undefined behavior. Additionally, the logic for skipping processed characters is flawed and may cause infinite loops or missed characters.]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; // @@ [This function returns 2 for uppercase letters as well as for any other character (like '-', symbols, etc.), which violates the requirement that expansion only occurs between same-type valid characters. It should return distinct values or validate input types properly.]
}