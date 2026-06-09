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
    gets(c); // @@ Using gets is unsafe and deprecated, but more importantly, the logic below fails for the specific test case.
    int a,b,d=0,e=0,f,g,h,i,j;
    if(c[1]=='.'&&c[0]=='0'){
        for(b=2;b<strlen(c);b++){
            if(c[b]=='0'){
                d++;
            }}
            
    pf("%c",c[2]); // @@ Error: This prints the character at index 2. In "0.0000000912...", index 2 is '0'. The first significant digit is at index 9 ('9'). The code assumes the first non-zero digit is immediately after the zeros counted by d, but it hardcodes index 2 instead of calculating the correct index (2 + d).
    if(c[3]!='\0'){ // @@ Error: This checks index 3 to decide if a decimal point is needed. It should check if there are any digits remaining after the first significant digit. Also, it prints from index 3, which is incorrect as it skips the first significant digit found (or rather, the logic is completely misaligned with finding the first significant digit).
    
    pf(".");pf("%s",&c[3]);} // @@ Error: Prints the rest of the string starting from index 3. This includes leading zeros and misses the correct alignment for scientific notation. It should print digits starting from the first significant digit + 1.
    else{pf("%s",&c[3]); // @@ Error: Same issue as above.
    
    }pf("e-%d",d+1); // @@ Error: The exponent calculation is partially correct in concept (number of zeros + 1), but since the mantissa printing is wrong, the whole output is wrong. For 0.0000000912, d=7 (zeros at indices 2-8? No, indices 2,3,4,5,6,7,8 are zeros. Wait. "0.0000000912". Indices: 0:'0', 1:'.', 2:'0', 3:'0', 4:'0', 5:'0', 6:'0', 7:'0', 8:'0', 9:'9'. The loop counts zeros. b goes from 2. c[2] to c[8] are '0'. So d becomes 7. Then it prints c[2] which is '0'. Correct first sig digit is c[9]. Exponent should be -(d+1) = -8. The exponent value here is -8. But the mantissa is wrong.
    
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