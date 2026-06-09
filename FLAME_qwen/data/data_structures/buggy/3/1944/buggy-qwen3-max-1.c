#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps 1e-8
    
int main()
{
    char s[100],t[100];
    int i,j,k,sum=0;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers.]
    if(s[0]=='0'){
        for(i=2;i<strlen(s);i++){
            if(s[i]!='0'){
                sum=i;
                i++;
                for(j=0;i<strlen(s);j++,i++){
                    t[j]=s[i];
                }
                if(j==0)
                    printf("%c%se-%d",s[sum],t,sum-1); // @@ [When j==0, the string 't' is uninitialized or empty, leading to undefined behavior when printed as a string with %s. Also, this format does not match scientific notation requirements (missing decimal point when fractional part exists).]
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
            if(t[j]=='0') t[j]='\0'; // @@ [This attempts to remove trailing zeros but incorrectly modifies the string in-place without ensuring null-termination of the remaining part; also, the logic fails when all digits after the first are zeros.]
            else break;
        }
        if(sum==0){
            if(i==1)
            printf("%ce%d",s[0],sum); // @@ [If there's no decimal point (sum==0) and only one digit (i==1), exponent should be 0, but 'sum' is 0, which is correct, but this case may not occur due to input constraints. However, more critically, the variable 'i' after the loop equals strlen(s), so i==1 implies input length 1, which contradicts problem statement requiring digits before and after decimal. This branch may be unreachable or logically flawed.]
            else if(j==-1)
            printf("%ce%d",s[0],i-1); // @@ [When j==-1, it means all digits after the first were zeros and stripped, so output should be just the first digit without decimal, but exponent should reflect original position of decimal. However, 'i-1' may not correctly represent exponent if decimal point was present. Also, if sum != 0, this branch shouldn't use i-1.]
            else
            printf("%c.%se%d",s[0],t,i-1); // @@ [Exponent should be based on position of decimal point (sum-1), not i-1. Using i-1 (which is strlen(s)-1) is incorrect when decimal point exists.]
        }    
        else
            printf("%c.%se%d",s[0],t,sum-1);        
        return 0;    
    }
}