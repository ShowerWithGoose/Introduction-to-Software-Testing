#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { // @@ [Loop runs one step too far: i<=strlen(ch) accesses ch[strlen(ch)] which is '\0', and then ch[i+1] becomes out-of-bounds when i == strlen(ch). Also, when i=0, ch[i-1] accesses ch[-1], causing undefined behavior.]
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { // @@ [Accesses ch[i-1] and ch[i+1] without checking bounds (i>0 and i<strlen(ch)-1), leading to potential buffer underflow/overflow.]
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) { // @@ [Should be 'else if' to avoid overlapping checks; current logic may process same '-' multiple times if conditions overlap (though unlikely due to ASCII ranges, it's logically incorrect per problem spec).]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) { // @@ [Same issue: should be 'else if'; also, the following 'else' only pairs with this last 'if', not the whole group, so invalid cases in digit/uppercase won't trigger the else block.]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else {
                i++; // @@ [Incorrectly increments i, skipping next character; also, logic is misplaced—it should output '-' and surrounding chars unchanged, not skip ahead.]
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