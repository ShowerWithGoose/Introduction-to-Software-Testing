#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) {
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { // @@ Checks character order before verifying they are of the same type, allowing mismatched types like 'B' and 'e' to enter the block.
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) { // @@ Should be 'else if' to prevent falling through to subsequent checks and the final 'else' block when a previous type matches.
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) { // @@ Should be 'else if' for the same reason as above.
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else { // @@ This 'else' is incorrectly attached only to the lowercase check instead of the overall expansion condition, causing it to trigger for mismatched types.
                i++; // @@ Incorrectly increments 'i', skipping the character after '-'. When expansion is invalid, the loop should just output '-' and continue.
                s[j]=ch[i]; // @@ Copies the character after '-' instead of '-', causing the '-' symbol to be omitted from the output.
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