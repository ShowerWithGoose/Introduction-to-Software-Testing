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
            n=i-1;
        }
        if('.'==str[i])
        count=i-1;
    }
    if('0'==str[0]){
        if(n+2>=l-1)
        printf("%c",str[n+1]);
        for(int i=n+2;i<l-1;i++){
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count));
    }
    if(str[0]!='0'){
        printf("%c.",str[n-1]); // @@ Error: When the first digit is non-zero, the base should be a single digit without a decimal point if there are no other significant digits after it, but here a decimal point is always added. Also, the exponent calculation is incorrect; it should be based on the position of the decimal point relative to the first digit.
        for(int i=n;i<l-1;i++){
            if('.'==str[i])
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",abs(n-count-1)); // @@ Error: The exponent calculation is wrong. For input like "0.9", the first digit is '0', so this branch is not taken, but for other cases, the exponent should be the number of places the decimal point moved, not abs(n-count-1).
    }
return 0;
}