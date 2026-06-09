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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ [The condition should be s[i-1] < s[i+1], not <=, because expansion is only performed when the character after '-' is greater than the one before it. Using <= allows cases like 'a-a' which should not be expanded.]
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ [This loop prints from s[i] to s[pos-1], but s[i] is the first marked character (e.g., 'a'), and s[pos-1] is the last marked character (e.g., 'u'). However, in the case of multiple consecutive expansions like "a-uB-F", the marking logic incorrectly merges separate expansion segments. Also, the loop includes both endpoints, but the original characters are already part of the range, so this duplicates the start character if not handled carefully. More critically, the marking approach fails to handle non-contiguous expansions correctly because it marks all three characters (left, '-', right) and then tries to merge contiguous marked regions, which conflates separate expansions like "a-u" and "B-F" into one block if they are adjacent after processing.]
            i=pos-1; 
        }
    }
    return 0;
}