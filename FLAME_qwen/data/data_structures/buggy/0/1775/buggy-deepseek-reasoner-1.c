#include<stdio.h>
#include<string.h>
char s[10010]={'\0'},b[100010]={'\0'};
int main(){
    int i,j=0;
    gets(s); // @@ Use of gets is unsafe and may cause buffer overflow, but not the main logical error.
    for(i=0;i<strlen(s);i++,j++){
        b[j]=s[i]; // @@ When i=0, s[i-1] is accessed later, but this line itself is fine; however, the out‑of‑bounds access on s[i-1] occurs in the following conditional.
        if(s[i]=='-'&&s[i+1]>s[i-1]){ // @@ s[i-1] is out of bounds when i=0 (first character). Also, if s[i+1] is the null terminator, s[i+1]>s[i-1] may cause issues.
            if((s[i-1]-'0'<=9&&s[i-1]-'0'>=0&&s[i+1]-'0'>=0&&s[i+1]-'\0'<=9)||(s[i-1]-'A'<=25&&s[i-1]-'A'>=0&&s[i+1]-'A'>=0&&s[i+1]-'A'<=25)||(s[i-1]-'a'<=25&&s[i-1]-'a'>=0&&s[i+1]-'a'>=0&&s[i+1]-'a'<=25)){
 // @@ The digit check uses s[i+1]-'\0' which is equivalent to s[i+1] (ASCII value), not s[i+1]-'0'. This breaks detection of numeric ranges (e.g., '0-9' will not expand). Also s[i-1] may be out of bounds.
                for(int k=1;k<s[i+1]-s[i-1];k++){
                    b[j]=s[i-1]+k;
                    j++;
                }
                b[j]=s[i+1];
                i++;
            }    
            
        }
    }
    puts(b);
    return 0;
}