#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1; // @@ Should initialize sum to 0, not 1. Also flag should be reset properly.
int main(){
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1; // @@ This sets flag to 1 even for the '.' character itself, causing sum to never increment. Should only check digits after dot.
            if(!flag&&s[i]=='0')sum++; // @@ Due to previous error, sum never increments; but this logic is correct if flag were set properly.
        }
    }
    if(dot==1&&s[0]!='0'){
        printf("%se0",s);
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){ // @@ Starting index is wrong. Should be dot+sum+1 to skip leading zeros and start at first non-zero digit.
                if(s[i]!='.')
                printf("%c",s[i]);
                if(i==dot+sum&&i!=len-1)printf("."); // @@ Condition for decimal point insertion is incorrect. Should be placed after the first non-zero digit.
            }
            printf("e-%d",sum); // @@ Exponent should be -(sum+1) because number of leading zeros is sum, but first significant digit is at position - (sum+1).
        }
        else{
            for(int i=0;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); 
                }
                if(i==0)printf("."); // @@ This branch also has issues for numbers like "123.45", but not directly related to the failing test case.
            }
            printf("e%d",dot-1); // @@ Exponent calculation for non-zero leading digit is also incorrect, but not the focus here.
        }
    }
    return 0;
}