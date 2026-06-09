#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in many modern compilers, 'gets' is removed leading to compilation error]
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){
        }
        n=1-i;
        printf("%d\n",i);
        for(j=0;i<=strlen(s);j++,i++){
            c[j]=s[i]; // @@ [Loop condition 'i<=strlen(s)' causes reading past the null terminator when i == strlen(s), leading to undefined behavior; also, c is not null-terminated after this loop]
        }
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){
            c[i+1]=s[i];
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){
            c[i]=s[i]; // @@ [Loop condition 'i<=strlen(s)' writes beyond valid input (s[strlen(s)] is '\0'), and c is not properly null-terminated; also, overlapping assignment may corrupt data]
        }
        printf("%se%d",c,n); // @@ [If the 'else' branch executes, it prints and returns, but if the 'if' branch executes, there's no corresponding print or return, leading to missing output and undefined behavior]
        return 0;
    }
}