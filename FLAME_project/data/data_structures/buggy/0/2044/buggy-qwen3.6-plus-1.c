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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ The condition should be s[i-1] < s[i+1] (strictly less than) because if they are equal, no expansion is needed and it might cause issues or just output the char twice depending on logic, but more importantly, the problem states "character after ... is greater than the one before". Using <= allows equal characters which shouldn't trigger expansion logic in the same way or is redundant. However, the critical error is usually that if s[i-1] == s[i+1], it marks them for expansion but the loop below prints from s[i-1] to s[pos-1]. If equal, it prints once. But standard expansion rules say "greater than". Let's look closer. If input is a-a, output should be a-a? Or a? The problem says "greater than". So <= is wrong, it must be <.
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