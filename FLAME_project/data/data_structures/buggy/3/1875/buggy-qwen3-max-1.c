#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[1000000]={0};
    gets(s); // @@ [Using gets() is unsafe and deprecated; more critically, it may include the newline in some environments, but the main issue is logic errors below. However, the primary bugs are logical, not this.]
    int len=strlen(s);
    int i,j;
    int cnt1=0,cnt2,mark1,mark2; // @@ [cnt2 is used uninitialized in the else branch if the loop doesn't run, leading to undefined behavior.]
    for(i=0;i<len;i++){
        if(s[i]!='.'){
            if(s[i]=='0'){
                cnt1++;
            }else{
                mark1=i;
                break;
            }
        }
    }
    if(cnt1>=1){ // @@ [This condition assumes that any leading zeros imply a number < 1 (like 0.00123), but fails for numbers like 10.5 where leading digit is non-zero but there are internal zeros. Also, it doesn't handle cases where the first non-zero digit is after the decimal point correctly in all scenarios.]
        printf("%c",s[mark1]);
        if(mark1!=len-1){
            printf(".");
        }
        for(i=mark1+1;i<len;i++){
            printf("%c",s[i]);
        }
        printf("e-%d",cnt1); // @@ [The exponent calculation is incorrect. For input like "0.00123", cnt1 counts leading zeros before '1', but exponent should be -(number of places moved), which is -3, but cnt1=2 (zeros before '1'), so it prints e-2 instead of e-3. Also, it doesn't skip the decimal point when counting.]
    }else{
        for(i=0;i<len;i++){
            if(s[i]!='.'){
                cnt2++; // @@ [cnt2 was never initialized to 0, so it starts with garbage value. This leads to wrong exponent calculation.]
            }else{
                mark2=i;
                break;
            }
        }
        if(mark2==1){ // @@ [This checks if decimal is at index 1 (e.g., "1.23"), but what if input is "0.5"? It wouldn't enter this else branch because cnt1 would be >=1. However, for "5.67", mark2=1, so it prints "5.67e0", which is correct per problem? But problem says if only one digit before decimal and it's 0, that's allowed. However, the bigger issue is cnt2 uninitialized.]
            printf("%se0",s);
        }else{
            printf("%c.",s[0]);
            for(i=1;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]);
                }
            }
            printf("e%d",cnt2-1); // @@ [Because cnt2 is uninitialized, this exponent is garbage. Even if initialized, the logic of counting digits before '.' is flawed because the loop breaks at '.', so cnt2 equals mark2, but then exponent should be mark2-1. However, without initializing cnt2=0, it's undefined.]
        }
    }
    return 0;
}