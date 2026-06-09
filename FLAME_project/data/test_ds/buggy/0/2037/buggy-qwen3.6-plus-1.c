#include <stdio.h>

int main (){
    char s[200]={0},S[500]={0};
    scanf ("%s", s);
    for (int i=0,j=0;s[i]!='\0';i++,j++){
        S[j]=s[i];
        if (s[i+1]=='-'){
            if (s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){ // @@ [Error: The loop starts from s[i] instead of s[i]+1, causing duplication of the first character, and uses ch<s[i+2] instead of ch<=s[i+2], omitting the last character.]
                    S[j] = ch;
                }
            }else if (s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){ // @@ [Error: The loop starts from s[i] instead of s[i]+1, causing duplication of the first character, and uses ch<s[i+2] instead of ch<=s[i+2], omitting the last character.]
                    S[j] = ch;
                }                
            }else if (s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){ // @@ [Error: The loop starts from s[i] instead of s[i]+1, causing duplication of the first character, and uses ch<s[i+2] instead of ch<=s[i+2], omitting the last character.]
                    S[j] = ch;
                }                
            }else {
                j++; // @@ [Error: When expansion conditions are not met, the '-' character is skipped and not copied to the output string S. It should assign S[j] = '-' before incrementing j to preserve the '-' in the output.]
            }
            i++;j--;
        }
    }
    printf ("%s", S);
    return 0;
}