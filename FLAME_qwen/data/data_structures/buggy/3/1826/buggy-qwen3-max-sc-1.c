#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
char str[1001];
int main(){
    fgets(str,1000,stdin);
    int count=0,n=0,l=strlen(str);
    for(int i=0;i<l-1;i++){
        if('0'==str[i])
        continue;
        if(str[i]!='0'&&str[i]!='.'){
            if(n!=0)
            continue;
            n=i+1;
            if('0'==str[0])
            n=i-1; @@ [Logic error: When the number starts with '0', n should be set to i (the index of first non-zero digit), not i-1. This causes incorrect exponent and base extraction.]
        }
        if('.'==str[i])
        count=i-1; @@ [Logic error: count is intended to track the position of the decimal point relative to digits, but setting it to i-1 here is inconsistent with how it's used later (e.g., in abs(n-count)). It should likely be set to i or handled differently.]
    }
    if('0'==str[0]){
        if(n+2>=l-1)
        printf("%c",str[n+1]); @@ [Logic error: If n was incorrectly set (e.g., to i-1 where i is index of first non-zero), then n+1 may be out of bounds or refer to wrong character. Also, when input is like "0.1", n might be 0, so n+1=1 which is '.', leading to printing '.' as significant digit.]
        for(int i=n+2;i<l-1;i++){
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count)); @@ [Logic error: Due to incorrect n and count values, the exponent calculation is wrong. For example, for "0.1", expected exponent is -1, but this may compute something else.]
    }
    if(str[0]!='0'){
        printf("%c.",str[n-1]); @@ [Logic error: If n was set as i+1 in the loop, then n-1 is the correct index of first non-zero digit. However, if the number has more than one digit before '.', this logic fails because it always prints only one digit before decimal. But more critically, if n was never set (e.g., all zeros except decimal), this leads to undefined behavior. Also, missing else causes both branches to execute if input doesn't start with '0' but also doesn't meet other conditions properly.]
        for(int i=n;i<l-1;i++){
            if('.'==str[i])
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",abs(n-count-1)); @@ [Logic error: Exponent calculation is based on flawed n and count, leading to incorrect exponent. Also, abs() is unnecessary for positive exponents and may mask sign errors.]
    }
return 0;
}