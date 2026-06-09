#include <stdio.h>
#include <string.h>
char s[105];
int main(){
    int x,j,y=0,i;
    gets(s);
    x=strlen(s);
    if(s[0]=='-'){
        printf("-");
        for(i=0,j=1;j<=x-1;j++,i++){
            s[i]=s[j];
        }
        s[x-1]=0;
        x=strlen(s);
    }
    for(j=0;j<=x-1;j++){
        if(s[j]=='.'){
            y=j;
            break;
        }
        else{
            y=0; // @@ [This line incorrectly resets y to 0 for every non-'.' character before the decimal point. As a result, if the loop doesn't find a '.', y remains 0, but if it finds a '.' at position >0, previous assignments of y=0 are overwritten correctly. However, the logic is flawed because y should remain unset or default only if no '.' is found. The real issue is that this loop sets y=0 repeatedly until it hits '.', which is inefficient but not directly wrong. The critical error is elsewhere.]
        }
    }
    if(y==1){
        if(s[0]>'0'){
            printf("%se0",s);
        }
        else{
            for(i=2;i<=x-1;i++){
                if(s[i]!='0'){
                    break;
                }
            }
            if(i==x-1){ // @@ [This condition assumes that if i reaches x-1, then only the last digit is non-zero. But if all digits after decimal are zero except the very last one, this may work, but the indexing is off. More critically, the handling of trailing zeros in input like "87899.9999999999000999" fails because the program does not preserve all significant digits after removing the decimal point.]
                printf("%ce-%d",s[x-1],i-1);
            }
            else{
                printf("%c.",s[i]); // @@ [Here, s[i] is the first non-zero digit after leading zeros, but it should be printed as the first digit of the mantissa. However, the code prints s[i] as the integer part, but skips all prior digits including the '0' before decimal and leading zeros. This is correct for numbers like 0.00123 -> 1.23e-3, but the indexing for exponent is wrong.]
                for(j=i+1;j<=x-1;j++){
                    printf("%c",s[j]);
                }
                printf("e-%d",i-1); // @@ [The exponent calculation is incorrect. For input "0.00123", i=4 (pointing to '1'), so exponent should be -3, but i-1 = 3 → e-3 is correct. However, in the failing test case, this branch is not taken. The main bug is in the else branch below.]
            }
        }
    }
    else{
        printf("%c.",s[0]);
        for(j=1;j<=x-1;j++){
            if(s[j]=='.'){
                j++; // @@ [This skips the character after the decimal point by incrementing j inside the loop, but the for-loop also increments j at the end of each iteration. This causes skipping of one digit after the decimal point. For example, in "87899.9999999999000999", when j reaches the '.' at index 5, it does j++ (now j=6), then the loop does j++ again (now j=7), so s[6] ('9') is skipped. This explains why the output misses one '9' after the decimal: expected has 15 '9's after decimal before '000999', but output has 14.]
            }
            else{
                printf("%c",s[j]);
            }
        }
        printf("e%d",y-1);
    }
    return 0;
}