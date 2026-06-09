#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char shu[105];

int main()
{
    fgets(shu,105,stdin);
    int n=strlen(shu);
    if(shu[0]!='0')
    {
        if(shu[1]=='.')
        {
            for(int i=0;i<n-1;i++)
            {
                printf("%c",shu[i]);
            }
            printf("e0");
        }
        else
        {
            int count=0,count_true=0;
            printf("%c",shu[0]);
            printf(".");
            for(int j=1;j<n-1;j++)
            {
                if(shu[j]!='.')
                {
                    printf("%c",shu[j]);
                    count++;
                }
                else
                {
                    count_true=count; @@ [This logic is flawed: 'count' counts digits before the decimal point after the first digit, but 'count_true' is only set when encountering '.', which may never happen if there's no '.' in input. Also, the exponent should be (position of '.') - 1, not based on counting digits this way.]
                }
            }
            printf("e%d",count_true); @@ [If there's no decimal point in the input (which shouldn't happen per problem, but still), count_true remains 0, leading to wrong exponent. Also, even if '.' exists, count_true equals number of digits between index 1 and '.', which is not the correct exponent.]
        }
    }
    else
    {
        int sum=1,sum_true=0,piece=0;
        for(int j=2;j<n-1;j++)
        {
            if(shu[j]=='0')
            {
                sum++;
            }
            else
            {
                sum_true=sum;
                piece++;
                if(piece==1||piece>2)
                {
                    printf("%c",shu[j]);
                }
                else if(piece==2)
                {
                    printf(".%c",shu[j]);
                }
            }
        }
        printf("e-%d",sum_true); @@ [For input "0.9", piece becomes 1, so it prints '9', but then prints "e-1" correctly. However, the output becomes "9e-1" only if nothing else is printed before. But note: if the number has more than one non-zero digit after leading zeros, e.g., "0.00123", it would print "1.23", which is correct. BUT: for "0.9", the loop runs j from 2 to n-2 (since n includes newline). For "0.9\n", n=4, so j from 2 to 2 (inclusive). shu[2] = '9', which is not '0', so sum_true = sum = 1, piece=1 → prints '9'. Then prints "e-1". So why does the buggy output say "e-0"? Because in the actual run, maybe n is computed differently? Wait: fgets includes newline, so "0.9" becomes "0.9\n", n=4. Loop j=2 to n-2=2. So it should work. But the reported buggy output is "e-0", meaning nothing was printed before "e-0". That implies that the 'else' block didn't print any digit. Why? Because for "0.9", after '0.', the first non-zero is at j=2. But what if the input is "0.9" without newline? Unlikely. Alternatively, maybe the code never enters the 'else' block? No, shu[0]=='0', so it does. Another possibility: if the input is "0.9", then in the else block, j starts at 2. But what if n=3? Then n-1=2, so j<2 → loop doesn't run. Then nothing is printed, and sum_true remains 0 → prints "e-0". That's the bug! Because fgets reads "0.9\n" → n=4, but if input is just "0.9" (without newline, e.g., EOF after), then n=3. Then j from 2 to n-2 = 1 → loop condition j < n-1 → j < 2 → j=2 is not < 2 → loop skipped. So no digits printed, sum_true=0 → "e-0". The loop condition should be j < n-1 (to exclude newline), but if the input doesn't have newline, n is smaller. Better to remove newline first. Also, the logic for printing the mantissa is wrong: it should print the first non-zero digit, then if there are more digits, print '.' and the rest. But current code uses 'piece' counter in a confusing way. For "0.9", piece=1 → prints '9', which is correct. But if loop doesn't run due to n being small, nothing prints. So the core issue is not handling the string length properly and skipping the loop when it shouldn't. Also, the initial value of sum=1 is correct (for "0.0...x", exponent is -(number of zeros after decimal +1)), but if no non-zero digit is found, it breaks. However, problem states all digits are significant and there are digits after decimal, so there must be a non-zero. But the loop might not run if n is too small.]
    }
    return 0;
}