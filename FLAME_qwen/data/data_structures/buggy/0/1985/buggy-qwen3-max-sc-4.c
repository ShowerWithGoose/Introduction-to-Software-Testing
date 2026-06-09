#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { @@ [Loop runs one iteration too far: i should be < strlen(ch), not <=, to avoid accessing ch[strlen(ch)] which is '\0' and then ch[i+1] becomes out-of-bounds]
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { @@ [Accesses ch[i-1] when i=0 (undefined behavior) and ch[i+1] when i = strlen(ch) (out-of-bounds); also fails to check if surrounding chars are of same valid type before comparing]
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) { @@ [Should be 'else if' to avoid overlapping checks; current structure allows multiple expansions or incorrect handling]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) { @@ [Should be 'else if'; also, the following 'else' only pairs with this last 'if', not the whole group]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else {
                i++; @@ [Incorrectly skips next character; also modifies loop variable inside loop, causing missed processing]
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