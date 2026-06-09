#include <stdio.h>

int main (){
    char s[200]={0},S[500]={0};
    scanf ("%s", s);
    for (int i=0,j=0;s[i]!='\0';i++,j++){
        S[j]=s[i]; // @@ Unconditionally copies the current character, causing duplication when an expansion follows. It should only copy when s[i+1] != '-'.
        if (s[i+1]=='-'){
            if (s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){ // @@ Starts expansion from s[i], which duplicates the character already stored in S[j]. Should start from s[i] + 1.
                    S[j] = ch;
                }
            }else if (s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){ // @@ Same duplication error as above.
                    S[j] = ch;
                }                
            }else if (s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){ // @@ Same duplication error as above.
                    S[j] = ch;
                }                
            }else {
                j++; // @@ Incorrectly increments j when no expansion occurs, creating a gap in S since S[j]=s[i] already copied the character and the outer loop increments j again.
            }
            i++;j--; // @@ Flawed index adjustment. Unconditionally skips the '-' character even when no expansion occurs, and misaligns j for subsequent characters.
        }
    }
    printf ("%s", S);
    return 0;
}