#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1;
int main(){
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1;
            if(!flag&&s[i]=='0')sum++; // @@ The variable 'sum' is intended to count leading zeros after the decimal point to determine the exponent for small numbers (e.g., 0.00...x). However, this loop iterates through the entire string. For input "0.00000009123...", 'dot' becomes 1. The condition `dot>0` is true for all subsequent characters. The logic `if(!flag&&s[i]=='0')sum++` correctly counts zeros until the first non-zero digit. But `sum` is initialized to 1. For "0.00000009...", the zeros are at indices 2,3,4,5,6,7,8. The first non-zero is at index 9 ('9'). So `sum` should become 1 + 7 = 8. This part seems logically okay for calculating the magnitude of the shift for numbers < 1. Let's trace carefully. Input: "0.00000009123456789012". dot=1. i=0: s[0]='0', dot=0. dot>0 false. i=1: s[1]='.', dot=1. dot>0 true. s[1]!='0' is false ('.'!='0' is true? No, '.' is not '0', so flag becomes 1 immediately? Wait. s[i] is '.'. '.' != '0' is true. So flag becomes 1. Then !flag is false. So sum doesn't increment. This is wrong. The code sets flag=1 when it encounters the decimal point itself because '.' != '0'. This breaks the logic for counting leading zeros after the decimal point.
        }
    }
    if(dot==1&&s[0]!='0'){
        printf("%se0",s);
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){ // @@ Because flag was set to 1 prematurely by the decimal point, sum remains 1. dot=1. dot+sum = 2. The loop starts printing from index 2. Index 2 is '0'. It prints "0000009123...". It should start printing from the first significant digit.
                if(s[i]!='.')
                printf("%c",s[i]);
                if(i==dot+sum&&i!=len-1)printf("."); // @@ This prints a decimal point after the first character printed in this loop. Since the loop starts at the wrong position, the mantissa is wrong.
            }
            printf("e-%d",sum); // @@ Sum is incorrect (1 instead of 8), so the exponent is wrong.
        }
        else{
            for(int i=0;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); 
                }
                if(i==0)printf(".");
            }
            printf("e%d",dot-1);
        }
    }
    return 0;
}