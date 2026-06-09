#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a);
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2;
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2;
        
        printf("%c.", a[i]); // @@ Error: When the input is "0.0", this will print a '.' after the digit, but the expected output for "0.0" is "0e0" (integer base) or "0.0e0" (decimal base) depending on interpretation. The problem states that if the base is an integer, it should have no decimal point. For "0.0", the significant digit is 0, and the exponent should be 0. The current logic incorrectly handles the case where all digits after the decimal point are zero.
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        
        printf("e-%d", j+1); // @@ Error: The exponent calculation is incorrect. For input "0.001", the exponent should be -3, but this code calculates j+1 = (i-2)+1 = (3-2)+1 = 2, giving e-2 instead of e-3. The correct exponent should be -(number of zeros after decimal point + 1), but the loop counting zeros starts from index 2, missing the first zero after the decimal point.
    }
    else if(a[i] != '0')//几点几 
    {
        printf("%c.", a[i]); // @@ Error: For integer inputs like "5", this will output "5.e0" instead of "5e0". The problem states that if the base is an integer, it should have no decimal point. The code always adds a decimal point after the first digit.
        i=1;
         
        while(a[i] != '.')
        {
            printf("%c", a[i]);
            i++;
        }
        j=i-1;
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        printf("e%d", j); // @@ Error: For input "12.34", this outputs "1.234e1" which is correct, but for input "1.23", it outputs "1.23e0" instead of "1.23e0" (which is actually correct). However, the problem expects the base to have exactly one digit before and after the decimal point if it's a decimal. For "1.23", the output should be "1.23e0" which matches. But for "123.45", the output should be "1.2345e2", and this code outputs "1.2345e2" which is correct. The main issue is with integer inputs and the decimal point handling.
    }
    return 0;
}