#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
char str[1001];
int main(){
    fgets(str,1000,stdin);
    int count=0,n=0,l=strlen(str);
    for(int i=0;i<l-1;i++){ // @@ Error: loop bound should be i < l to include all characters; using l-1 excludes the last digit when newline is missing, causing the digit '9' in "0.9" to be skipped.
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
        if(n+2>=l-1) // @@ Error: uses l-1; should use l instead (or adjust for newline). With the loop bound error, this condition may be incorrectly met.
        printf("%c",str[n+1]); // @@ Error: missing decimal point after the first digit when there are more digits; should print '.' before subsequent digits.
        for(int i=n+2;i<l-1;i++){ // @@ Error: similar loop bound issue; should use i < l.
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count));
    }
    if(str[0]!='0'){
        printf("%c.",str[n-1]);
        for(int i=n;i<l-1;i++){ // @@ Error: loop bound should be i < l to include all characters after the decimal point.
            if('.'==str[i])
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",abs(n-count-1));
    }
return 0;
}