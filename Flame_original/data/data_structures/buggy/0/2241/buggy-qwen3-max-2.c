#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> // @@ [duplicate inclusion of stdio.h is unnecessary but not a compilation error; however, the real issue is missing function declaration scope and potential undefined behavior, but the actual compilation error stems from using C99-style for-loop variable declarations without proper standard compliance in some compilers. However, the primary critical error is that the function 'bigger' is declared without a parameter in its prototype but defined with one.]
int bigger(); // @@ [function declaration does not match definition: declared as taking no parameters, but defined as taking an int parameter. This causes a compilation error.]
char S[10000];
int main(){
    scanf("%s",S);
    for(int i=0;S[i]!='\0';i++){ // @@ [C99 feature; may cause compilation error if compiler defaults to older standard, but less likely than the function declaration mismatch. The main error is the function prototype.]
        if(S[i] != '-'){
            printf("%c",S[i]);
        }else bigger(i);
    }
    
    return 0;
}
int bigger(int i){
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