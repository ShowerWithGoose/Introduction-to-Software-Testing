#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char str[120];
int main(){
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    int i;
    int k=0;
    if(str[0]=='0'){

    for(i=0;str[i]!='\0';i++){
    if(str[i]=='0'){
    k++;
    }
    if(str[i]!='0'&&str[i]!='.')
    break;
    }
    printf("%c.",str[i]); // @@ [If input is "0.0", this will access beyond valid significant digits or cause undefined behavior; also, does not handle case where all digits after decimal are zero (though problem says no trailing zeros)]
    for(i++;str[i]!='\0';i++){
    printf("%c",str[i]);
    }
    printf("e-%d",k); // @@ [Exponent calculation is incorrect; for "0.00123", k counts leading zeros including the one before decimal, but exponent should be -3, not -2 or -1 depending on count logic]
    }
    else{
    for(i=0;str[i]!='.'&&str[i]!='\0';i++)
    {}
    printf("%c.",str[0]); 
    for(k=1;str[k]!='\0';k++){
    if(str[k]!='.')printf("%c",str[k]);
    }
    printf("e%d",i-1); // @@ [If there's no decimal point in input (e.g., "123"), loop exits at '\0', so i = length, and exponent becomes length-1 which is correct, but code assumes decimal point always exists in non-zero-leading case, which may not hold per problem description]
    }

 
}