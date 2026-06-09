#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { // @@ [Loop runs one iteration too far: `i <= strlen(ch)` accesses `ch[strlen(ch)]` which is the null terminator, and then `ch[i+1]` reads out-of-bounds. Should be `i < strlen(ch)`]
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { // @@ [When i=0, `ch[i-1]` is `ch[-1]`, which is invalid memory access. Also, when i = strlen(ch)-1, `ch[i+1]` is out of bounds. No bounds checking before accessing adjacent characters]
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) { // @@ [Should be `else if` to avoid overlapping checks; current code may process multiple cases incorrectly]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) { // @@ [Should be `else if`; also, the following `else` only pairs with this `if`, not the whole group, causing incorrect fallback behavior]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else {
                i++; // @@ [Incorrectly skips next character; also modifies loop variable inside loop, leading to skipped or duplicated processing]
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