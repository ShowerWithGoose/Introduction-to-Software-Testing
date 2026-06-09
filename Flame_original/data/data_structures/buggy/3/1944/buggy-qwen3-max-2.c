#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps 1e-8
    
int main()
{
    char s[100],t[100];
    int i,j,k,sum=0;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
    if(s[0]=='0'){
        for(i=2;i<strlen(s);i++){
            if(s[i]!='0'){
                sum=i;
                i++;
                for(j=0;i<strlen(s);j++,i++){
                    t[j]=s[i];
                }
                if(j==0)
                    printf("%c%se-%d",s[sum],t,sum-1); // @@ [When j==0, the array 't' is uninitialized (no characters were copied), leading to undefined behavior when printed as a string.]
                else
                    printf("%c.%se-%d",s[sum],t,sum-1);        
                return 0;
            }
        }
    }
    else{j=0;
        sum=0;
        for(i=1;i<strlen(s);i++){
            if(s[i]=='.'){
                sum=i;
                }
            else{
                t[j]=s[i];
                j++;        }    
        }
        j--;
        for(;j!=-1;j--){
            if(t[j]=='0') t[j]='\0'; // @@ [This loop attempts to remove trailing zeros but incorrectly modifies the string in place without ensuring null termination after the last non-zero digit, potentially leaving garbage or incomplete strings.]
            else break;
        }
        if(sum==0){
            if(i==1)
            printf("%ce%d",s[0],sum); // @@ [If there's no decimal point (sum==0) and only one digit (i==1), the exponent should be 0, but 'sum' is 0 which is correct; however, this branch may not handle multi-digit integers correctly. Also, variable 'i' after the loop equals strlen(s), so i==1 only if input length is 1, which is okay, but logic is convoluted.]
            else if(j==-1)
            printf("%ce%d",s[0],i-1); // @@ [If all digits after the first are zeros and stripped (j==-1), then output should be just the first digit with exponent = number of digits -1, but 'i-1' is strlen(s)-1 which is correct only if there was no decimal point. However, this conflicts with the condition sum==0 (no decimal point), so it might be okay, but the overall logic is fragile.]
            else
            printf("%c.%se%d",s[0],t,i-1); // @@ [When sum==0 (no decimal in input), the exponent should be (number of digits -1), which is i-1 (since i ends at strlen(s)), but 't' may contain leftover data if not properly null-terminated after zero-stripping.]
        }    
        else
            printf("%c.%se%d",s[0],t,sum-1); // @@ [If there is a decimal point (sum != 0), the exponent should be (position of decimal - 1). However, if trailing zeros were removed from 't', the string 't' might not be null-terminated correctly, leading to garbage output. Also, if all fractional digits are zero and stripped, 't' could be empty or unterminated.]        
        return 0;    
    }
}