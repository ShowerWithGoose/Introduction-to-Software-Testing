#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    scanf("%s",a);
    int l=0,i,m=0,n=0,k=0;
    l=strlen(a);
    if(a[0]=='0'&&a[1]=='.')
    {
        for(i=2;i<l;i++)
        {
            if(a[i]!='0')
            {
            m=i;
            k=m;
            break;    
            }
        }
        if(m==l-1)
        {
            printf("%ce-%d",a[l-1],l-2); // @@ Error: When the input is "0.0", the loop finds no non-zero digit, so m remains 0, and this condition incorrectly triggers, printing "0e-2" instead of "0e0". Also, for inputs like "0.001", the exponent calculation l-k is wrong; it should be -(m-1) or -(i-1) where i is the index of the first non-zero digit.
            
        }
        else
        {
            printf("%c.",a[m]);
        for(m++;m<l;m++)
        {
            printf("%c",a[m]);
        }
        printf("e-%d",l-k); // @@ Error: The exponent should be -(m-1) where m is the index of the first non-zero digit, not l-k. For example, input "0.001" should output "1e-3", but this code outputs "1.0e-4" because l=5, k=3, so l-k=2, but the correct exponent is -3.
        }  
    }
    else if(a[0]<='9'&&a[0]>='1'&&a[1]=='.')
    {
        printf("%s",a); // @@ Error: This prints the entire input string including the decimal point, but the output format requires the base to have exactly one digit before the decimal point and one digit after (if decimal). For input "1.23", it prints "1.23e0", but the correct output should be "1.23e0" (this is actually correct for this case). However, for input "1.0", it prints "1.0e0", but the problem says no trailing zeros, so this input should not occur. The real issue is that for inputs like "1.23", the output is correct, but the code does not handle cases where the input has no decimal point (e.g., "123") which is handled in the else-if below.
        printf("e0");
    }
    else if(a[0]<='9'&&a[0]>='1'&&a[1]!='.')
    {
        for(i=0;i<l;i++)
        {
            if(a[i]=='.')
            {
                n=i;
                break;
            }
        }
        printf("%c.",a[0]);
        for(i=1;i<n;i++)
        {
            printf("%c",a[i]);
        }
            for(i=n+1;i<l;i++)
        {
            printf("%c",a[i]);
        }
        printf("e%d",n-1);
    }
    return 0;
 }