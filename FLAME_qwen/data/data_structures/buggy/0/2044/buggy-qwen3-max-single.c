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
    scanf("%s",s+1); // @@ [Reading input into s+1 leaves s[0] uninitialized; this causes undefined behavior when accessing s[i-1] for i=1 (i.e., s[0]) which is not part of the input string.]
    for(int i=1;i<=strlen(s+1);i++){
        if(s[i]=='-'){
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ [Accessing s[i+1] when i equals strlen(s+1) leads to out-of-bounds read (buffer overread), because valid indices are from 1 to strlen(s+1), and s[i+1] would be beyond the null terminator.]
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ [This loop assumes that the marked segment starts at a character to expand and ends at the upper bound, but the marking logic only marks three positions (i-1, i, i+1) for a single '-', so for consecutive expansions or complex cases, this logic fails. Also, if s[i] > s[pos-1], the loop condition fails or becomes infinite due to char signedness.]
            i=pos-1; 
        }
    }
    return 0;
}