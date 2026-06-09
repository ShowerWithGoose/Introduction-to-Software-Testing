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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ The condition should be s[i-1] < s[i+1] (strictly less than), not <=. According to the problem, expansion only occurs when the character after '-' is greater than the one before it. Using <= would incorrectly expand when they are equal (e.g., a-a), which should output unchanged.
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ This loop includes both endpoints s[i] and s[pos-1], but s[i] and s[pos-1] are the characters before and after the '-', which should not be printed again because they are already printed when mk[i]==0 (since they are not marked? Actually they are marked, so they are skipped in the mk[i]==0 branch. However, the loop starts from s[i] and goes to s[pos-1], which includes the starting character. But the starting character should be printed only once, and the ending character should be printed only once. The problem is that the loop includes both endpoints, but the starting character s[i] is the character before the first '-', and s[pos-1] is the character after the last '-'. For a single expansion like a-d, i points to 'a', pos-1 points to 'd', and the loop prints a,b,c,d. But 'a' and 'd' are already printed? Actually 'a' is marked and skipped, so it's not printed elsewhere, so printing it here is correct. However, for multiple expansions like a-uB-F, the logic fails because the loop treats the entire marked range as one expansion, but the marked range may contain multiple '-' and characters that are not part of a single expansion sequence. The marking approach is flawed because it marks all characters in the expansion range, but then the output loop tries to print a continuous range from the first marked character to the last marked character, which may include characters that should not be expanded together (e.g., 'u' and 'B' are different types, so they should not be expanded). The correct approach is to handle each '-' individually, not mark a contiguous block.
            i=pos-1; 
        }
    }
    return 0;
}