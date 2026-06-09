#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { // @@ [Loop runs one step too far: `i <= strlen(ch)` includes the null terminator, causing out-of-bound access when checking `ch[i+1]` at the last character. Should be `i < strlen(ch)`.]
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { // @@ [Does not validate that both sides of '-' are of the same type (e.g., digit/digit, letter/letter). Also accesses `ch[i-1]` when i=0, which is invalid.]
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else {
                i++; // @@ [This `else` only applies to the last `if` (lowercase), not all three type checks. So if it's not lowercase but is uppercase or digit, this `else` incorrectly executes. Also, `i++` skips next character and may cause misalignment.]
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