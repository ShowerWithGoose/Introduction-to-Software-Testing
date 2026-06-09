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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ Condition should be '<' not '<=' because expansion only occurs when the character after '-' is strictly greater than the one before it. Using '<=' may incorrectly mark cases where they are equal or cause issues with type mixing.
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ This loop prints from the first character of the first expansion to the last character of the last expansion, merging separate expansions and duplicating endpoints. It should handle each expansion individually, printing characters between endpoints without reprinting the endpoints.
            i=pos-1; // @@ Setting i to pos-1 then incrementing in for loop skips over the entire marked region but does not properly output the expansion characters. This logic fails for multiple expansions of different types.
        }
    }
    return 0;
}