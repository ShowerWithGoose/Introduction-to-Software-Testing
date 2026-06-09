#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { // @@ [Loop runs one iteration too far: `i <= strlen(ch)` accesses `ch[strlen(ch)]` which is the null terminator, and then `ch[i+1]` becomes out-of-bounds when i == strlen(ch). Should be `i < strlen(ch)`]
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { // @@ [When i=0, `ch[i-1]` accesses `ch[-1]`, which is invalid memory. Also, when i = strlen(ch)-1, `ch[i+1]` is `ch[strlen(ch)]` (null terminator), which may cause incorrect comparisons or undefined behavior]
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) { // @@ [This should be `else if` to avoid overlapping checks; otherwise, a digit range might also pass an uppercase check incorrectly due to ASCII values]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) { // @@ [Same issue: should be `else if`; also, the following `else` only applies to this last `if`, not the whole group, so non-matching cases in digit/uppercase won't trigger the else]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else {
                i++; // @@ [This increments `i` inside the loop, causing the next character to be skipped. Also, it writes `ch[i]` (now the character after '-') into output, but the '-' itself was never output, and this logic doesn't match the requirement of outputting the original string unchanged for invalid expansions]
                s[j]=ch[i];
                j++;
            }
        } else {
            s[j]=ch[i];
            j++;
        }
    }
    printf("%s",s);
    return 0;
}