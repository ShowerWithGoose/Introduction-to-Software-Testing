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
    gets(c); // @@ [gets() is unsafe and deprecated; use fgets() instead, but this is not the main error]
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[2]); // @@ [This assumes there is always a non-zero digit at index 2, but if the number is "0.0...01", the first non-zero digit may be later; also, the loop above counts zeros but does not find the first non-zero digit correctly]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);} // @@ [This prints from index 3 onward, but if the first non-zero digit is at index s > 2, this will include leading zeros before the significant digit]
    else{pf("%s",&c[3]); // @@ [Same issue: c[3] may be out of bounds or include incorrect characters]
    
    }pf("e-%d",d+1); // @@ [The exponent should be -(s-1) where s is the index of the first non-zero digit after the decimal point, not d+1 where d is the count of zeros before the first non-zero digit]
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [This copies from index 1 onward, but if the number has more than one digit before the decimal point (e.g., "12.34"), this incorrectly removes the first digit from the base]
    pf("%c.",c[0]); // @@ [This always prints the first character as the base, but if the number is like "0.123", the base should be "1.23", not "0."; also, for numbers like "12.34", the base should be "1.234", not "1."]
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1); // @@ [The exponent should be (p-1) where p is the position of the decimal point, but b is the index of the decimal point; for numbers like "12.34", b=2, so exponent is 1, which is correct, but for "0.123", this branch is not taken]
}
    return 0;
}