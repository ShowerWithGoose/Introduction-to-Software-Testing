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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++; // @@ Incorrectly merges adjacent valid expansion ranges into a single contiguous block, causing separate ranges like 'a-u' and 'B-F' to be treated as one.
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ Attempts to expand from the first character of the merged block to the last, which fails when the starting character is lexicographically greater than the ending character (e.g., 'a' > 'F').
            i=pos-1; 
        }
    }
    return 0;
}