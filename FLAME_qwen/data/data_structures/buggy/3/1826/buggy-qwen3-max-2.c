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
        printf("%c",str[n+1]); // @@ [Missing else leads to always printing digits after the first even when not in decimal form; also, no decimal point printed when needed]
        for(int i=n+2;i<l-1;i++){ // @@ [This loop runs unconditionally after the if above, causing extra digits to be printed even when n+2 >= l-1 (i.e., no fractional part)]
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count));
    }
    if(str[0]!='0'){ // @@ [Using a second independent if instead of else-if causes both blocks to potentially execute if input starts with '0' but str[0]!='0' is somehow true—though unlikely, logic is flawed; more critically, if input is like "0.1", the first block runs, but if input is "1.23", both conditions might not be mutually exclusive in all edge cases due to uninitialized or miscomputed n/count]
        printf("%c.",str[n-1]);
        for(int i=n;i<l-1;i++){
            if('.'==str[i])
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",abs(n-count-1));
    }
return 0;
}