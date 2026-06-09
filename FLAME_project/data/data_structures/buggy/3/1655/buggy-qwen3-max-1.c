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
        k=len-1;
    }
    if(j1==j){
        printf("%ce%d",str[j1],k-j1); @@ // The exponent calculation is incorrect for numbers less than 1. For "0.00000009...", k is the position of '.', which is 1, and j1 is the index of first non-zero digit (9). The correct exponent should be -(j1 - k), but here it's computed as k - j1, which gives a negative value without proper sign handling and wrong magnitude.
    }
    else{
        printf("%c.",str[j1]);
        for(i=j1+1;i<=j;i++){
            if(str[i]!='.')
                printf("%c",str[i]);
        }
        printf("e%d",k-j1-1); @@ // The exponent calculation is wrong. For numbers >= 1, this may work, but for numbers < 1 (like the test case), k is the decimal point position (1), j1 is the first non-zero digit index (9 in "0.00000009..."), so k - j1 - 1 = 1 - 9 - 1 = -9, but the correct exponent is -8. The formula doesn't account for the fact that after the decimal point, each zero shifts the exponent by -1, and the first non-zero digit is at position (j1 - k - 1) places after the decimal, so exponent should be -(j1 - k).
    }
    return 0;
}