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
            printf("%ce-%d",a[l-1],l-2);
            
        }
        else
        {
            printf("%c.",a[m]);
        for(m++;m<l;m++)
        {
            printf("%c",a[m]);
        }
        printf("e-%d",l-k); @@ [The exponent calculation is incorrect. It should be (k - 1), not (l - k). For example, input "0.00123" should yield e-3, but this computes e-(6-3)=e-3 only by coincidence in some cases; for "0.012", l=5, k=3, l-k=2, but correct exponent is -2, which matches, but logic is flawed and fails when trailing digits exist. More critically, if no non-zero digit is found (though problem states all digits are significant), m remains 0, leading to undefined behavior. Also, the case where the number has no decimal point or starts with non-zero but has no decimal is not fully handled.]
        }  
    }
    else if(a[0]<='9'&&a[0]>='1'&&a[1]=='.')
    {
        printf("%s",a);
        printf("e0"); @@ [This prints the entire original string including the decimal and all digits, but scientific notation requires only one digit before the decimal and the rest after without trailing zeros. For example, input "1.23" should output "1.23e0", which is okay, but if input were "12.3", this branch wouldn't trigger. However, the real issue is that this branch assumes the input has exactly one digit before the decimal, but the condition only checks a[1]=='.', so "5.67" works, but what if input is "1."? The problem states there are digits before and after the decimal, so maybe safe. But more importantly, this outputs "1.23e0", which is correct per spec. So this line may not be erroneous by itself. However, combined with missing handling of integers (no decimal point) starting with non-zero, the program fails other cases. But the immediate error is in the first branch's exponent.]
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
        printf("e%d",n-1); @@ [This assumes there is always a decimal point in numbers starting with non-zero digit and a[1] != '.', but if the input has no decimal point at all (e.g., "123"), then n remains 0 (uninitialized behavior—actually n is initialized to 0 globally, but the loop may not find '.' so n stays 0), leading to printing from i=1 to i<0 (no loop), then from i=1 to end, and exponent = -1, which is wrong. For "123", expected is "1.23e2", but this would print "1." then nothing from first loop, then from i=1 to 2: "23", so "1.23e-1", which is incorrect. The exponent should be strlen-1, and decimal point must be handled even if not present in input. The program fails to handle numbers without a decimal point in this branch.]
    }
    return 0;
}