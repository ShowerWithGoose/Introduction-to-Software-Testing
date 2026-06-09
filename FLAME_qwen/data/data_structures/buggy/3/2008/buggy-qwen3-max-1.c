#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){
        }
        n=1-i;
        printf("%d\n",i); // @@ [Unnecessary debug print that alters output format; violates output specification]
        for(j=0;i<=strlen(s);j++,i++){ // @@ [Loop condition i<=strlen(s) causes out-of-bounds access; should be i<strlen(s)]
            c[j]=s[i];
        }
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){ // @@ [If input has no decimal point, this loop runs past string end causing undefined behavior]
            c[i+1]=s[i];
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){ // @@ [Loop condition i<=strlen(s) writes null terminator incorrectly and may access out-of-bounds]
            c[i]=s[i];
        }
        printf("%se%d",c,n); // @@ [Missing newline in output; also only prints in else branch, not in if branch]
        return 0;
    }
}