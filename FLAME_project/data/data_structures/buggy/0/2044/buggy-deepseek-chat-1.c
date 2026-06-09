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
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ The condition should be s[i-1] < s[i+1] (strictly less than), not <=. According to the problem, expansion only occurs when the character after '-' is greater than the one before it.
                mk[i-1]=mk[i]=mk[i+1]=1;
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++;
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ This loop includes the starting character s[i] again, but s[i] has already been printed when mk[i]==0 was false? Actually, the logic is flawed: when mk[i]==1, it enters the else branch and prints from s[i] to s[pos-1], but s[i] is the first character of the range and should not be printed again if it was already output. However, the main issue is that the loop prints the entire range including the start and end characters, but the start character s[i] might have been printed earlier when mk[i]==0 was false? No, mk[i]==1 means it's part of the expansion, so it hasn't been printed. But the problem is that the loop prints from s[i] to s[pos-1], which includes both endpoints, but the expansion should only include the characters between them (excluding the endpoints if they are already in the string). Actually, the reference program shows that the endpoints are kept and the middle is expanded. Here, the code marks all three positions (i-1, i, i+1) as 1, then in the output loop, when it encounters a marked position, it prints the entire range from s[i] to s[pos-1], which includes the start and end characters. But the start character s[i] is the first character of the range (e.g., 'a' in "a-u"), and it will be printed again when the loop runs, causing duplication. The correct approach is to print only the expansion characters (from s[i]+1 to s[pos-1]-1) and then skip to the end character. The current logic prints the entire range including both endpoints, leading to wrong output.
            i=pos-1; 
        }
    }
    return 0;
}