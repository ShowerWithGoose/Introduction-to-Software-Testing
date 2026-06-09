#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { @@ Loop bound i<=strlen(ch) causes out-of-bounds access at i=strlen(ch); also ch[i-1] is invalid when i=0.
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { @@ Accessing ch[i-1] when i=0 causes undefined behavior.
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) { @@ Should be 'else if' to prevent incorrect fall-through to the final else block.
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) { @@ Should be 'else if'.
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) { @@ Should be 'else if'.
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else { @@ This else only pairs with the last if, causing logic errors for valid expansions and failing to output '-' for invalid ranges.
                i++;
                s[j]=ch[i];
                j++;
            }
        } else {
            s[j]=ch[i];
            j++;
        }
    }
    printf("%s",s); @@ String s lacks a null terminator ('\0'), causing undefined behavior when printing.
    return 0;
}