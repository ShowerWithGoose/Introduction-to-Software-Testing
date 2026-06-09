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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ Error: The condition should be s[i-1] < s[i+1] (strictly less than), not <=. According to the problem, expansion should only occur when the character after '-' is greater than the one before it. Using <= would incorrectly expand when they are equal (e.g., a-a), which is not allowed.
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ Error: This loop includes both endpoints s[i] and s[pos-1], but the original characters at these positions are already printed or marked. The expansion should only include characters between s[i] and s[pos-1] (exclusive of the endpoints), because the endpoints are the original characters that should not be duplicated. For example, for "a-d", the output should be "abcd", but this code would print "a" from the first iteration, then "abcd" from the expansion, resulting in "aabcd". The correct approach is to print the start character once, then expand from s[i]+1 to s[pos-1]-1, then print the end character.
            i=pos-1; 
        }
    }
    return 0;
}