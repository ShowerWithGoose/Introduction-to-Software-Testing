#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> // @@ [duplicate inclusion of stdio.h is unnecessary but not a compilation error; however, the real issue is missing function declaration before use in older C standards]
int bigger(); // @@ [function declaration is present, but in C, if compiling in strict mode without recognizing implicit int or old-style declarations, this might not be enough; however, the actual compilation error likely stems from using 'for(int i=...)' in C89 mode where variable declaration in for loop is not allowed]
char S[10000];
int main(){
    scanf("%s",S);
    for(int i=0;S[i]!='\0';i++){ // @@ [declaring 'int i' inside the for loop initializer is invalid in C89/C90 standard, which many default compilers (like older gcc) use; this causes a compilation error]
        if(S[i] != '-'){
            printf("%c",S[i]);
        }else bigger(i);
    }
    
    return 0;
}
int bigger(int i){ // @@ [function definition is okay, but the prior call in main may cause issues if compiler doesn't support forward reference properly under strict C89]
    int a;
    if('0'<=S[i+1]&&S[i+1]<='9'&&'0'<=S[i-1]&&S[i-1]<='9'&&(a = S[i+1]-S[i-1])>0){
        for(int b=1;b<a;b++){ // @@ [declaring 'int b' inside for loop is also invalid in C89/C90, causing another compilation error]
            printf("%c",S[i-1]+b);
        }
    } else
if('a'<=S[i+1]&&S[i+1]<='z'&&'a'<=S[i-1]&&S[i-1]<='z'&&(a = S[i+1]-S[i-1])>0){
        for(int b=1;b<a;b++){ // @@ [same issue: variable declaration in for loop not allowed in C89]
            printf("%c",S[i-1]+b);
        }
    } else
if('A'<=S[i+1]&&S[i+1]<='Z'&&'A'<=S[i-1]&&S[i-1]<='Z'&&(a = S[i+1]-S[i-1])>0){
        for(int b=1;b<a;b++){ // @@ [same C89 incompatibility]
            printf("%c",S[i-1]+b);
        }
    }
    return 0;
}