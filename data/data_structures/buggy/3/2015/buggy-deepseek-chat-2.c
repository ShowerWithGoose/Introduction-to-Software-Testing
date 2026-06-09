#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char str[120];
int main(){
    gets(str);
    int i;
    int k=0;
    if(str[0]=='0'){

    for(i=0;str[i]!='\0';i++){
    if(str[i]=='0'){
    k++;
    }
    if(str[i]!='0'&&str[i]!='.')
    break;
    }
    printf("%c.",str[i]); // @@ Error: When the input is "0.xxx", the loop may break at the decimal point, causing str[i] to be '.' and printing an extra decimal point. Also, for numbers like "0.001", the loop counts leading zeros incorrectly (including the zero before the decimal point) and the exponent calculation is wrong.
    for(i++;str[i]!='\0';i++){
    printf("%c",str[i]);
    }
    printf("e-%d",k); // @@ Error: The exponent k counts all leading zeros including the one before the decimal point, which is incorrect. For example, input "0.001" should output "1e-3", but k would be 3 (counting '0', '.', '0') leading to "e-3" but the base would be wrong.
    }
    else{
    for(i=0;str[i]!='.'&&str[i]!='\0';i++)
    {}
    printf("%c.",str[0]); // @@ Error: For numbers with more than one digit before the decimal point (e.g., "12.34"), this always prints only the first digit before the decimal point, but the problem requires the base to have one significant digit before the decimal point, which should be the first non-zero digit, not necessarily str[0]. Also, for integers without a decimal point, this will print an extra '.'.
    for(k=1;str[k]!='\0';k++){
    if(str[k]!='.')printf("%c",str[k]);
    }
    printf("e%d",i-1); // @@ Error: For numbers like "12.34", i is the position of the decimal point (2), so i-1=1, but the correct exponent should be 1 (since 12.34 = 1.234e1). However, for numbers like "1.23", i=1, i-1=0, which is correct. For integers without a decimal point, i will be strlen(str), causing i-1 to be incorrect.
    }

 
}