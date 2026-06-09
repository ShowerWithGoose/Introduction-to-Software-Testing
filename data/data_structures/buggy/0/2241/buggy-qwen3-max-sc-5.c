#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> // @@ [duplicate inclusion of stdio.h is unnecessary but not a compilation error; however, the real issue is missing function declaration scope and potential undefined behavior, but the actual compilation error stems from using C99-style for-loop variable declarations without proper standard compliance in some compilers. However, the primary critical error is that the function 'bigger' is declared without a parameter in its prototype but defined with one.]
int bigger(); // @@ [function declaration does not match definition: declared as taking no parameters, but defined as taking an int parameter]
char S[10000];
int main(){
    scanf("%s",S);
    for(int i=0;S[i]!='\0';i++){ // @@ [C99 feature; may cause compilation error if compiler doesn't support it, but more critically, the call to bigger(i) expects a function that takes an int, but the declaration says it takes none]
        if(S[i] != '-'){
            printf("%c",S[i]);
        }else bigger(i); // @@ [calling bigger with argument, but its prior declaration says it takes no arguments — this mismatch causes a compilation error]
    }
    
    return 0;
}
int bigger(int i){ // @@ [definition expects an int parameter, but earlier declaration said no parameters — this inconsistency causes a compilation error]
    int a;
    if('0'<=S[i+1]&&S[i+1]<='9'&&'0'<=S[i-1]&&S[i-1]<='9'&&(a = S[i+1]-S[i-1])>0){
        for(int b=1;b<a;b++){
            printf("%c",S[i-1]+b);
        }
    } else
if('a'<=S[i+1]&&S[i+1]<='z'&&'a'<=S[i-1]&&S[i-1]<='z'&&(a = S[i+1]-S[i-1])>0){
        for(int b=1;b<a;b++){
            printf("%c",S[i-1]+b);
        }
    } else
if('A'<=S[i+1]&&S[i+1]<='Z'&&'A'<=S[i-1]&&S[i-1]<='Z'&&(a = S[i+1]-S[i-1])>0){
        for(int b=1;b<a;b++){
            printf("%c",S[i-1]+b);
        }
    }
    return 0;
}