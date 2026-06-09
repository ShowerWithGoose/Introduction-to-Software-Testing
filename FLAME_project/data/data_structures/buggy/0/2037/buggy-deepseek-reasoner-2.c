#include <stdio.h>

int main (){
    char s[200]={0},S[500]={0};
    scanf ("%s", s);
    for (int i=0,j=0;s[i]!='\0';i++,j++){
        S[j]=s[i];
        if (s[i+1]=='-'){
            if (s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){  // @@ Errors: (1) starts with ch=s[i] which duplicates left character, (2) condition should be ch <= s[i+2] to include right character.
                    S[j] = ch;
                }
            }else if (s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){  // @@ Same errors as above.
                    S[j] = ch;
                }                
            }else if (s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){
                for (char ch=s[i];ch<s[i+2];j++,ch++){  // @@ Same errors as above.
                    S[j] = ch;
                }                
            }else {
                j++;   // @@ Error: increments j without copying the '-' character, causing it to be omitted.
            }
            i++;   // @@ Error: always skips the dash in the input string, even when expansion is invalid (dash should be copied as normal character).
            j--;   // @@ Error: decrements j, interfering with the correct index for the next character, leading to concatenation like "Be" instead of "B-e".
        }
    }
    printf ("%s", S);
    return 0;
}