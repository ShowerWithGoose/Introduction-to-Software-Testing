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
            n=i-1; // @@ [When the input is "0.9", this sets n = 1 - 1 = 0, which causes incorrect indexing later. The logic for computing n when the number starts with '0' is flawed.]
        }
        if('.'==str[i])
        count=i-1; // @@ [This assigns count = i - 1 when '.' is found, but for "0.9", i=1 so count=0. However, the exponent should be based on the position of the first non-zero digit relative to the decimal point, not just the dot's index minus one.]
    }
    if('0'==str[0]){
        if(n+2>=l-1)
        printf("%c",str[n+1]); // @@ [If n=0 (as in "0.9"), this prints str[1], which is '.', leading to output starting with '.', which is invalid.]
        for(int i=n+2;i<l-1;i++){
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count)); // @@ [With n=0 and count=0, this prints e-0, but the correct exponent for 0.9 is -1. The formula abs(n-count) is incorrect.]
    }
    if(str[0]!='0'){
        printf("%c.",str[n-1]);
        for(int i=n;i<l-1;i++){
            if('.'==str[i])
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",abs(n-count-1)); // @@ [This branch is not taken for "0.9", but the exponent calculation here is also likely incorrect due to flawed count and n values.]
    }
return 0;
}