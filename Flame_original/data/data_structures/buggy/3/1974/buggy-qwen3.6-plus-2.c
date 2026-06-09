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
    gets(c); // @@ gets is deprecated and removed in modern C standards, causing compilation errors; use scanf("%s", c) instead.
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){ // @@ Counts all zeros after index 2 instead of only consecutive leading zeros, leading to incorrect exponent calculation.
                d++;
            }}
            
    pf("%c",c[2]); // @@ Assumes the first significant digit is always at index 2, which fails for inputs like "0.05"; should dynamically find the first non-zero digit.
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);} // @@ Prints from a fixed index 3 instead of the position after the first significant digit, resulting in an incorrect mantissa.
    else{pf("%s",&c[3]);
    
    }pf("e-%d",d+1); // @@ Exponent calculation is incorrect because d counts all zeros after index 2 rather than just the leading zeros after the decimal point.
    
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