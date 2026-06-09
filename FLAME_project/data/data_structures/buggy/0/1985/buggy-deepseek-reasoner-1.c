#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) {
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) {
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
            } else { // @@ This else incorrectly handles the case where the characters are not of the same type. It should simply output the '-' character, but instead it increments i and adds the next character, causing the '-' to be skipped and the right character to be added prematurely, leading to wrong output.
                i++; // @@ Incorrectly increments i, causing the loop to skip the '-' and the following character to be processed out of order.
                s[j]=ch[i]; // @@ Adds the next character (after '-') instead of the '-' itself.
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