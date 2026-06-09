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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ Should be '<' instead of '<=' because expansion requires left character strictly less than right character. Using '<=' allows expansion when left equals right, which is incorrect per problem description.
                mk[i-1]=mk[i]=mk[i+1]=1; // @@ Marking all three positions as 1 causes separate expansions (e.g., "a-u" and "B-F") to merge into one contiguous block when they are adjacent, even if they are of different types. This leads to incorrect output.
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ This loop assumes the entire marked block represents a single expansion range from s[i] to s[pos-1]. When multiple expansions of different types are merged, the start character may be larger than the end character (e.g., 'a' > 'F'), causing no output. Moreover, the range may include characters outside the intended expansions (e.g., if start < end but types differ, many unintended characters are printed).
            i=pos-1;
        }
    }
    return 0;
}