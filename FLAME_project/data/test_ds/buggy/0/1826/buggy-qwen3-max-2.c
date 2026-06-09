#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
int main(){
    int i=0;
    char ch;
    char a[256]={0};
    while((ch=getchar())!='\n'){
        a[i]=ch;
        i++;
    }
    printf("%c",a[0]); // @@ [If input is empty (i==0), accessing a[0] leads to undefined behavior; also, if the first character is part of an expansion like "-b", this prints '-' prematurely]
    for(int j=1;j<i;j++){
        if('-'!=a[j]){
            printf("%c",a[j]);
        }
        if('-'==a[j]){ // @@ [Does not check if a[j+1] exists (j+1 < i); accessing a[j+1] when j == i-1 causes out-of-bounds read]
            if(((a[j-1]>='a'&&a[j-1]<='z')&&(a[j+1]>='a'&&a[j+1]<='z'))||((a[j-1]>='A'&&a[j-1]<='Z')&&(a[j+1]>='A'&&a[j+1]<='Z'))||((a[j-1]>='0'&&a[j-1]<='9')&&(a[j+1]>='0'&&a[j+1]<='9'))){
                for(int k=1;k<(a[j+1]-a[j-1]);k++){ // @@ [Expansion condition requires that the second char is greater than the first, but this loop runs even if a[j+1] <= a[j-1], producing incorrect or negative-length loops (though k<(negative) skips loop, it still fails requirement to output unchanged in such cases]; also, when valid, it correctly expands but doesn't handle non-expansion cases properly because the '-' was already skipped in printing]
                    printf("%c",a[j-1]+k);
                }
            }
        }
    }
return 0;
}