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
    scanf("%s",s+1); // @@ [Reading input into s+1 leaves s[0] uninitialized; later strlen(s+1) may work, but indexing from 1 complicates logic and risks out-of-bounds access when checking s[i+1] near the end]
    for(int i=1;i<=strlen(s+1);i++){
        if(s[i]=='-'){
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ [When i is at the last character, s[i+1] accesses beyond the string boundary (undefined behavior). Also, if '-' is at the end (e.g., "a-"), s[i+1] is '\0', which fails type check but still causes invalid read]
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ [If expansion range is large (e.g., 'a' to 'z'), this loop works, but if s[i] > s[pos-1] (shouldn't happen due to earlier check), it could loop infinitely or incorrectly. However, main issue is that s[i] might not be the start of the range — e.g., in "a-c-e", overlapping marks may cause wrong expansion]
            i=pos-1; 
        }
    }
    return 0;
}