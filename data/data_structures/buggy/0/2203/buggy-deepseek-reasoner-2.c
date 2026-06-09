#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) { // @@ [No bounds check for i-1 and i+1; may access out-of-bounds if '-' at first or last position]
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { // @@ [Condition should be s[i-1] < s[i+1] (strictly less) per requirement]
            while(s[i-1]<s[i+1]) { // @@ [Loop should be while(s[i-1] < s[i+1]-1) to avoid printing the right character; current prints inclusive right]
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2; // @@ [Incorrect skip logic; after i+=2, the for loop's increment causes skipping more characters than intended]
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; // @@ [Decrementing i may cause infinite loop or incorrect processing; should just print '-' and continue]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; // @@ [Returns 2 for both uppercase letters and non‑alphanumeric characters; must return a distinct value for uppercase (e.g., 2) and another for others (e.g., 3) to correctly distinguish types]
}