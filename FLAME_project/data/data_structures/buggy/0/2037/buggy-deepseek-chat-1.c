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
                j++; // @@ This line incorrectly increments j when no expansion occurs, causing the output to skip characters. For input "B-e", after copying 'B', the else branch executes, incrementing j, so the next character 'e' is written to S[2] instead of S[1], and the '-' is lost, resulting in "Be" instead of "B-e".
            }
            i++;j--;
        }
    }
    printf ("%s", S);
    return 0;
}