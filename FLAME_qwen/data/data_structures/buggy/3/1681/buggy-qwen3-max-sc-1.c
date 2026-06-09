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
        printf("e-%d",l-k); @@ [The exponent calculation is incorrect. It should be (k - 1), not (l - k). For example, input "0.00123" should yield e-3, but this computes e-(6-3)=e-3 only by coincidence in some cases; for "0.01", l=4, k=2, l-k=2, but correct exponent is -2, which matches, but logic is flawed and fails for other cases like "0.1" where k=2, l=3, l-k=1, but exponent should be -1 — actually seems to work numerically but the reasoning is wrong and may break on edge cases. However, more critically, if all digits after decimal are zero (though problem states no trailing zeros and all digits significant), but more importantly, if no non-zero digit is found, m remains 0 and leads to undefined behavior. But per problem, there's always at least one non-zero digit. The real issue is in the exponent: for "0.001", k=3, exponent should be -3, but l=5? Wait: "0.001" has l=5? No: '0','.','0','0','1' → l=5, k=4, l-k=1 → outputs e-1, which is wrong. So yes, exponent is wrong. Correct exponent is -(k - 1).]
        }  
    }
    else if(a[0]<='9'&&a[0]>='1'&&a[1]=='.')
    {
        printf("%s",a);
        printf("e0"); @@ [This prints the entire original string including the decimal point and all digits, but scientific notation requires only one digit before decimal and then the rest after. For example, input "5.67" should output "5.67e0", which is acceptable per problem (one digit before decimal), so this is actually correct. However, if input is "5.0", but problem states no trailing zeros, so "5.0" won't appear. So this branch may be okay. But wait: what if input is "1."? That is, ends with decimal? Problem says "has digits before and after the decimal point", so this case shouldn't occur. So maybe not an error. But let's check other branches.]
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
        printf("e%d",n-1); @@ [This assumes there is a decimal point in the number, but the condition only checks that a[1] != '.' — the number could be an integer with no decimal point at all (e.g., "123"). In that case, the loop for(i=0;i<l;i++) may never find a '.', so n remains 0 (uninitialized behavior — actually n is initialized to 0 globally, but if no '.' is found, n=0, then printing from i=1 to n-1 (i<0) does nothing, then from i=n+1=1 to l-1 prints all digits from index 1 onward, which is correct for integer input. However, the exponent becomes n-1 = -1, which is wrong. For input "123", expected output is "1.23e2", but this would set n=0 (since no '.' found), then print "1." then from i=1 to -1 (nothing), then from i=1 to 2: "23", so "1.23", then exponent = -1 → "1.23e-1", which is wrong. So the code fails to handle integers (no decimal point). The problem states: "has digits before and after the decimal point", so maybe integers without decimal are not in input? But the problem also says: "If there’s only one digit before the decimal point, it can be 0; otherwise, the first digit before the decimal point cannot be 0." This implies there is always a decimal point? Actually, re-read: "the input data contains no sign, has digits before and after the decimal point" — so every input has a decimal point. Therefore, this branch may be safe. But wait: the third condition is a[0] between '1'-'9' and a[1] != '.', which implies the number has more than one digit before decimal, e.g., "12.34". So decimal point exists but not at position 1. So the loop will find it. So maybe okay. However, what if the number is "1234" (no decimal)? Per problem, this won't happen. So perhaps not an error. But the first branch has a clear exponent error. Also, the program doesn't handle the case where the number is like "10.0" but problem says no trailing zeros, so "10.0" invalid. So main error is in first branch exponent. Additionally, the program lacks handling for numbers like "0.1" — let's test: a="0.1", l=3, i=2, a[2]='1' !='0', so m=2, k=2. Then m==l-1 → 2==2 → true, so prints a[2]='1' and e-(3-2)=e-1 → "1e-1", but expected is "1e-1" or "1.e-1"? Problem says: if base is integer, one digit without decimal; if decimal, one before and after. Since only one digit total, should it be "1e-1" (integer base) or "1.e-1"? The problem says: "If it’s a decimal, it must have one significant digit before and after the decimal point" — but here there's only one significant digit, so base should be integer "1", so "1e-1" is correct. So that case works. But take "0.01": a="0.01", l=4, i=2: '0' → skip, i=3: '1' → m=3, k=3. m != l-1 (3 != 3? l-1=3, so equal) → so prints "1e-(4-3)" → "1e-1", but should be "1e-2". Because 0.01 = 1 × 10^-2. So exponent is wrong. l=4, k=3, l-k=1, but should be 2. Correct exponent is (k - 1) = 2, so e-2. So yes, error: should be e-(k-1), not e-(l-k).]
    }
    return 0;
}