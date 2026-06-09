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
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it includes the newline in some environments, but the main issue here is logic error in parsing]
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[2]); // @@ [This always prints c[2], but if the first non-zero digit is not at index 2 (e.g., "0.000..."), this prints '0', which is wrong. Should find first non-zero digit.]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);} // @@ [This prints from c[3] onward regardless of where the first non-zero digit is. It should print digits starting from after the first non-zero digit.]
    else{pf("%s",&c[3]);
    
    }pf("e-%d",d+1); // @@ [Exponent calculation is off: for "0.00000009...", d counts leading zeros after decimal, but exponent should be -(d+1) only if first non-zero is at position d+2. However, because code assumes first non-zero is at c[2], it fails when it's later. Also, if c[2] is '0', it prints '0' as significant digit, which is invalid.]
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [This copies from c[1] to end, including the decimal point and everything after. Later loop skips '.', but this approach is fragile and may include extra characters if input has no decimal? But problem says input always has decimal. Main issue: if number is like "123.45", this prints "1.2345e2" correctly? But what if input is "0.1"? That goes to first branch. However, if input is "1.0", but problem states no trailing zeros, so maybe ok. But the real bug is in the first branch.]
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1);
}
    return 0;
}