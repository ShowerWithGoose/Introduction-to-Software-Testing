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
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[2]); // @@ Error: This assumes the first non-zero digit is always at index 2, but for input "0.00000009123456789012", the first non-zero digit '9' is at index 8, not 2. This causes the wrong base to be printed.
    if(c[3]!='\0'){ // @@ Error: This assumes the first non-zero digit is at index 2, so it starts printing from index 3. For the given input, this prints "000009123456789012" instead of "123456789012".
    
    pf(".");pf("%s",&c[3]);} // @@ Error: Same issue as above; the substring starting from index 3 includes leading zeros that should not be part of the base.
    else{pf("%s",&c[3]);
    
    }pf("e-%d",d+1); // @@ Error: The exponent calculation is incorrect. For input "0.00000009123456789012", d counts 7 zeros after the decimal point, so d+1 = 8, but the correct exponent is -8 (since 9.123456789012e-8). The exponent should be -(d+2) because the first non-zero digit is at index d+2, not d+1.
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ Error: This copies from index 1, which includes the decimal point and all subsequent characters. For numbers like "123.456", this copies "23.456", but the base should be "1.23456". The logic for handling numbers with non-zero first digit is flawed.
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1); // @@ Error: The exponent calculation is incorrect. For "123.456", b is the index of the decimal point (3), so b-1 = 2, but the correct exponent is 2 (since 1.23456e2). However, for numbers like "1.23", b=1, b-1=0, which is correct. But the overall logic fails for numbers with more than one digit before the decimal point because the base is incorrectly constructed.
}
    return 0;
}