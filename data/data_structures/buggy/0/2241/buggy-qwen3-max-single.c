#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> // @@ [duplicate inclusion of stdio.h is unnecessary but not a compilation error; however, the real issue is missing function declaration scope]
int bigger(); // @@ [function declaration does not match definition: declared with no parameters but defined with one int parameter]
char S[10000];
int main(){
    scanf("%s",S);
    for(int i=0;S[i]!='\0';i++){
        if(S[i] != '-'){
            printf("%c",S[i]);
        }else bigger(i); // @@ [calling bigger with argument, but declaration says no parameters - causes compilation error in strict C]
    }
    
    return 0;
}
int bigger(int i){ // @@ [definition has parameter, but prior declaration had none - mismatch causes compilation error]
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