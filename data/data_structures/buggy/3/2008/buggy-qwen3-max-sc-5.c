#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; causes compilation error in modern compilers due to removal from C standard]
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){
        }
        n=1-i;
        printf("%d\n",i);
        for(j=0;i<=strlen(s);j++,i++){ // @@ [Loop condition 'i<=strlen(s)' may access beyond null terminator; also, missing null-termination of c[] leads to undefined behavior]
            c[j]=s[i];
        }
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){ // @@ [If input has no '.', this loop runs past end of string causing undefined behavior]
            c[i+1]=s[i];
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){ // @@ [Same issue: 'i<=strlen(s)' accesses s[strlen(s)] which is '\0', and then writes beyond valid digits; also c[] not null-terminated]
            c[i]=s[i];
        }
        printf("%se%d",c,n); // @@ [String c is not null-terminated in many paths, leading to garbage output or undefined behavior]
        return 0;
    }
}