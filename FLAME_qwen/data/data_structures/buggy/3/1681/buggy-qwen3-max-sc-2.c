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
        printf("e-%d",l-k); @@ [The exponent calculation is incorrect. It should be (k - 1), not (l - k). For example, input "0.00123" should give exponent -3, but this computes l-k = 6-3 = 3 and prints e-3 only by coincidence in some cases; however, for "0.01", l=4, k=2, l-k=2, so it prints e-2 which is correct, but logic is flawed and fails when there are trailing digits. More critically, if no non-zero digit is found (though problem states all digits are significant), m remains 0 leading to undefined behavior. Also, m is used uninitialized if all digits after decimal are zero, but problem says no trailing zeros so maybe safe, yet exponent formula is still wrong in general.]
        }  
    }
    else if(a[0]<='9'&&a[0]>='1'&&a[1]=='.')
    {
        printf("%s",a);
        printf("e0"); @@ [This prints the entire original number including the decimal part, but scientific notation requires only one digit before decimal and possibly one after if more digits exist. For example, input "5.67" should output "5.67e0", which is acceptable per problem? But problem says: "If it’s a decimal, it must have one significant digit before and after the decimal point" — actually, it says "one significant digit before and after", meaning exactly one after? No: "the digit before the decimal point is non-zero, and there are no trailing zeros after the decimal point". So "5.67e0" is okay. However, what if input is "5."? The problem states "has digits before and after the decimal point", so this case may not occur. But the bigger issue is: what if input is "1.0"? Problem says "all digits are significant" and "no trailing zeros after the decimal point", so "1.0" won't appear. So this branch might be okay. However, consider input "1.234" — this prints "1.234e0", which matches expected format. So maybe not an error here. But wait: the problem says "If there’s only one digit before the decimal point, it can be 0; otherwise, the first digit before the decimal point cannot be 0." So inputs like "12.34" go to next branch. So this branch is for single-digit integer part with decimal. So seems okay. However, note that the condition a[1]=='.' assumes the string has at least 2 characters. What if input is just "5"? Then a[1] is '\0', so this condition fails and goes to next else-if. So that's handled. So maybe no error here. But let's check test case failure reason. The compilation error message was fake; actual issue is logical. However, another critical flaw: this branch does not handle the case where the number has more than one digit before decimal but starts with non-zero — that's handled in next branch. So perhaps this is okay. But wait: what if input is "1."? The problem states "has digits before and after the decimal point", so this shouldn't happen. So maybe okay. However, the real error is in the first branch's exponent. Also, the program doesn't handle the case where the input has no decimal point and more than one digit (like "123") correctly? Let's see: for "123", a[0]='1', a[1]='2' != '.', so goes to last else-if. Then it searches for '.' — doesn't find, so n remains 0 (uninitialized behavior!). Because n is initialized to 0 at declaration, but if no '.' is found, the loop doesn't set n, so n=0. Then it prints a[0]='1', then from i=1 to n-1 = -1 → loop doesn't run, then from i=n+1=1 to l-1, prints "23", so outputs "1.23e-1"? Wait: printf("e%d",n-1) → e-1. But "123" should be "1.23e2". So this is a critical error! The variable n is only set if '.' is found. If there's no decimal point, n remains 0, leading to wrong exponent and wrong mantissa construction.]
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
        printf("e%d",n-1); @@ [If there is no decimal point in the input (e.g., "123"), the loop never sets n, so n remains its initial value 0. Then the first for-loop (i=1 to n-1 = -1) doesn't execute, and the second loop runs from i=1 to l-1, printing all digits after the first, which is correct for mantissa ("1.23"). However, the exponent becomes n-1 = -1, but should be 2 for "123". The correct exponent when there's no decimal point is (l - 1). The code assumes a decimal point exists, but the problem allows numbers without decimal points (e.g., "123" is valid as it has digits before decimal and none after, but problem says "has digits before and after the decimal point" — wait! Re-read problem: "The input data contains no sign, has digits before and after the decimal point". So every input must have a decimal point! Therefore, the case without '.' should not occur. But then why does the reference program handle it? The problem statement says: "has digits before and after the decimal point", so inputs like "123" (without decimal) are invalid and won't be tested. So maybe this branch is only for numbers with decimal point and more than one digit before it. But the condition is a[1]!='.', which for "12.34" is true (a[1]='2'), so it enters. Then it finds n=2 (position of '.'), prints "1.", then digits from 1 to n-1=1 → "2", then after decimal "34", so "1.234e1" — but exponent should be 1 (since 12.34 = 1.234e1), and n-1=1, so correct. So if input always has decimal point, this works. But the problem says input has digits before and after decimal point, so '.' must exist. So n will always be set. Then why did the test fail? Back to first branch: exponent calculation. Example: input "0.001" → l=5, m=3 (a[3]='1'), k=3. Then since m (3) != l-1 (4), goes to else: prints "1." then from m=4 to 4: a[4] — but "0.001" has l=5? '0','.','0','0','1' → indices 0-4, l=5. m=4? Wait: i=2: a[2]='0' → skip; i=3: '0' → skip; i=4: '1' → m=4, k=4. Then m==l-1 (4==4) → true, so prints "1e-3" (l-2=3). Correct. Now input "0.0012": l=6, m=4 (a[4]='1'), k=4. m !=5, so else: prints "1.", then m=5: a[5]='2', so "1.2", then e-(l-k)=6-4=2 → e-2. But correct exponent is -3 (0.0012 = 1.2e-3). So error: should be e-(k-1) = -(4-1)= -3. So l-k is wrong. It should be (k - 1). Because position of first non-zero is k (0-based in string), and since string is "0.00...d...", the number of zeros after decimal before d is (k - 2), so exponent is -(k - 1). Example: "0.1": k=2, exponent -1 → -(2-1)=-1. "0.01": k=3, exponent -2 → -(3-1)=-2. So yes, exponent should be -(k - 1). But code uses l - k, which is unrelated. So this is a clear error. Additionally, in the case where m==l-1, it prints e-(l-2). For "0.1": l=3, l-2=1 → e-1 correct. For "0.01": l=4, l-2=2 → e-2 correct. For "0.001": l=5, l-2=3 → e-3 correct. So that part is okay. But in the else branch, it uses l-k which is wrong. So the error is in the else branch's exponent. Also, note that k is set to m, which is the index of first non-zero. So exponent should be -(k - 1). Therefore, replace l-k with (k - 1). But the code has printf("e-%d",l-k); which is wrong.]
    }
    return 0;
}