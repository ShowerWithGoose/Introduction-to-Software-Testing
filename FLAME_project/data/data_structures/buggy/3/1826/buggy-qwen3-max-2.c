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
            n=i-1; @@ [This logic incorrectly sets n when the first character is '0'. For input "0.9", i=2 (pointing to '9'), so n becomes 1, but it should record the position of the first non-zero digit correctly for later use.]
        }
        if('.'==str[i])
        count=i-1; @@ [count is intended to store the exponent base, but this assignment overwrites it for every '.' encountered and doesn't handle cases like leading zero correctly. For "0.9", count becomes -1 (since i=1 for '.'), which leads to wrong exponent calculation.]
    }
    if('0'==str[0]){
        if(n+2>=l-1)
        printf("%c",str[n+1]); @@ [For "0.9", n=1, so n+1=2, but str[2] is '9', yet the condition n+2>=l-1 (3 >= 2) is true, so it prints str[2]='9'. However, the following loop doesn't run, so it prints "9", but then the exponent is computed as abs(n-count)=abs(1 - (-1))=2, leading to "9e-2", which is wrong. But actual buggy output is ".e-0", meaning this branch may not even be entered correctly due to earlier errors in n and count.]
        for(int i=n+2;i<l-1;i++){
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count)); @@ [Exponent calculation is incorrect. For "0.9", the correct exponent is -1, but this computes abs(1 - (-1)) = 2, yielding e-2. However, observed output is e-0, suggesting n or count are not what we expect—likely because n was set incorrectly earlier.]
    }
    if(str[0]!='0'){
        printf("%c.",str[n-1]);
        for(int i=n;i<l-1;i++){
            if('.'==str[i])
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",abs(n-count-1)); @@ [This branch is not taken for "0.9", so not directly responsible for the error, but the exponent formula is also suspect.]
    }
return 0;
}