#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char a[200];char c;int i,j;
int main(){
    gets(a);
    if(a[0]=='0'){
        for(i=2;a[i]=='0';i++){
            
        }
        if(a[i+1]=='\0'){
            printf("%c",a[i]);printf("e");
            printf("%d",1-i); // @@ The exponent calculation is incorrect. For numbers like 0.001, the exponent should be negative, but 1-i gives a positive value when i>1. The correct exponent should be 1-i (which is negative), but the output format requires no '+' for non-negative exponents, and this code prints a negative exponent correctly. However, the logic fails for cases like 0.0 (single zero after decimal) because the loop may skip all zeros and i points to the null terminator, causing undefined behavior.
        }
        else{
            printf("%c.",a[i]);
            for(j=i+1;a[j]!='\0';j++){
                printf("%c",a[j]);
            }
            printf("e%d",1-i); // @@ Same exponent issue as above. Additionally, the code does not handle the case where the input has no digits after the decimal point (e.g., "0") or when the number is exactly zero. The problem states the input has digits before and after the decimal point, but the code may still fail for edge cases like "0.0" (though trailing zeros are not allowed per spec, the code should be robust).
        }
    }
    // @@ Missing else branch: The program does not handle numbers that do not start with '0' (e.g., "1.23", "12.34"). The reference program includes an else block for such cases, but this code only handles the case where the first digit is '0', so it will produce no output for non-zero leading digits.
    return 0;
}