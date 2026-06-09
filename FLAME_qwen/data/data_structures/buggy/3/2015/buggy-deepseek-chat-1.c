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
    printf("%c.",str[i]); // @@ Error: When the input is "0.xxx", the loop may break at the decimal point, causing str[i] to be '.' and printing an extra decimal point. Also, for input like "0.001", the exponent calculation is incorrect because k counts all leading zeros including the one before the decimal point, but the exponent should be based on the position of the first non-zero digit after the decimal point.
    for(i++;str[i]!='\0';i++){
    printf("%c",str[i]);
    }
    printf("e-%d",k); // @@ Error: The exponent k is the count of leading zeros including the one before the decimal point, but for numbers like "0.001", the correct exponent should be -3 (since the first non-zero digit is at position 3 after the decimal), not -4. The logic does not correctly compute the exponent.
    }
    else{
    for(i=0;str[i]!='.'&&str[i]!='\0';i++)
    {}
    printf("%c.",str[0]); 
    for(k=1;str[k]!='\0';k++){
    if(str[k]!='.')printf("%c",str[k]);
    }
    printf("e%d",i-1); // @@ Error: For numbers like "123.456", i is the index of the decimal point (3), so i-1 = 2, but the correct exponent should be 2 (since 123.456 = 1.23456e2). However, for numbers like "1.23", i is 1, i-1 = 0, which is correct. But for numbers with multiple digits before the decimal point, the exponent calculation is correct only if the first digit is non-zero. However, the output format requires that if the base is an integer (only one digit before decimal), it should not have a decimal point. This code always prints a decimal point after the first digit, which is incorrect for cases like "1.0" (should output "1e0" not "1.0e0"). Also, for numbers like "10.0", the output should be "1e1", but this code outputs "1.0e1", which is wrong.
    }

 
}