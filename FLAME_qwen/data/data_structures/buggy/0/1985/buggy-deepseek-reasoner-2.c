#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { // @@ Loop goes up to strlen(ch) inclusive, causing out-of-bounds access for ch[i+1] when i = strlen(ch)-1 and ch[i-1] when i = 0; also processes the null terminator.
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) {
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i-1]-1; k++) { // @@ Uses ch[i-1] instead of ch[i+1] for the upper bound, causing an incorrect or empty loop.
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) {
                for(int k=ch[i-1]+1; k<=ch[i-1]-1; k++) { // @@ Same mistake: should be ch[i+1].
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) {
                for(int k=ch[i-1]+1; k<=ch[i-1]-1; k++) { // @@ Same mistake: should be ch[i+1].
                    s[j]=k;
                    j++;
                }
            } else { // @@ This else is attached only to the third if, causing it to execute even when a previous if (digit or uppercase) was true. Should use else if chain.
                i++; // @@ Incorrectly increments i, skipping the hyphen character.
                s[j]=ch[i]; // @@ After increment, adds the character after the hyphen, but the hyphen itself is not output.
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