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
    gets(c); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow. Use fgets() instead.]
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[2]); // @@ [If the input is "0.0", c[2] is '0', but the first non-zero digit should be found; this logic is incorrect for cases like "0.001".]
    if(c[3]!='\0'){
    
    pf(".");pf("%s",&c[3]);} // @@ [This prints everything from index 3, but may include trailing zeros or incorrect digits; also, if c[3] is '\0', the else branch prints an empty string incorrectly.]
    else{pf("%s",&c[3]); // @@ [When c[3] is '\0', printing an empty string is unnecessary and may cause issues.]
    
    }pf("e-%d",d+1); // @@ [The exponent calculation d+1 is incorrect; it should be based on the position of the first non-zero digit after the decimal point, not just counting zeros.]
    
    }

else{
    for(b=0;b<strlen(c);b++){
        if(c[b]=='.'){
            break;
        }
    }
    strcpy(cc,&c[1]); // @@ [This copies from index 1, but if the number has more than one digit before the decimal (e.g., "12.34"), it incorrectly removes the first digit.]
    pf("%c.",c[0]); // @@ [Always prints the first character as the base, but for numbers like "12.34", the first digit is '1', but the base should be "1.234" not "1.234" with the first digit only; the logic is flawed for multi-digit integer parts.]
    for(i=0;i<strlen(cc);i++){
        if(cc[i]!='.'){
            pf("%c",cc[i]);
        }
    }pf("e%d",b-1); // @@ [Exponent calculation b-1 is correct only when there is exactly one digit before the decimal; for multi-digit integer parts, it is wrong.]
}
    return 0;
}