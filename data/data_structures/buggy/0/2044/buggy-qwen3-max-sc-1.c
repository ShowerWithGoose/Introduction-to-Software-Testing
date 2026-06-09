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
    scanf("%s",s+1); // @@ [The program uses 1-based indexing for string input, but standard C strings are 0-terminated and expected to start at index 0. This causes undefined behavior when accessing s[i-1] for i=1 (i.e., s[0] is uninitialized) and may lead to incorrect comparisons or buffer overreads. Additionally, strlen(s+1) is incorrect because s+1 skips the first character, but the string was read starting at s+1, so the actual string starts at s[1], making s[0] garbage. This leads to logic errors in expansion detection.]
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
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j);
            i=pos-1; 
        }
    }
    return 0;
}