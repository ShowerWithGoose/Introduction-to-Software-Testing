#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
int main(){
    char c[105];
    char cc[105];
    gets(c);
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){ // @@ Loop should break when first non-zero digit is found to count only leading zeros.
            if(c[b]=='0'){ // @@ Should only count leading zeros; missing break prevents proper counting.
                d++;
            }}
            
    pf("%c",c[2]); // @@ Should output the first non-zero digit, not necessarily c[2].
    if(c[3]!='\0'){ // @@ Condition should be based on whether there are digits after the first non-zero digit.
    
    pf(".");pf("%s",&c[3]);} // @@ Incorrect base: should print decimal point and remaining digits after first non-zero digit.
    else{pf("%s",&c[3]); // @@ Incorrect handling; should not print decimal point if no more digits.
    
    }pf("e-%d",d+1); // @@ Exponent uses d+1, but d is not the correct count of leading zeros.
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]);
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1);
}
    return 0;
}