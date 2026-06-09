#include <stdio.h>
#include <string.h>

char s[100005];
int mk[100005];
int t(char a){
    if(a>='a'&&a<='z')return 1;
    if(a>='A'&&a<='Z')return 2;
    if(a>='0'&&a<='9')return 3;
    return -1;
}
int main() {
    scanf("%s",s+1);
    for(int i=1;i<=strlen(s+1);i++){
        if(s[i]=='-'){
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ The problem requires the character after '-' to be strictly greater than the one before it, so '<' should be used instead of '<='.
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++; // @@ This incorrectly merges adjacent valid expansion ranges into a single continuous block, which breaks the logic when multiple ranges are next to each other.
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ Due to the merged block, the starting character may be greater than the ending character (e.g., 'a' > 'F'), causing the loop condition to fail immediately and produce empty output.
            i=pos-1;
        }
    }
    return 0;
}