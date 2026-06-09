#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){
        }
        n=1-i;
        printf("%d\n",i); // @@ [Unnecessary debug print that alters output format; also, i may go out of bounds if input is "0." or similar]
        for(j=0;i<=strlen(s);j++,i++){ // @@ [Loop condition should be i < strlen(s), not <=, to avoid copying null terminator incorrectly and potential buffer overflow]
            c[j]=s[i];
        }
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){ // @@ [If there's no '.' in input (e.g., integer input), this loop runs past string end causing undefined behavior]
            c[i+1]=s[i];
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){ // @@ [Same issue: should be i < strlen(s); also, after skipping '.', s[i] may be '\0', leading to incorrect copy]
            c[i]=s[i]; // @@ [Indexing error: c[i] uses original i which is too large; should use a separate index for c]
        }
        printf("%se%d",c,n); // @@ [Only prints in non-zero-leading case; missing print for zero-leading case, so program produces no output for inputs like "0.00123"]
        return 0;
    }
}