#include <stdio.h>

int main (){
    char s[200]={0},S[500]={0};
    scanf ("%s", s);
    for (int i=0,j=0;s[i]!='\0';i++,j++){
        S[j]=s[i];
        if (s[i+1]=='-'){
            if (s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){ // @@ This condition misses the check that s[i] < s[i+2]; if left > right, expansion should not happen.
                for (char ch=s[i];ch<s[i+2];j++,ch++){ // @@ Begins duplication of first character; should start from s[i]+1.
                    S[j] = ch;
                }
            }else if (s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){ // @@ Same missing less-than check.
                for (char ch=s[i];ch<s[i+2];j++,ch++){ // @@ Same duplication error.
                    S[j] = ch;
                }                
            }else if (s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){ // @@ Same missing less-than check.
                for (char ch=s[i];ch<s[i+2];j++,ch++){ // @@ Same duplication error.
                    S[j] = ch;
                }                
            }else {
                j++; // @@ Does not copy the '-' character; should copy s[i+1] to S[j] and increment j.
            }
            i++;j--; // @@ Incorrectly modifies loop counters; leads to skipping characters and incorrect indexing. The loop's own increment (i++,j++) further compounds the error.
        }
    }
    printf ("%s", S);
    return 0;
}