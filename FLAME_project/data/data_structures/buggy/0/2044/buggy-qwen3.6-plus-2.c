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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<s[i+1]){ // @@ The condition should be strict less than (<) instead of less than or equal to (<=). If the characters are equal (e.g., a-a), no expansion should occur, but <= would mark it for expansion. Although the problem says "greater than", typically a-a is not expanded. More importantly, the logic for expansion range relies on start < end.
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(pos <= strlen(s+1) && mk[pos])pos++; // @@ Added boundary check pos <= strlen(s+1) to prevent out-of-bounds access if the string ends with a marked sequence.
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j);
            i=pos-1; 
        }
    }
    return 0;
}