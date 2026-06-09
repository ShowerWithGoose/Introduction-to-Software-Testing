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
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it includes the newline in some environments, but the main issue is logic errors below]
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[2]); // @@ [This prints c[2] regardless of whether it's zero or not. It should print the first non-zero digit after leading zeros, not c[2] specifically. For input "0.0000000912...", c[2] is '0', which is wrong.]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);} // @@ [This prints from c[3] onward, including any remaining zeros and digits, but it doesn't skip the leading zeros before the first significant digit. Also, if the first non-zero digit is beyond index 2, this fails completely.]
    else{pf("%s",&c[3]);
    
    }pf("e-%d",d+1); // @@ [The exponent calculation is incorrect. For "0.0000000912...", there are 7 leading zeros after decimal before '9', so exponent should be -8, but d counts all zeros from index 2 onward until end, not until first non-zero. Also, it always assumes first non-zero is at position d+2, which is wrong.]
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [This copies from c[1] to end into cc, but if the number has more than one digit before decimal (e.g., "123.45"), then c[0]='1', c[1]='2', etc., and copying from c[1] loses the second digit onward before the decimal point. Also, the decimal point is still in cc, which is handled later, but the logic is flawed for numbers like "10.5" where trailing zero before decimal is significant.]
    pf("%c.",c[0]);
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1); // @@ [For numbers like "123.45", b=3 (index of '.'), so exponent = 2, which is correct. But if input is "1.23", b=1, exponent=0, which is correct. However, the earlier strcpy includes digits after decimal and possibly extra characters, but the bigger issue is that this branch assumes the number has non-zero first digit and at least one digit before decimal, which is okay per problem, but the handling of cc is error-prone. However, the main failure is in the first branch, so this may work for some cases but isn't robust. Still, the critical errors are in the first branch.]
}
    return 0;
}