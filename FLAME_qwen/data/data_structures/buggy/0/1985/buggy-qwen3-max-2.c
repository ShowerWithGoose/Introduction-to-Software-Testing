#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { // @@ [Loop runs one iteration too far: i<=strlen(ch) accesses ch[strlen(ch)] which is '\0', and then ch[i+1] reads beyond the string boundary causing undefined behavior. Should be i < strlen(ch).]
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { // @@ [When i=0, ch[i-1] accesses ch[-1], which is invalid memory. Also, when i = strlen(ch)-1, ch[i+1] is out of bounds. Need to ensure i>0 and i<strlen(ch)-1 before accessing neighbors.]
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) { // @@ [This should be 'else if' to avoid overlapping checks; otherwise, after handling digits, it may incorrectly process uppercase or lowercase even if not applicable.]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) { // @@ [Same issue: should be 'else if' to maintain mutual exclusivity among type checks.]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else {
                i++; // @@ [This increments loop variable inside loop body, which can skip characters or cause misalignment. Also, this 'else' only pairs with the last 'if', not the whole group — logic error.]
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