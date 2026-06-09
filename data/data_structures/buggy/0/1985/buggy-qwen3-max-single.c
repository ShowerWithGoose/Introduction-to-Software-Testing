#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { // @@ [Loop runs one iteration too far: i<=strlen(ch) accesses ch[strlen(ch)] which is '\0', and then ch[i+1] reads beyond the string boundary, causing undefined behavior. Should be i < strlen(ch).]
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { // @@ [When i=0, ch[i-1] is ch[-1], which is invalid memory access. Also, when i is at the last character (due to loop condition), ch[i+1] is out of bounds. Need to ensure i>0 and i<strlen(ch)-1 before accessing ch[i-1] and ch[i+1].]
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) { // @@ [This should be 'else if' to avoid overlapping checks. As written, if a digit range matches, it may also incorrectly match uppercase or lowercase due to ASCII values (e.g., '9' is 57, 'A' is 65 — not overlapping, but logic is still flawed because multiple conditions could be true only if types match, but using separate 'if's allows fall-through to later blocks even when earlier ones matched. However, more critically, the final 'else' only applies to the last 'if', not the whole group.]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) { // @@ [Same issue: should be 'else if'. Also, the following 'else' block is attached only to this 'if', so if the first two 'if's fail but this one also fails, it executes the else — but if any prior 'if' succeeded, this 'if' might still fail and trigger the else incorrectly. This leads to wrong output for valid expansions in digits or uppercase.]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else {
                i++; // @@ [This modifies loop variable inside the loop, causing skipped characters and potential out-of-bounds access. Also, it only handles the case when the last 'if' fails, not when expansion conditions aren't met overall. Moreover, it writes ch[i] after incrementing i, which may be unintended.]
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