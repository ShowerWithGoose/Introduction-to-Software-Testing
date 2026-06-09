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
            printf("%ce-%d",a[l-1],l-2); // @@ Error: When the input is "0.0", the loop does not find a non-zero digit, so m remains 0, and this condition may be incorrectly met. Also, the exponent calculation l-2 is wrong; it should be -(l-2) or similar, but the logic for handling all zeros after decimal is missing.
            
        }
        else
        {
            printf("%c.",a[m]);
        for(m++;m<l;m++)
        {
            printf("%c",a[m]);
        }
        printf("e-%d",l-k); // @@ Error: The exponent should be -(m-1) where m is the index of the first non-zero digit, but here l-k is used, which is incorrect. For example, input "0.001" should output "1e-3", but this code outputs "1.e-4" because l=5, k=3, so l-k=2, but the correct exponent is -3.
        }  
    }
    else if(a[0]<='9'&&a[0]>='1'&&a[1]=='.')
    {
        printf("%s",a); // @@ Error: This prints the entire input string including the decimal point, but the output format requires the base to have exactly one digit before and after the decimal point (if decimal) or just one digit (if integer). For input like "1.23", it prints "1.23e0", but the correct output should be "1.23e0" (this is actually correct for this case). However, for input "1.0", it prints "1.0e0", but the problem says no trailing zeros, so this input should not occur. The real issue is that for inputs like "1.234", it prints "1.234e0", which is correct. So this part is actually fine for valid inputs, but the problem description says the base should have no trailing zeros, so inputs like "1.0" are invalid. However, the code does not handle the case where the input is just an integer without a decimal point, e.g., "5", which should output "5e0", but this code would go to the else if branch incorrectly because a[1] is not '.' and a[0] is between '1' and '9', so it goes to the next else if, which is correct. Actually, for "5", a[1] is '\0', not '.', so it goes to the else if(a[0]<='9'&&a[0]>='1'&&a[1]!='.') branch, which is correct. So this line is not erroneous for valid inputs, but the comment is misleading.
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
        printf("e%d",n-1); // @@ Error: For an integer input without a decimal point, n remains 0 because the loop never finds a '.', so n-1 is -1, which is incorrect. For example, input "123" should output "1.23e2", but this code prints "1.23e-1" because n=0. The code does not handle the case where there is no decimal point in the input.
    }
    return 0;
 }