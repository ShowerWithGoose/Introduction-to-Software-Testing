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
    for(int i=1;i<=strlen(s+1);i++){ // @@ strlen() is called in every iteration causing O(N^2) complexity; comparing int with size_t may cause compilation warnings/errors in strict environments.
        if(s[i]=='-'){
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ The problem specifies expansion only when the character after '-' is strictly greater than the one before it, so '<=' should be '<'.
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){ // @@ Same issue as above: repeated strlen() calls and int/size_t comparison.
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ Using 'char' for loop variable j can cause overflow and infinite loop if s[pos-1] is 127 (max signed char); should use 'int'.
            i=pos-1; 
        }
    }
    return 0;
}