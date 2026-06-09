#include<stdio.h>
#include<string.h>
int main(){
    int i,j=0,j1=-1,k=0,len,a,b;
    char str[105];
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]>'0'&&str[i]<='9'){
            j=i;
            if(j1<0)
            j1=j;    
        }
        if(str[i]=='.')
            k=i;
    }
    if(k==0){
        k=len-1; // @@ [This line incorrectly assumes that if there's no decimal point (k remains 0), then the decimal point is at the end. However, per problem input format, the input always has digits before and after the decimal point, so k should never be 0. But more critically, in cases like "0.000...", k is correctly set to 1 (the position of '.'), so this block should not run. The real issue is elsewhere.]
    }
    if(j1==j){
        printf("%ce%d",str[j1],k-j1); // @@ [The exponent calculation is wrong for numbers less than 1. For input "0.00000009123456789012", j1=9 (index of '9'), k=1 (index of '.'). So k - j1 = 1 - 9 = -8, but this prints e-8 as e%d → which would print e-8 only if %d handles negative, but here it's printed as e-8? Wait: actually, k-j1 is negative, so %d will print negative number. But in this branch, j1==j means only one significant digit, so it should print e-(j1 - k) or similar. However, the bigger error is in the else branch exponent. Let's check the failing case: input "0.00000009123456789012" → j1=9, j=20 (last digit), so it goes to else branch. Then exponent is k - j1 - 1 = 1 - 9 -1 = -9, but expected is -8. So the error is in the else branch exponent formula.]
    }
    else{
        printf("%c.",str[j1]);
        for(i=j1+1;i<=j;i++){
            if(str[i]!='.')
                printf("%c",str[i]);
        }
        printf("e%d",k-j1-1); // @@ [This is the critical error. For input "0.00000009123456789012", the decimal point is at index k=1, first non-zero digit '9' is at j1=9. The correct exponent should be -(j1 - k) = -(9 - 1) = -8. But the code computes k - j1 - 1 = 1 - 9 - 1 = -9, which is off by one. The correct formula for numbers < 1 is: exponent = -(j1 - k - 1) = k - j1 + 1? Let's think: 0.00000009 = 9e-8. The '9' is at position 9 (0-based), '.' at 1. Number of zeros after decimal before 9 is 7, so exponent is -8. That equals (k + 1 - j1) = 1 + 1 - 9 = -7? No. Actually, the place value: digit at index j1 is 10^(k - j1) because '.' is at k, so positions after '.' are k+1 (10^-1), k+2 (10^-2), ..., j1 is at offset (j1 - (k+1)) after decimal, so exponent = - (j1 - k). For j1=9, k=1: exponent = -(9 - 1) = -8. So correct exponent is k - j1. But in the else branch, they do k - j1 - 1, which gives -9. So the -1 is extra. The error is this line uses k-j1-1 instead of k-j1.]
    }
    return 0;
}