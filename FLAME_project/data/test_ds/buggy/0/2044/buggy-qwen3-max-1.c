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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ [The condition should be s[i-1] < s[i+1], not <=, because expansion is only required when the character after '-' is greater than the one before it. Using <= allows cases like 'a-a' to be expanded, which violates the problem requirement.]
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ [When expanding, it should start from s[i-1] (the character before '-') and go up to s[pos-1], but here it starts from s[i], which is '-', leading to incorrect output. Also, the marked region includes '-', so s[i] is '-', and printing from '-' causes wrong characters.]
            i=pos-1; 
        }
    }
    return 0;
}