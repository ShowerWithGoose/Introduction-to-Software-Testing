#include <stdio.h>

int main (){
    char s[200]={0},S[500]={0};
    scanf ("%s", s);
    for (int i=0,j=0;s[i]!='\0';i++,j++){
        S[j]=s[i];
        if (s[i+1]=='-'){
            if (s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){
                    S[j] = ch;
                }
            }else if (s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){
                    S[j] = ch;
                }                
            }else if (s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){
                    S[j] = ch;
                }                
            }else {
                j++; // @@ [This increments j unnecessarily; it causes skipping of the next character and leads to incorrect output. Also, after this, i++ and j-- may cause misalignment.]
            }
            i++;j--; // @@ [The j-- here cancels one increment, but combined with the earlier j++ in the else block or loop update, it leads to incorrect indexing. Additionally, when expansion occurs, the loop's j++ (from for-loop) plus manual j++ in for-body causes double increment, and then j-- only partially compensates, leading to off-by-one errors.]
        }
    }
    printf ("%s", S);
    return 0;
}