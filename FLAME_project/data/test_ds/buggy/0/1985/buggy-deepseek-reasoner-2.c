#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) {
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { // @@ Condition does not check that both characters belong to the same character type (lowercase, uppercase, or digit); for input "B-e" it enters this block even though 'B' (uppercase) and 'e' (lowercase) are of different types.
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
            } else { // @@ This else is attached only to the third if condition (lowercase check). When the characters are of different types (e.g., 'B' and 'e'), none of the three type-specific ifs are true, so this else executes. It incorrectly increments i and copies ch[i] (the character after the dash) without copying the dash itself, causing the dash to be omitted from output.
                i++;
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