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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ The condition should be '<' not '<=' to avoid expansion when characters are equal.
                mk[i-1]=mk[i]=mk[i+1]=1; // @@ Marking all three indices causes adjacent expansion ranges to merge into one block, leading to incorrect output when ranges are of different types.
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ This loop assumes a single contiguous expansion block and prints from first character to last, which fails when ranges are not contiguous or of different types.
            i=pos-1; 
        }
    }
    return 0;
}